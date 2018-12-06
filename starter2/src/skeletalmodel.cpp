#include "skeletalmodel.h"
#include <cassert>

#include "starter2_util.h"
#include "vertexrecorder.h"

using namespace std;

SkeletalModel::SkeletalModel() {
    program = compileProgram(c_vertexshader, c_fragmentshader_light);
    if (!program) {
        printf("Cannot compile program\n");
        assert(false);
    }
}

SkeletalModel::~SkeletalModel() {
    // destructor will release memory when SkeletalModel is deleted
    while (m_joints.size()) {
        delete m_joints.back();
        m_joints.pop_back();
    }

    glDeleteProgram(program);
}

void SkeletalModel::load(const char *meshFile)
{
    // loadSkeleton(skeletonFile);

    m_mesh.load(meshFile);
    // m_mesh.loadAttachments(attachmentsFile, (int)m_joints.size());

    // computeBindWorldToJointTransforms();
    // updateCurrentJointToWorldTransforms();
}

void SkeletalModel::draw(const Camera& camera, bool skeletonVisible)
{
    // draw() gets called whenever a redraw is required
    // (after an update() occurs, when the camera moves, the window is resized, etc)

    m_matrixStack.clear();

    glUseProgram(program);
    updateShadingUniforms();
    // if (skeletonVisible)
    // {
    //     drawJoints(camera);
    //     drawSkeleton(camera);
    // }
    // else
    // {
        // Tell the mesh to draw itself.
        // Since we transform mesh vertices on the CPU,
        // There is no need to set a Model matrix as uniform


        camera.SetUniforms(program, Matrix4f::identity());
    Vector3f map = Vector3f(1, 1, 0);
    Vector3f v1 = .25 * (m_mesh.currentVertices[1] + m_mesh.currentVertices[4]) * map;
    Vector3f v2 = .25 * (m_mesh.currentVertices[1] + m_mesh.currentVertices[5]) * map;
    Vector3f v3 = .25 * (m_mesh.currentVertices[4] + m_mesh.currentVertices[5]) * map;
    m_mesh.currentVertices[1] = m_mesh.currentVertices[1] * map;
    m_mesh.currentVertices[4] = m_mesh.currentVertices[4] * map;
    m_mesh.currentVertices[5] = m_mesh.currentVertices[5] * map;
    Vector3f b1(v1[0], v2[0], v3[0]);
    Vector3f b2(v1[1], v2[1], v3[1]);
    Matrix3f A(1,    -.25, -.25,
               -.25, 1,    -.25,
               -.25, -.25,    1);
    Vector3f values1 = A.inverse()*b1;
    Vector3f values2 = A.inverse()*b2;
    m_mesh.currentVertices[0] = Vector3f(values1[0], values2[0], 0);
    m_mesh.currentVertices[2] = Vector3f(values1[1], values2[1], 0);
    m_mesh.currentVertices[3] = Vector3f(values1[2], values2[2], 0);
    for (Tuple3u face: m_mesh.faces) {
        for (int i=0; i<3; i++) {
            camera.SetUniforms(program, Matrix4f::identity());
            Matrix4f transform = Matrix4f::identity();
            Vector3f p1 = m_mesh.currentVertices[face[i]-1];
            Vector3f p2 = m_mesh.currentVertices[face[(i+1)%3]-1];
            transform = transform * Matrix4f::translation(p1[0], p1[1], p1[2]);
            float length = sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)+pow(p1[2]-p2[2],2));
            float plane_dist = sqrt(pow(p2[0]-p1[0],2)+pow(p2[2]-p1[2],2));
            transform = transform * Matrix4f::rotateY(atan2(p2[0]-p1[0], p2[2]-p1[2])) * Matrix4f::rotateX(atan2(plane_dist,p2[1]-p1[1]));
            camera.SetUniforms(program, transform);
            drawCylinder(6, .00125f, length);
        }
    }
    // m_mesh.draw();
    // }
    glUseProgram(0);
}

void SkeletalModel::updateShadingUniforms() {
    // UPDATE MATERIAL UNIFORMS
    GLfloat diffColor[] = { 0.4f, 0.4f, 0.4f, 1 };
    GLfloat specColor[] = { 0.9f, 0.9f, 0.9f, 1 };
    GLfloat shininess[] = { 50.0f };
    int loc = glGetUniformLocation(program, "diffColor");
    glUniform4fv(loc, 1, diffColor);
    loc = glGetUniformLocation(program, "specColor");
    glUniform4fv(loc, 1, specColor);
    loc = glGetUniformLocation(program, "shininess");
    glUniform1f(loc, shininess[0]);

    // UPDATE LIGHT UNIFORMS
    GLfloat lightPos[] = { 3.0f, 3.0f, 5.0f, 1.0f };
    loc = glGetUniformLocation(program, "lightPos");
    glUniform4fv(loc, 1, lightPos);

    GLfloat lightDiff[] = { 120.0f, 120.0f, 120.0f, 1.0f };
    loc = glGetUniformLocation(program, "lightDiff");
    glUniform4fv(loc, 1, lightDiff);
}

void SkeletalModel::loadSkeleton(const char* filename)
{
    // Load the skeleton from file here.

    // set up the file for reading
    const int MAX_BUFFER_SIZE = 4096;
    char buffer[MAX_BUFFER_SIZE];
    ifstream skeleton;
    skeleton.open(filename);

    // hold information we parse from file
    Vector3f translation;
    int index;

    while (true) {
      skeleton.getline(buffer, MAX_BUFFER_SIZE);
      stringstream line(buffer);
      // check if we are at the end of the file
      if (!(line >> translation[0])) break;

      line >> translation[1] >> translation[2] >> index;

      Joint *joint = new Joint;
      joint->transform = Matrix4f::translation(translation);

      if (index == -1) {
        m_rootJoint = joint;
      } else {
        m_joints[index]->children.push_back(joint);
      }
      m_joints.push_back(joint);
    }

    // safely close file
    skeleton.close();
}

void SkeletalModel::drawJoints(const Camera& camera)
{
    // Draw a sphere at each joint.
    jointDFS(camera, m_rootJoint);
}

void SkeletalModel::jointDFS(const Camera& camera, Joint *joint)
{
    // Using drawSphere( 0.025f, 12, 12 )
    // to draw a sphere of reasonable size.

    m_matrixStack.push(joint->transform);
    camera.SetUniforms(program, m_matrixStack.top());

    drawSphere(0.025f, 12, 12);

    // we don't need to keep track of visited nodes since
    // this is a DAG
    for (Joint *child: joint->children)
    {
      jointDFS(camera, child);
    }

    m_matrixStack.pop();
}

void SkeletalModel::drawSkeleton(const Camera& camera)
{
    // Draw cylinders between the joints. You will need to add a recursive
    // helper function to traverse the joint hierarchy.
    //
    // We recommend using drawCylinder(6, 0.02f, <height>);
    // to draw a cylinder of reasonable diameter.

    // you can use the stack with push/pop like this
    // m_matrixStack.push(Matrix4f::translation(+0.6f, +0.5f, -0.5f))
    // camera.SetUniforms(program, m_matrixStack.top());
    // drawCylinder(6, 0.02f, 0.2f);
    // callChildFunction();
    // m_matrixStack.pop()
    boneDFS(camera, m_rootJoint);
}

void SkeletalModel::boneDFS(const Camera& camera, Joint *joint)
{
    m_matrixStack.push(joint->transform);

    // we don't need to keep track of visited nodes since
    // this is a DAG
    for (Joint *child: joint->children)
    {
      camera.SetUniforms(program, m_matrixStack.top() * rotationMatrix(child));
      drawCylinder(6, .02f, findBoneLength(child));

      boneDFS(camera, child);
    }

    m_matrixStack.pop();
}

float SkeletalModel::findBoneLength(Joint *joint)
{
  // all the information about translation realtive to
  // parent which we can use to find distance
  Vector4f trans = joint->transform.getCol(3);
  return sqrt(pow(trans[0], 2) + pow(trans[1], 2) + pow(trans[2], 2));
}

Matrix4f SkeletalModel::rotationMatrix(Joint *joint)
{
    // figure out how much we need to rotate around the x axis
    // then around the y axis
    Vector4f trans = joint->transform.getCol(3);
    float xz_plane_distance = sqrt(pow(trans[2],2)+pow(trans[0],2));
    Matrix4f x_rotation = Matrix4f::rotateX(atan2(xz_plane_distance, trans[1]));
    Matrix4f y_rotation = Matrix4f::rotateY(atan2(trans[0],trans[2]));
    return y_rotation*x_rotation;
}

void SkeletalModel::setJointTransform(int jointIndex, float rX, float rY, float rZ)
{
    // Set the rotation part of the joint's transformation matrix based on the passed in Euler angles.
    Joint *joint = m_joints[jointIndex];
    Matrix4f current_transform = joint->transform;
    Matrix4f rotation = Matrix4f::rotateX(rX - joint->euler_angles[0]) *
                        Matrix4f::rotateY(rY - joint->euler_angles[1]) *
                        Matrix4f::rotateZ(rZ - joint->euler_angles[2]);
    vector<float> new_euler_angles = {rX, rY, rZ};
    joint->euler_angles = new_euler_angles;
    m_joints[jointIndex]->transform = current_transform * rotation;
}

void SkeletalModel::computeBindWorldToJointTransforms()
{
    // 2.3.1. Implement this method to compute a per-joint transform from
    // world-space to joint space in the BIND POSE.
    //
    // Note that this needs to be computed only once since there is only
    // a single bind pose.
    //
    // This method should update each joint's bindWorldToJointTransform.
    // You will need to add a recursive helper function to traverse the joint hierarchy.

    // we have to make our own stack because we multiply on the left rather
    // than the right when calculating the inverse
    vector<Matrix4f> inverses;
    bindDFS(m_rootJoint, inverses);
}

void SkeletalModel::bindDFS(Joint *joint, vector<Matrix4f> inverses)
{
    inverses.push_back(joint->transform.inverse());
    Matrix4f inverse_b = Matrix4f::identity();

    // calculate B^(-1)
    for (Matrix4f inverse: inverses)
    {
      // multiply on the left for inverse
      inverse_b = inverse * inverse_b;
    }

    joint->bindWorldToJointTransform = inverse_b;
    // we don't need to keep track of visited nodes since
    // this is a DAG
    for (Joint *child: joint->children)
    {
      bindDFS(child, inverses);
    }
}

void SkeletalModel::updateCurrentJointToWorldTransforms()
{
    // 2.3.2. Implement this method to compute a per-joint transform from
    // joint space to world space in the CURRENT POSE.
    //
    // The current pose is defined by the rotations you've applied to the
    // joints and hence needs to be *updated* every time the joint angles change.
    //
    // This method should update each joint's currentJointToWorldTransform.
    // You will need to add a recursive helper function to traverse the joint hierarchy.

    // pretty much same code as before but don't set camera
    updateDFS(m_rootJoint);
}

void SkeletalModel::updateDFS(Joint *joint)
{
    m_matrixStack.push(joint->transform);
    joint->currentJointToWorldTransform = m_matrixStack.top();

    // we don't need to keep track of visited nodes since
    // this is a DAG
    for (Joint *child: joint->children)
    {
      updateDFS(child);
    }

    m_matrixStack.pop();
}

void SkeletalModel::updateMesh()
{
    for (unsigned i=0; i<m_mesh.currentVertices.size(); i++) {
      Vector4f vertex(0,0,0,0);
      for (unsigned j=0; j<m_mesh.attachments[0].size(); j++)
      {
        // added to try to help with some performance
        if (m_mesh.attachments[i][j] != 0)
        {
          // in reading, it says we should assume the first joint has zero weight
          vertex = m_mesh.attachments[i][j] * m_joints[j+1]->currentJointToWorldTransform
                   * m_joints[j+1]->bindWorldToJointTransform * Vector4f(m_mesh.bindVertices[i], 1.0f) + vertex;
        }
      }
      m_mesh.currentVertices[i] = vertex.xyz();
    }
}

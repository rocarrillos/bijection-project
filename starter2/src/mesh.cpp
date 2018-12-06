#include "mesh.h"

#include "vertexrecorder.h"

using namespace std;

void Mesh::load( const char* filename )
{
	// 4.1. load() should populate bindVertices, currentVertices, and faces

	// Add your code here.
	const int MAX_BUFFER_SIZE = 4096;
	char buffer[MAX_BUFFER_SIZE];
	ifstream mesh;
	mesh.open(filename);

	while (true) {
		mesh.getline(buffer, MAX_BUFFER_SIZE);
		stringstream line(buffer);
		string geometricFeature;
		// check if we're at eof
		if (!(line >> geometricFeature)) break;

		if (geometricFeature == "v") {
			Vector3f coord;
			line >> coord[0] >> coord[1] >> coord[2];
			coord[0] = coord[0]/3+.5;
			coord[1] = coord[1]/3+.5;
			coord[2] = coord[2]/3+.5;
			bindVertices.push_back(coord);
		} else if (geometricFeature == "f") {
			unsigned face [3];
			line >> face[0] >> face[1] >> face[2];
			faces.push_back(face);
		}
	}

	// make a copy of the bind vertices as the current vertices
	currentVertices = bindVertices;
}

void Mesh::draw()
{
	// 4.2 Since these meshes don't have normals
	// be sure to generate a normal per triangle.
	// Notice that since we have per-triangle normals
	// rather than the analytical normals from
	// assignment 1, the appearance is "faceted".
	VertexRecorder mesh;
	for (Tuple3u face : faces)
	{
		Vector3f normal = calculateNormal(face);
		for (int i=0; i<3; i++)
		{
			Vector3f point = currentVertices[face[i]-1];
			mesh.record(point, normal);
		}
	}
	mesh.draw();
}

Vector3f Mesh::calculateNormal(Tuple3u face)
{
	Vector3f A = currentVertices[face[1]-1] - currentVertices[face[0]-1];
	Vector3f B = currentVertices[face[2]-1] - currentVertices[face[0]-1];
	return Vector3f::cross(A, B).normalized();
}

void Mesh::loadAttachments( const char* filename, int numJoints )
{
	// 4.3. Implement this method to load the per-vertex attachment weights
	// this method should update m_mesh.attachments
	const int MAX_BUFFER_SIZE = 4096;
	char buffer[MAX_BUFFER_SIZE];
	ifstream attach;
	attach.open(filename);

	while (true) {
		attach.getline(buffer, MAX_BUFFER_SIZE);
		stringstream line(buffer);
		vector<float> weights(numJoints-1);
		// check if we're at eof
		if (!(line >> weights[0])) break;
		for (int i=1; i<numJoints-1; i++)
		{
			line >> weights[i];
		}

		attachments.push_back(weights);
	}
}

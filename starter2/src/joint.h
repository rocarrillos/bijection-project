#ifndef JOINT_H
#define JOINT_H

#include <vector>
#include <vecmath.h>

struct Joint
{
	Matrix4f transform; // transform relative to its parent
	std::vector<Joint*> children; // list of children
	std::vector<float> euler_angles = {0.0f, 0.0f, 0.0f}; // used to hold euler angles
	// This matrix transforms world space into joint space for the initial ("bind") configuration of the joints.
	Matrix4f bindWorldToJointTransform;

	// This matrix maps joint space into world space for the *current* configuration of the joints.
	Matrix4f currentJointToWorldTransform;
};

#endif

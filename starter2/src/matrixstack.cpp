#include "matrixstack.h"

MatrixStack::MatrixStack()
{
	// Initialize the matrix stack with the identity matrix.
  m_matrices.push_back(Matrix4f::identity());
}

void MatrixStack::clear()
{
	// Revert to just containing the identity matrix.
  std::vector<Matrix4f> cleared_stack;
  cleared_stack.push_back(Matrix4f::identity());
  m_matrices = cleared_stack;
}

Matrix4f MatrixStack::top()
{
	// Return the top of the stack
	// return Matrix4f();

    return m_matrices.back();
}

void MatrixStack::push( const Matrix4f& m )
{
	// Push m onto the stack.
	// The new top should be "old * m", so that conceptually the new matrix
  // is applied first in right-to-left evaluation.
  Matrix4f newest_rotation = m_matrices.back() * m;
  m_matrices.push_back(newest_rotation);
}

void MatrixStack::pop()
{
	// Remove the top element from the stack
  m_matrices.pop_back();
}

#include "vec.h"

// Includes: DEBUG
#if defined _DEBUG
#include <stdio.h>
#endif


////////////////////
// CLASS: vec2f
////////////////////

// Setup & Initialization
vec2f::vec2f(float fX, float fY) :
	x(fX),
	y(fY)
{
}

vec2f::vec2f() : vec2f(0.0f, 0.0f)
{
}

// Maths
float vec2f::DotProduct(const vec2f v1, const vec2f v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float vec2f::Mag() const
{
	return (float) sqrt(x * x + y * y);
}

void vec2f::Normalize()
{
	float vec_norm = Mag();
	x /= vec_norm;
	y /= vec_norm;
}

vec2f operator-(const vec2f v)
{
	return (-1.0f * v);
}

// Add
vec2f operator+(const vec2f v1, const vec2f v2)
{
	return vec2f(v1.x + v2.x, v1.y + v2.y);
}
// Subtract
vec2f operator-(const vec2f v1, const vec2f v2)
{
	return vec2f(v1.x - v2.x, v1.y - v2.y);
}

vec2f operator*(const float fScalar, const vec2f vec)
{
	return vec2f(fScalar * vec.x, fScalar * vec.y);
}

// DEBUG
void vec2f::Print()
{
#if defined _DEBUG
	printf("(%f, %f)\n", x, y);
#endif
}


////////////////////
// CLASS: vec3f
////////////////////

// Setup & Initialization
vec3f::vec3f(float x /*= 0.0f*/, float y /*= 0.0f*/, float z /*= 0.0f*/) :
	m_vec{ x,y,z }
{
}

// Accessor
float vec3f::operator[](int idx) const
{
	return m_vec[idx];
}

float& vec3f::operator[](int idx)
{
	return m_vec[idx];
}

float vec3f::DotProduct(const vec3f v1, const vec3f v2)
{
	float val_dp = 0;
	for (int i = 0; i < 3; i++)
	{
		val_dp += (v1[i] * v2[i]);
	}
	return val_dp;
}

vec3f vec3f::CrossProduct(const vec3f v1, const vec3f v2)
{
	return vec3f
	(
		(v1.y() * v2.z()) - (v1.z() * v2.y()),
		(v1.z() * v2.x()) - (v1.x() * v2.z()),
		(v1.x() * v2.y()) - (v1.y() * v2.x())
	);
}

float vec3f::Mag() const
{
	return (float) sqrt(DotProduct(*this, *this));
}

void vec3f::Normalize()
{
	float vec_norm = Mag();	// :NOTE: Not verifying that our magnitude is > 0
	for (int i = 0; i < 3; i++)
	{
		m_vec[i] /= vec_norm;
	}
}

// Operator Overload: Negative
vec3f operator-(const vec3f v)
{
	return (-1.0f * v);
}

// Operator Overload: Add
vec3f operator+(const vec3f v1, const vec3f v2)
{
	return vec3f(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}
// Operator Overload: Subtract
vec3f operator-(const vec3f v1, const vec3f v2)
{
	return vec3f(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

// Operator Overload: Scalar Multiplication
vec3f operator*(const float fScalar, const vec3f vec)
{
	return vec3f(fScalar * vec.x(), fScalar * vec.y(), fScalar * vec.z());
}



// DEBUG
void vec3f::Print()
{
#if defined _DEBUG
	printf("(%f, %f, %f)\n", x(), y(), z());
#endif
}

////////////////////
// CLASS: vec4f
////////////////////

// Setup & Initialization
vec4f::vec4f(float x /*= 0.0f*/, float y /*= 0.0f*/, float z /*= 0.0f*/, float w /*=0.0f*/) :
	m_vec{x,y,z,w}
{
}

// Accessor
float vec4f::operator[](int idx) const
{
	return m_vec[idx];
}

float& vec4f::operator[](int idx)
{
	return m_vec[idx];
}

float vec4f::DotProduct(const vec4f v1, const vec4f v2)
{
	float val_dp = 0;
	for (int i = 0; i < 4; i++)
	{
		val_dp += (v1[i] * v2[i]);
	}
	return val_dp;
}

/*
vec3f vec3f::CrossProduct(const vec3f v1, const vec3f v2)
{
	return vec3f
		(
			(v1.y() * v2.z()) - (v1.z() * v2.y()),
			(v1.z() * v2.x()) - (v1.x() * v2.z()),
			(v1.x() * v2.y()) - (v1.y() * v2.x())
			);
}
*/

float vec4f::Mag() const
{
	return (float) sqrt(DotProduct(*this, *this));
}
void vec4f::Normalize()
{
	float vec_norm = Mag();
	for (int i = 0; i < 4; i++)
	{
		m_vec[i] /= vec_norm;
	}
}

// Operator Overload: Add
vec4f operator+(const vec4f v1, const vec4f v2)
{
	return vec4f(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z(), v1.w() + v2.w());
}
// Operator Overload: Subtract
vec4f operator-(const vec4f v1, const vec4f v2)
{
	return vec4f(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z(), v1.w() - v2.w());
}

// Operator Overload: Scalar Multiplication
vec4f operator*(const float fScalar, const vec4f vec)
{
	return vec4f(fScalar * vec.x(), fScalar * vec.y(), fScalar * vec.z(), fScalar * vec.w());
}

// DEBUG
void vec4f::Print()
{
#if defined _DEBUG
	printf("(%f, %f, %f, %f)\n", x(), y(), z(), w());
#endif
}
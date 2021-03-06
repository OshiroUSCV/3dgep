#include <stdio.h>

#include "vec.h"
#include "mat.h"
#include "quat.h"
#include "math3d.h"
#include "curve.h"


int main()
{
	printf("Hello World!\n");

	// Bezier tests
	printf("== BEZIER TESTS ==\n");
	vec2f p1(100, 500);
	vec2f p2(600, 200);
	vec2f p3(1000, 400);
	Lerp2D(p1, p2, 0.1f).Print();
	Bezier2DQuad bq(p1, p2, p3);

	bq.GetPoint(0.1f).Print();


	//vec4f v_1(3, 4);
	//v_1 = 3 * v_1;
	//vec4f v_2(4, -4);
	//vec4f v_3 = v_1 - v_2;

	//v_1.Print();
	//v_2.Print();
	//v_3.Print();
	

	// Result: -306
	mat33 mat_det33
	(
		vec3f(6,1,1),
		vec3f(4,-2,5),
		vec3f(2,8,7)
	);
	mat_det33.Print();
	printf("Determinant: %f\n", mat_det33.GetDeterminant());
	mat_det33.GetTranspose().Print();

	//
	printf("Shenanigans\n");

	// Result: 20
	mat44 mat_det44
	(
		vec4f(3, 0, 2, -1),
		vec4f(1, 2, 0, -2),
		vec4f(4, 0, 6, -3),
		vec4f(5, 0,  2, 0)
	);
	mat_det44.Print();

	float det = mat_det44.GetDeterminant();
	printf("Determinant: %f\n", det);

	mat44 mat_inv = ((1.0f / det) * (mat_det44.GetCofactorsMatrix().GetTranspose()));
	mat_inv.Print();
	mat44 result_identity = mat_det44 * mat_inv;
	result_identity.Print();

	// MULTIPLICATION TEST
	// RESULT:
	// 96	68	69	69
	// 24	56	18	52
	// 58	95	71	92
	// 90	107	81	142
	printf("\n\nMULTIPLICATION\n");
	mat44 mat_mult1
	(
		vec4f(5, 2, 6, 1),
		vec4f(0, 6, 2, 0),
		vec4f(3, 8, 1, 4),
		vec4f(1, 8, 5, 6)
	);

	mat44 mat_mult2
	(
		vec4f(7, 5, 8, 0),
		vec4f(1, 8, 2, 6),
		vec4f(9, 4, 3, 8),
		vec4f(5, 3, 7, 9)
	);
	mat44 result_mult = mat_mult1 * mat_mult2;
	result_mult.Print();

	///////////////////////////////////////
	// Test: Quaternions
	vec3f v_q1(2.0f, 0.0f, 0.0f);
	vec3f v_r1(0.0f, 0.0f, 1.0f);
	//vec3f v_qr1 = Quaternion::RotateVectorD(v_q1, v_r1, 45.0f);
	vec3f v_qr1 = Quaternion::RotateVectorR(v_q1, v_r1, M_PI / 4.0f);
	printf("Quat Result 1\n");
	v_qr1.Print();


	float sqrt22 = (float)(sqrt(2.0f) / 2.0f);
	vec3f v_q2(2.0f, 0.0f, 0.0f);
	vec3f v_r2(sqrt22, 0.0f, sqrt22);
	vec3f v_qr2 = Quaternion::RotateVectorD(v_q2, v_r2, 90.0f);
	printf("Quat Result 2\n");
	v_qr2.Print();


	/*
	mat44 mat_test
	(
		vec4f(1,2,3,4),
		vec4f(5,6,7,8),
		vec4f(20,30,40,50),
		vec4f(25,50,75,100)
	);
	mat33 mat_result = mat_test.GetMinor(2,1);

	mat_test.Print();
	mat_result.Print();
	*/

	///////////////////////////////////////
	// Test: Applied Math

	// Test 1: IsWithinRange2D()
	vec2f v_sentry(0.0f, 0.0f);
	vec2f v_dir(1.0f, 0.0f);
	vec2f v_target(0.5f, 0.5f);
	bool b_in_range = IsWithinRange2D(v_sentry, v_dir, 1.5f, M_PI_4, v_target);
	printf("IsWithinRange(): %s\n", (b_in_range ? "Yes" : "No"));


	///////////////////////////////////////
	while (true) {}
}
#include<iostream>
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

int main()
{
	vec4 v1(1, 2, 3, 4);
	vec4 v2(5, 6, 7, 8);
	vec4 v3(9, 10, 11, 12);
	vec4 v4(13, 14, 15, 16);
	mat4 m(v1, v2, v3, v4);
	mat4 a;

	a.transpose(m);
	return 0;
}
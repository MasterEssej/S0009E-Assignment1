#include<iostream>
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

int main()
{
	vec4 v1(5, 8, 12, 10);
	vec4 v2(5, 20, 7, 8);
	vec4 v3(9, 10, 3, 5);
	vec4 v4(13, 6, 15, 4);
	mat4 m(v1, v2, v3, v4);
	mat4 a;

	/*
	for (int i = 0; i < 4; i++)
	{
		a[i] = m.transpose()[i];
	}*/

	//m.transpose().print();

	//a = m.transpose();

	a = m.inverse(m);

	a.print();
	return 0;
}
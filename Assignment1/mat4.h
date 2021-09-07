#pragma once
#include <iostream>
#include <array>
#include "vec3.h"
#include "vec4.h"

class mat4
{
public:
	std::array<vec4, 4> m;

#pragma region constructors
	mat4()
		:m({ vec4{1, 0, 0, 0}, vec4{0, 1, 0, 0}, vec4{0, 0, 1, 0}, vec4{0, 0, 0, 1}}){}

	mat4(const vec4& r0, const vec4& r1, const vec4& r2, const vec4& r3)
		:m({ r0, r1, r2, r3 }){}

	mat4(const mat4& mn)
		:m({mn.m[0], mn.m[1], mn.m[2], mn.m[3]})
	{}
#pragma endregion

#pragma region operators
	mat4 operator=(const mat4& rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			m[i].x = rhs.m[i].x;
			m[i].y = rhs.m[i].y;
			m[i].z = rhs.m[i].z;
			m[i].w = rhs.m[i].w;
		}
		return *this;
	}
	mat4 operator*(const mat4& rhs)
	{
		mat4 tempm;
		for (int i = 0; i < 4; i++)
		{
			vec4 tpose;
			for (int j = 0; j < 4; j++)
			{
				vec4 tempv = rhs.m[j];
				tpose.setElement(j, tempv[i]);
			}
			for (int k = 0; k < 4; k++)
			{
				tempm[k].setElement(i, m[k].dot(m[k], tpose));
			}
		}

		/*
		mat4 temp;
		mat4 temp2;
		int i, j, k;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				temp[i][j] = 0;
				for (k = 0; k < 4; k++)
					temp2[k] = rhs.m[k];
					temp[i][j] += m[i][k] * temp2[k][j];
			}
		}
		return temp;*/
	}
	bool operator==(const mat4& rhs)
	{
		if (m[0] == rhs.m[0] && m[1] == rhs.m[1] && m[2] == rhs.m[2] && m[3] == rhs.m[3])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const mat4& rhs)
	{
		if (m[0] != rhs.m[0] || m[1] != rhs.m[1] || m[2] != rhs.m[2] || m[3] != rhs.m[3])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	vec4& operator[](const unsigned int i)
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
		}
		else
		{
			return m[i];
		}
	}
	const vec4& operator[](const unsigned int i)const
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
		}
		else
		{
			return m[i];
		}
	}
#pragma endregion

	float determinant()
	{
		float d =
			(m[0].x *
				(m[1].y * (m[2].z * m[3].w - m[2].w * m[3].z)
					- m[1].z * (m[2].y * m[3].w - m[2].w * m[3].y)
					+ m[1].w * (m[2].y * m[3].z - m[2].z * m[3].y))

				- m[0].y *
				(m[1].x * (m[2].z * m[3].w - m[2].w * m[3].z)
					- m[1].z * (m[2].x * m[3].w - m[2].w * m[3].x)
					+ m[1].w * (m[2].x * m[3].z - m[2].z * m[3].x))

				+ m[0].z *
				(m[1].x * (m[2].y * m[3].w - m[2].w * m[3].y)
					- m[1].y * (m[2].x * m[3].w - m[2].w * m[3].x)
					+ m[1].w * (m[2].x * m[3].y - m[2].y * m[3].x))

				- m[0].w *
				(m[1].x * (m[2].y * m[3].z - m[2].z * m[3].y)
					- m[1].y * (m[2].x * m[3].z - m[2].z * m[3].x)
					+ m[1].z * (m[2].x * m[3].y - m[2].y * m[3].x))

				);

		return d;
	}
	mat4 inverse(const mat4& tm)
	{

		mat4 c(m[0], m[1], m[2], m[3]);//(m[0], m[1], m[2], m[3]);
		float deter = c.determinant();
		if (deter == 0)
		{
			mat4 temp;
			return temp;
		}
		else
		{
			mat4 temp;
			temp[0].x = tm.m[1].y * (tm.m[2].z * tm.m[3].w - tm.m[2].w * tm.m[3].z) //a corrected
				- tm.m[1].z * (tm.m[2].y * tm.m[3].w - tm.m[2].w * tm.m[3].y)
				+ tm.m[1].w * (tm.m[2].y * tm.m[3].z - tm.m[2].z * tm.m[3].y);
			temp[0].y = tm.m[1].x * (tm.m[2].z * tm.m[3].w - tm.m[2].w * tm.m[3].z) //b corrected
				- tm.m[1].z * (tm.m[2].x * tm.m[3].w - tm.m[2].w * tm.m[3].x)
				+ tm.m[1].w * (tm.m[2].x * tm.m[3].z - tm.m[2].z * tm.m[3].x);
			temp[0].z = tm.m[1].x * (tm.m[2].y * tm.m[3].w - tm.m[2].w * tm.m[3].y) //c corrected
				- tm.m[1].y * (tm.m[2].x * tm.m[3].w - tm.m[2].w * tm.m[3].x)
				+ tm.m[1].w * (tm.m[2].x * tm.m[3].y - tm.m[2].y * tm.m[3].x);
			temp[0].w = tm.m[1].x * (tm.m[2].y * tm.m[3].z - tm.m[2].z * tm.m[3].y) //d corrected
				- tm.m[1].y * (tm.m[2].x * tm.m[3].z - tm.m[2].z * tm.m[3].x)
				+ tm.m[1].z * (tm.m[2].x * tm.m[3].y - tm.m[2].y * tm.m[3].x);
			temp[1].x = tm.m[0].y * (tm.m[2].z * tm.m[3].w - tm.m[2].w * tm.m[3].z) //e corrected
				- tm.m[0].z * (tm.m[2].y * tm.m[3].w - tm.m[2].w * tm.m[3].y)
				+ tm.m[0].w * (tm.m[2].y * tm.m[3].z - tm.m[2].z * tm.m[3].y);
			temp[1].y = tm.m[0].x * (tm.m[2].z * tm.m[3].w - tm.m[2].w * tm.m[3].z) //f corrected
				- tm.m[0].z * (tm.m[2].x * tm.m[3].w - tm.m[2].w * tm.m[3].x)
				+ tm.m[0].w * (tm.m[2].x * tm.m[3].z - tm.m[2].z * tm.m[3].x);
			temp[1].z = tm.m[0].x * (tm.m[2].y * tm.m[3].w * tm.m[2].w * tm.m[3].y) //g corrected
				- tm.m[0].y * (tm.m[2].x * tm.m[3].w - tm.m[2].w * tm.m[3].x)
				+ tm.m[0].w * (tm.m[2].x * tm.m[3].y - tm.m[2].y * tm.m[3].x);
			temp[1].w = tm.m[0].x * (tm.m[2].y * tm.m[3].z - tm.m[2].z * tm.m[3].y) //h corrected
				- tm.m[0].y * (tm.m[2].x * tm.m[3].z - tm.m[2].z * tm.m[3].x)
				+ tm.m[0].z * (tm.m[2].x * tm.m[3].y - tm.m[2].y * tm.m[3].x);
			temp[2].x = tm.m[0].y * (tm.m[1].z * tm.m[3].w - tm.m[1].w * tm.m[3].z) //i corrected
				- tm.m[0].z * (tm.m[1].y * tm.m[3].w - tm.m[1].w * tm.m[3].y)
				+ tm.m[0].w * (tm.m[1].y * tm.m[3].z - tm.m[1].z * tm.m[3].y);
			temp[2].y = tm.m[0].x * (tm.m[1].z * tm.m[3].w - tm.m[1].w * tm.m[3].z) //j
				- tm.m[0].z * (tm.m[1].x * tm.m[3].w - tm.m[1].w * tm.m[3].x)
				+ tm.m[0].w * (tm.m[1].x * tm.m[3].z - tm.m[1].z * tm.m[3].x);
			temp[2].z = tm.m[0].x * (tm.m[1].y * tm.m[3].w - tm.m[1].w * tm.m[3].y) //k
				- tm.m[0].y * (tm.m[1].x * tm.m[3].w - tm.m[1].w * tm.m[3].x)
				+ tm.m[0].w * (tm.m[1].x * tm.m[3].y - tm.m[1].y * tm.m[3].x);
			temp[2].w = tm.m[0].x * (tm.m[1].y * tm.m[3].z - tm.m[1].z * tm.m[3].y) //L
				- tm.m[0].y * (tm.m[1].x * tm.m[3].z - tm.m[1].z * tm.m[3].x)
				+ tm.m[0].z * (tm.m[1].x * tm.m[3].y - tm.m[1].y * tm.m[3].x);
			temp[3].x = tm.m[0].y * (tm.m[1].z * tm.m[2].w - tm.m[1].w * tm.m[2].z) //m
				- tm.m[0].z * (tm.m[1].y * tm.m[2].w - tm.m[1].w * tm.m[2].y)
				+ tm.m[0].w * (tm.m[1].y * tm.m[2].z - tm.m[1].z * tm.m[2].y);
			temp[3].y = tm.m[0].x * (tm.m[1].z * tm.m[2].w - tm.m[1].w * tm.m[2].z) //n
				- tm.m[0].z * (tm.m[1].x * tm.m[2].w - tm.m[1].w * tm.m[2].x)
				+ tm.m[0].w * (tm.m[1].x * tm.m[2].z - tm.m[1].z * tm.m[2].x);
			temp[3].z = tm.m[3].z * (tm.m[1].y * tm.m[2].w - tm.m[1].w * tm.m[2].y) //o
				- tm.m[0].y * (tm.m[1].x * tm.m[2].w - tm.m[1].w * tm.m[2].x)
				+ tm.m[0].w * (tm.m[1].x * tm.m[2].y - tm.m[1].y * tm.m[2].x);
			temp[3].w = tm.m[0].x * (tm.m[1].y * tm.m[2].z - tm.m[1].z * tm.m[2].y) //p corrected
				- tm.m[0].y * (tm.m[1].x * tm.m[2].z - tm.m[1].z * tm.m[2].x)
				+ tm.m[0].z * (tm.m[1].x * tm.m[2].y - tm.m[1].y * tm.m[2].x);

			//adjugate and then multiply the adjugate by (1/determinant) using original matrix
			temp = temp.transpose();
			for (int i = 0; i < 4; i++) {
				temp[i].x = (1 / deter) * temp[i].x;
				temp[i].y = (1 / deter) * temp[i].y;
				temp[i].z = (1 / deter) * temp[i].z;
				temp[i].w = (1 / deter) * temp[i].w;
			}
			return temp;
		}
		
	}
	mat4 transpose()
	{
		mat4 temp;
		vec4 tpose;
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				tpose.setElement(k, m[k].getElement(i));
			}
			temp[i] = tpose;
		}
		return temp;
	}
	mat4 rotationx(const float rad)
	{
		mat4 xrot;
		xrot.m[0].x = 1;
		xrot.m[1].y = cos(rad);
		xrot.m[1].z = sin(rad);
		xrot.m[2].y = -sin(rad);
		xrot.m[2].z = cos(rad);
		xrot.m[3].w = 1;
		return xrot;
	}
	mat4 rotationy(const float rad)
	{
		mat4 yrot;
		yrot.m[0].x = cos(rad);
		yrot.m[0].y = -sin(rad);
		yrot.m[1].z = 1;
		yrot.m[2].y = sin(rad);
		yrot.m[2].z = cos(rad);
		yrot.m[3].w = 1;
		return yrot;
	}
	mat4 rotationz(const float rad)
	{
		mat4 zrot;
		zrot.m[0].x = cos(rad);
		zrot.m[0].y = sin(rad);
		zrot.m[1].z = -sin(rad);
		zrot.m[2].y = cos(rad);
		zrot.m[2].z = 1;
		zrot.m[3].w = 1;
		return zrot;
	}
	mat4 rotationaxis(const vec3& v, const float rad)
	{

	}
	int print()
	{
		for (int i = 0; i < 4; i++)
		{
			m[i].print();
		}
		return 0;
	}

};
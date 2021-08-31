#pragma once
#include <iostream>

class vec4
{
public:
	float x;
	float y;
	float z;
	float w;

#pragma region constructor
	vec4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	vec4(float const xn, float const yn, float const zn, float const wn)
	{
		x = xn;
		y = yn;
		z = zn;
		w = wn;
	}

	vec4(const vec4& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}
#pragma endregion

#pragma region operators
	vec4 operator=(const vec4& rhs)
	{
		vec4 temp(rhs.x, rhs.y, rhs.z, rhs.w);
		return temp;
	}
	vec4 operator-()
	{
		vec4 temp(-x, -y, -z, -w);
		return temp;
	}
	vec4 operator+(const vec4& rhs)
	{
		vec4 temp((x + rhs.x), (y + rhs.y), (z + rhs.z), (w + rhs.w));
		return temp;
	}
	void operator+=(const vec4& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
	}
	vec4 operator-(const vec4& rhs)
	{
		vec4 temp((x - rhs.x), (y - rhs.y), (z - rhs.z), (w - rhs.w));
		return temp;
	}
	void operator-=(const vec4& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
	}
	void operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
	}
	vec4 operator*(const float scalar)
	{
		vec4 temp(x * scalar, y * scalar, z * scalar, w * scalar);
		return temp;
	}
	bool operator==(const vec4& rhs)
	{
		if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const vec4& rhs)
	{
		if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	float& operator[](const unsigned int i)
	{
		float no;

		if (i > 3)
		{
			no = -1;
			std::cerr << "Error\n";
		}
		else if (i == 0)
		{
			return x;
		}
		else if (i == 1)
		{
			return y;
		}
		else if (i == 2)
		{
			return z;
		}
		else if (i == 3)
		{
			return w;
		}
		return no;
	}
#pragma endregion

#pragma region functions
	float dot(const vec4& a, const vec4& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w*b.w;
	}
	float length(const vec4& v)
	{
		return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
	}
	vec4 normalize(const vec4& v)
	{
		vec4 temp(v.x / length(v), v.y / length(v), v.z / length(v), v.w/length(v));
		return temp;
	}
#pragma endregion

};
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
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return *this;
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
		if (x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	float operator[](const unsigned int i)
	{
		float no = -1;

		if (i > 3)
		{
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
	float setElement(const int i, const float v)
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
			return -1;
		}
		else if (i == 0)
		{
			x = v;
		}
		else if (i == 1)
		{
			y = v;
		}
		else if (i == 2)
		{
			z = v;
		}
		else if (i == 3)
		{
			w = v;
		}
		return 0;
	}
	float getElement(const int i)const
	{
		if (i > 3)
		{
			std::cerr << "Error\n";
			return -1;
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
		return 0;
	}
#pragma endregion

};
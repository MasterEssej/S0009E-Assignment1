#pragma once
#include <iostream>

class vec3
{
public:
	float x;
	float y;
	float z;

#pragma region constructor
	vec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	vec3(float const xn, float const yn, float const zn)
	{
		x = xn;
		y = yn;
		z = zn;

	}

	vec3(const vec3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
#pragma endregion

#pragma region operators
	vec3 operator=(const vec3& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}
	vec3 operator-()
	{
		vec3 temp(-x, -y, -z);
		return temp;
	}
	vec3 operator+(const vec3& rhs)
	{
		vec3 temp((x + rhs.x), (y + rhs.y), (z + rhs.z));
		return temp;
	}
	void operator+=(const vec3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}
	vec3 operator-(const vec3& rhs)
	{
		vec3 temp((x - rhs.x), (y - rhs.y), (z - rhs.z));
		return temp;
	}
	void operator-=(const vec3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}
	void operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}
	vec3 operator*(const float scalar)
	{
		vec3 temp(x * scalar, y * scalar, z * scalar);
		return temp;
	}
	bool operator==(const vec3& rhs)
	{
		if (x == rhs.x && y == rhs.y && z == rhs.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const vec3& rhs)
	{
		if (x == rhs.x && y == rhs.y && z == rhs.z)
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
		float no = -1;

		if (i > 2)
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
		return no;
	}
#pragma endregion

#pragma region functions
	float dot(const vec3& a, const vec3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	float length(const vec3& v)
	{
		return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	}
	vec3 cross(const vec3& a, const vec3& b)
	{
		vec3 temp;
		temp.x = a.y * b.z - a.z * a.y;
		temp.y = -(a.x * b.z - a.z * b.x);
		temp.z = a.x * b.y + a.y * b.x;
		return temp;
	}
	vec3 normalize(const vec3& v)
	{
		vec3 temp(v.x / length(v), v.y / length(v), v.z / length(v));
		return temp;
	}
	float setElement(const int i, const float v)
	{
		if (i > 2)
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
		return 0;
	}
	float getElement(const int i, const float v)
	{
		if (i > 2)
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
		return 0;
	}
	int print()const
	{
		std::cout << x << ", " << y << ", " << z << std::endl;
		return 0;
	}
#pragma endregion

};
#include "vec2.h"

Vec2::Vec2() { x = 0.0f, y = 0.0f; }

Vec2::Vec2(float a, float b) { x = a, y = b; }

Vec2 Vec2::operator+() const { return *this; }

Vec2 Vec2::operator-() const { return { -x, -y }; }

Vec2& Vec2::operator=(const Vec2& other)
{
	if (this != &other) {
		// 各メンバーの値を代入する
		x = other.x;
		y = other.y;
	}
	return *this;
}

Vec2 Vec2::operator+(const Vec2& other) const { return { x + other.x, y + other.y }; }

Vec2 Vec2::operator-(const Vec2& other) const { return { x - other.x, y - other.y }; }

Vec2 Vec2::operator*(const Vec2& other) const { return { x * other.x, y * other.y }; }

Vec2 Vec2::operator*(float s) const { return { x * s, y * s }; }

Vec2 Vec2::operator/(float s) const { return { x * 1 / s, y * 1 / s }; }

Vec2& Vec2::operator+=(const Vec2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vec2& Vec2::operator*=(float s) {
	x *= s;
	y *= s;
	return *this;
}

Vec2& Vec2::operator/=(float s) {
	x /= s;
	y /= s;
	return *this;
}

Vec2 operator*(float s, const Vec2& v) { return { s * v.x, s * v.y }; }
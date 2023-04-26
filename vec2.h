#pragma once
/// <summary>
/// 2次元ベクトル
/// </summary>
class Vec2 {
public:
	float x;
	float y;
public:
	Vec2();
	Vec2(float a, float b);
	/// <summary>
	/// 単項 +
	/// </summary>
	/// <returns>Vec2型</returns>
	Vec2 operator+() const;

	/// <summary>
	/// 単項 -
	/// </summary>
	/// <returns>Vec2型</returns>
	Vec2 operator-() const;

	/// <summary>
	/// 単項 =
	/// </summary>
	/// <returns>Vec2型</returns>
	Vec2& operator=(const Vec2& other);

	/// <summary>
	/// 2項 +
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2 operator+(const Vec2& other) const;

	/// <summary>
	/// 2項 -
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2 operator-(const Vec2& other) const;

	/// <summary>
	/// 2項 +
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2 operator*(const Vec2& other) const;

	/// <summary>
	/// 2項 *
	/// </summary>
	/// <param name="s"> s倍</param>
	/// <returns>Vec2型</returns>
	Vec2 operator*(float s) const;

	/// <summary>
	/// 2項 /
	/// </summary>
	/// <param name="s">  1 / s倍</param>
	/// <returns>Vec2型</returns>
	Vec2 operator/(float s) const;

	/// <summary>
	/// 複合代入演算 +=
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2& operator+=(const Vec2& other);

	/// <summary>
	/// 複合代入演算 -=
	/// </summary>
	/// <param name="other"> Vec2</param>
	/// <returns>Vec2型</returns>
	Vec2& operator-=(const Vec2& other);

	/// <summary>
	/// 複合代入演算 *=
	/// </summary>
	/// <param name="s"> s倍</param>
	/// <returns>Vec2型</returns>
	Vec2& operator*=(float s);

	/// <summary>
	/// 複合代入演算 /=
	/// </summary>
	/// <param name="s"> 1 / s倍</param>
	/// <returns>Vec2型</returns>
	Vec2& operator/=(float s);

	bool operator==(const Vec2& other) const {
		bool tmp=false;
		if (x == other.x && y == other.y) {
			return true;
		}
		return false;
	}
	
};



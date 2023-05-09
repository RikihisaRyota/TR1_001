#pragma once
#include "vec2.h"
class Mapchip;
class Player
{
public:
	Player();
	void Init();
	void Update(Mapchip* map, int& num);
	void Draw();
	enum State {
		Front,
		Back,
		Right,
		Left,
	}m_State;
private:
	Vec2 m_Pos;
	Vec2 m_Vec;
	Vec2 m_Front;
	int m_Vel;
	int m_Size;
	char m_Keys[256] = { 0 };
	char m_PreKeys[256] = { 0 };
	int m_FrontArrowTexture;
	int m_BackArrowTexture;
	int m_RightArrowTexture;
	int m_LeftArrowTexture;
private:
	void CheckMove(Mapchip* map, int& num);
	void SetFront(Vec2 vec);
	bool IsTriger(char* key, char* prekey);
public:
	//ゲッター
	Vec2 GetPos() { return m_Pos; };
	Vec2 GetFront() { return m_Front; };
	State GetState() const { return m_State; };
	//セッター
	void SetState();
public:
	// フレンドクラスとして宣言
	friend class Wall;
};


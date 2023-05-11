#pragma once
#include "vec2.h"
class Mapchip
{
public:
	static const int kMapChipWidth = 12;
	static const int kMapChipHeight = 12;
	static const int kChipSize = 20;

	int GetMapchip(Vec2 pos) { return m_Mapchip[static_cast<int>(pos.y)][static_cast<int>(pos.x)]; }
	Mapchip();
	void Update();
	void Draw();
private:
	int m_Mapchip[kMapChipHeight][kMapChipWidth];
	int m_Texture;
	char m_Keys[256] = { 0 };
	char m_PreKeys[256] = { 0 };
	bool m_DrawFlag = false;
private:
	void Init();
	bool IsPress(char* key, char* prekey);
};


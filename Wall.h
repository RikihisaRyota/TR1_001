#pragma once
#include "vec2.h"
class Player;
class Mapchip;
class Wall
{
public:
	Wall();
	void Init();
	void Draw();
	void Update(Player& player,Mapchip& map);
	void ChackDraw(Player& player, Mapchip& map);
	Vec2 ChengeMap(Vec2 pos);

	inline int getBox(const int index) const {
		return m_Box[index];
	}
	static const int kYMax = 3;
	static const int kXMax = 3;
	static const int kMax = kYMax * kXMax;

	enum Box {
		backLeft,
		backCenter,
		backRight,
		middleLeft,
		middleCenter,
		middleRight,
		frontLeft,
		frontCenter,
		frontRight,
	};
private:
	
	int m_Box[kMax];
	Vec2 m_Pos[kMax];
	void SetBox(int box, int num);
	void SetGrid(Player& player);
};


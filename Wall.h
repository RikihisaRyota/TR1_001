#pragma once
#include "vec2.h"
class Player;
class Mapchip;
class Wall
{
public:
	Wall();
	void Init();
	void Update(Player* player, Mapchip* map);
	void ChackDraw(Player* player, Mapchip* map);
	void Draw();
	Vec2 ChengeMap(Vec2 pos);

	inline int getBox(const int index) const {
		return m_Box[index];
	}
	static const int kYMax = 3;
	static const int kXMax = 3;
	static const int kMax = kYMax * kXMax;

	enum Box {
		backLeft,
		middleCenter,
		backRight,
		middleLeft,
		frontCenter,
		middleRight,
		frontLeft,
		player,
		frontRight,
	};
private:
	
	int m_Box[kMax];
	Vec2 m_Pos[kMax];
	void SetGrid(Player* player);
};


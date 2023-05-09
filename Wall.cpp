#include "Wall.h"
#include "Player.h"
#include "Mapchip.h"
#include <Novice.h>

Wall::Wall()
{
	Init();
}

void Wall::Init()
{
	for (size_t i = 0; i < kMax; i++) {
		m_Box[i] = { 0 };
		m_Pos[i] = { 0.0f,0.0f };
	}
}

void Wall::Update(Player* player, Mapchip* map)
{
	SetGrid(player);
	ChackDraw(player, map);
}

void Wall::ChackDraw(Player* player, Mapchip* map)
{
	for (size_t i = 0; i < kMax; i++) {
		if (m_Pos[i].x < -Mapchip::kChipSize || m_Pos[i].x > Mapchip::kChipSize * (Mapchip::kMapChipWidth - 1) || m_Pos[i].y < -Mapchip::kChipSize || m_Pos[i].y > Mapchip::kChipSize * (Mapchip::kMapChipHeight - 1)) {
			m_Box[i] = 2;
		}
		else
			if (map->GetMapchip((ChengeMap(m_Pos[i]))) == 0) {
				m_Box[i] = 0;
			}
			else if (map->GetMapchip((ChengeMap(m_Pos[i]))) == 3) {
				m_Box[i] = 3;
			}
			else {
				m_Box[i] = 1;
			}
	}
}

Vec2 Wall::ChengeMap(Vec2 pos)
{
	Vec2 tmp;
	tmp = pos / static_cast<float>(Mapchip::kChipSize);
	return tmp;
}

void Wall::SetGrid(Player* player)
{
	//どこ向いていても
	//{0,1,2},
	//{3,4,5},
	//{6,7,8},
	//に変換する
	switch (player->GetState())
	{
	case Player::State::Front:
		m_Pos[7] = player->GetPos();
		m_Pos[4] = player->GetPos() + player->GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player->GetPos() + player->GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x - Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[5] = { m_Pos[4].x - Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[8] = { m_Pos[7].x - Mapchip::kChipSize,m_Pos[7].y };

		m_Pos[0] = { m_Pos[1].x + Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[3] = { m_Pos[4].x + Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[6] = { m_Pos[7].x + Mapchip::kChipSize,m_Pos[7].y };
		break;
	case Player::State::Back:
		m_Pos[7] = player->GetPos();
		m_Pos[4] = player->GetPos() + player->GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player->GetPos() + player->GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x + Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[5] = { m_Pos[4].x + Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[8] = { m_Pos[7].x + Mapchip::kChipSize,m_Pos[7].y };

		m_Pos[0] = { m_Pos[1].x - Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[3] = { m_Pos[4].x - Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[6] = { m_Pos[7].x - Mapchip::kChipSize,m_Pos[7].y };
		break;
	case Player::State::Left:

		m_Pos[7] = player->GetPos();
		m_Pos[4] = player->GetPos() + player->GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player->GetPos() + player->GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x ,m_Pos[1].y - Mapchip::kChipSize };
		m_Pos[5] = { m_Pos[4].x ,m_Pos[4].y - Mapchip::kChipSize };
		m_Pos[8] = { m_Pos[7].x ,m_Pos[7].y - Mapchip::kChipSize };

		m_Pos[0] = { m_Pos[1].x ,m_Pos[1].y + Mapchip::kChipSize };
		m_Pos[3] = { m_Pos[4].x ,m_Pos[4].y + Mapchip::kChipSize };
		m_Pos[6] = { m_Pos[7].x ,m_Pos[7].y + Mapchip::kChipSize };
		break;
	case Player::State::Right:
		m_Pos[7] = player->GetPos();
		m_Pos[4] = player->GetPos() + player->GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player->GetPos() + player->GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x,m_Pos[1].y + Mapchip::kChipSize };
		m_Pos[5] = { m_Pos[4].x,m_Pos[4].y + Mapchip::kChipSize };
		m_Pos[8] = { m_Pos[7].x,m_Pos[7].y + Mapchip::kChipSize };

		m_Pos[0] = { m_Pos[1].x ,m_Pos[1].y - Mapchip::kChipSize };
		m_Pos[3] = { m_Pos[4].x ,m_Pos[4].y - Mapchip::kChipSize };
		m_Pos[6] = { m_Pos[7].x ,m_Pos[7].y - Mapchip::kChipSize };
		break;
	default:
		break;
	}
}



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

void Wall::Draw()
{
	for (size_t i = 0; i < kMax; i++) {
		if (m_Box[i] == 0) {
			Novice::DrawEllipse(static_cast<int>(m_Pos[i].x + Mapchip::kChipSize / 2), static_cast<int>(m_Pos[i].y + Mapchip::kChipSize / 2), Mapchip::kChipSize / 2, Mapchip::kChipSize / 2, 0.0f, WHITE, kFillModeSolid);
		}
		else if (m_Box[i] == 1) {
			Novice::DrawEllipse(static_cast<int>(m_Pos[i].x + Mapchip::kChipSize / 2), static_cast<int>(m_Pos[i].y + Mapchip::kChipSize / 2), Mapchip::kChipSize / 2, Mapchip::kChipSize / 2, 0.0f, RED, kFillModeWireFrame);
		}
		else {
			Novice::DrawEllipse(static_cast<int>(m_Pos[i].x + Mapchip::kChipSize / 2), static_cast<int>(m_Pos[i].y + Mapchip::kChipSize / 2), Mapchip::kChipSize / 2, Mapchip::kChipSize / 2, 0.0f, BLUE, kFillModeWireFrame);
		}
	}
}

void Wall::Update(Player& player, Mapchip& map)
{
	SetGrid(player);
	ChackDraw(player, map);
}

void Wall::ChackDraw(Player& player, Mapchip& map)
{
	for (size_t i = 0; i < kMax; i++) {
		if (m_Pos[i].x < -Mapchip::kChipSize || m_Pos[i].x > Mapchip::kChipSize * (Mapchip::kMapChipWidth - 1) || m_Pos[i].y < -Mapchip::kChipSize || m_Pos[i].y > Mapchip::kChipSize * (Mapchip::kMapChipHeight - 1)) {
			m_Box[i] = 2;
		}
		else
			if (map.GetMapchip((ChengeMap(m_Pos[i]))) == 0) {
				m_Box[i] = 0;
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

//void Wall::SetBox(int box, int num)
//{
//	switch (box)
//	{
//	case Wall::backLeft:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == backLeft) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::CenterBack:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == CenterBack) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::RightBack:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == RightBack) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::LeftMiddle:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == LeftMiddle) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::CenterMiddle:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == CenterMiddle) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::RightMiddle:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == RightMiddle) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::LeftFront:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == LeftFront) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::CenterFront:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == CenterFront) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	case Wall::RightFront:
//		for (size_t i = 0; i < kMax; i++) {
//			if (m_Box[i] == RightFront) {
//				m_Box[i] = num;
//			}
//		}
//		break;
//	default:
//		break;
//	}
//}

void Wall::SetGrid(Player& player)
{
	//どこ向いていても
	//{0,1,2},
	//{3,4,5},
	//{6,7,8},
	//に変換する
	switch (player.GetState())
	{
	case Player::State::Front:
		m_Pos[7] = player.GetPos();
		m_Pos[4] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x - Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[5] = { m_Pos[4].x - Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[8] = { m_Pos[7].x - Mapchip::kChipSize,m_Pos[7].y };

		m_Pos[0] = { m_Pos[1].x + Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[3] = { m_Pos[4].x + Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[6] = { m_Pos[7].x + Mapchip::kChipSize,m_Pos[7].y };
		////m_Pos
		////真ん中
		//m_Pos[1] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		//m_Pos[4] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;
		//m_Pos[7] = player.GetPos() + player.GetFront() * 3 * Mapchip::kChipSize;
		////左
		//m_Pos[2] = { m_Pos[1].x + Mapchip::kChipSize,m_Pos[1].y };
		//m_Pos[5] = { m_Pos[4].x + Mapchip::kChipSize,m_Pos[4].y };
		//m_Pos[8] = { m_Pos[7].x + Mapchip::kChipSize,m_Pos[7].y };
		////右
		//m_Pos[0] = { m_Pos[1].x - Mapchip::kChipSize,m_Pos[1].y };
		//m_Pos[3] = { m_Pos[4].x - Mapchip::kChipSize,m_Pos[4].y };
		//m_Pos[6] = { m_Pos[7].x - Mapchip::kChipSize,m_Pos[7].y };
		//
		//
		////m_Box
		////真ん中
		//m_Box[1][0]  = CenterFront;
		//m_Box[4][0]  = CenterMiddle;
		//m_Box[7][0]  = CenterBack;
		////左
		//m_Box[2][0] = LeftFront;
		//m_Box[5][0] = LeftMiddle;
		//m_Box[8][0] = LeftBack;
		////右
		//m_Box[0][0] = RightFront;
		//m_Box[3][0] = RightMiddle;
		//m_Box[6][0] = RightBack;

		break;
	case Player::State::Back:
		m_Pos[7] = player.GetPos();
		m_Pos[4] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x + Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[5] = { m_Pos[4].x + Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[8] = { m_Pos[7].x + Mapchip::kChipSize,m_Pos[7].y };

		m_Pos[0] = { m_Pos[1].x - Mapchip::kChipSize,m_Pos[1].y };
		m_Pos[3] = { m_Pos[4].x - Mapchip::kChipSize,m_Pos[4].y };
		m_Pos[6] = { m_Pos[7].x - Mapchip::kChipSize,m_Pos[7].y };

		////m_Pos
		////真ん中
		//m_Pos[7] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		//m_Pos[4] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;
		//m_Pos[1] = player.GetPos() + player.GetFront() * 3 * Mapchip::kChipSize;
		////左
		//m_Pos[6] = { m_Pos[7].x - Mapchip::kChipSize,m_Pos[7].y };
		//m_Pos[3] = { m_Pos[4].x - Mapchip::kChipSize,m_Pos[4].y };
		//m_Pos[0] = { m_Pos[1].x - Mapchip::kChipSize,m_Pos[1].y };
		////右
		//m_Pos[8] = { m_Pos[7].x + Mapchip::kChipSize,m_Pos[7].y };
		//m_Pos[5] = { m_Pos[4].x + Mapchip::kChipSize,m_Pos[4].y };
		//m_Pos[2] = { m_Pos[1].x + Mapchip::kChipSize,m_Pos[1].y };
		//
		////m_Box
		////真ん中
		//m_Box[7][0] = CenterFront;
		//m_Box[4][0] = CenterMiddle;
		//m_Box[1][0] = CenterBack;
		////左
		//m_Box[8][0] = LeftFront;
		//m_Box[5][0] = LeftMiddle;
		//m_Box[2][0] = LeftBack;
		////右
		//m_Box[6][0] = RightFront;
		//m_Box[3][0] = RightMiddle;
		//m_Box[0][0] = RightBack;
		break;
	case Player::State::Left:

		m_Pos[7] = player.GetPos();
		m_Pos[4] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x ,m_Pos[1].y - Mapchip::kChipSize };
		m_Pos[5] = { m_Pos[4].x ,m_Pos[4].y - Mapchip::kChipSize };
		m_Pos[8] = { m_Pos[7].x ,m_Pos[7].y - Mapchip::kChipSize };

		m_Pos[0] = { m_Pos[1].x ,m_Pos[1].y + Mapchip::kChipSize };
		m_Pos[3] = { m_Pos[4].x ,m_Pos[4].y + Mapchip::kChipSize };
		m_Pos[6] = { m_Pos[7].x ,m_Pos[7].y + Mapchip::kChipSize };
		////真ん中
		//m_Pos[5] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		//m_Pos[4] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;
		//m_Pos[3] = player.GetPos() + player.GetFront() * 3 * Mapchip::kChipSize;
		////左
		//m_Pos[8] = { m_Pos[5].x,m_Pos[5].y + Mapchip::kChipSize };
		//m_Pos[7] = { m_Pos[4].x,m_Pos[4].y + Mapchip::kChipSize };
		//m_Pos[6] = { m_Pos[3].x,m_Pos[3].y + Mapchip::kChipSize };
		////右
		//m_Pos[2] = { m_Pos[5].x ,m_Pos[5].y - Mapchip::kChipSize };
		//m_Pos[1] = { m_Pos[4].x ,m_Pos[4].y - Mapchip::kChipSize };
		//m_Pos[0] = { m_Pos[3].x ,m_Pos[3].y - Mapchip::kChipSize };
		//
		////m_Box
		////真ん中
		//m_Box[5][0] = CenterFront;
		//m_Box[4][0] = CenterMiddle;
		//m_Box[3][0] = CenterBack;
		////左
		//m_Box[8][0] = LeftFront;
		//m_Box[7][0] = LeftMiddle;
		//m_Box[6][0] = LeftBack;
		////右
		//m_Box[2][0] = RightFront;
		//m_Box[1][0] = RightMiddle;
		//m_Box[0][0] = RightBack;
		break;
	case Player::State::Right:
		m_Pos[7] = player.GetPos();
		m_Pos[4] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		m_Pos[1] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;

		m_Pos[2] = { m_Pos[1].x,m_Pos[1].y + Mapchip::kChipSize };
		m_Pos[5] = { m_Pos[4].x,m_Pos[4].y + Mapchip::kChipSize };
		m_Pos[8] = { m_Pos[7].x,m_Pos[7].y + Mapchip::kChipSize };

		m_Pos[0] = { m_Pos[1].x ,m_Pos[1].y - Mapchip::kChipSize };
		m_Pos[3] = { m_Pos[4].x ,m_Pos[4].y - Mapchip::kChipSize };
		m_Pos[6] = { m_Pos[7].x ,m_Pos[7].y - Mapchip::kChipSize };
		////真ん中
		//m_Pos[3] = player.GetPos() + player.GetFront() * Mapchip::kChipSize;
		//m_Pos[5] = player.GetPos() + player.GetFront() * 3 * Mapchip::kChipSize;
		//m_Pos[4] = player.GetPos() + player.GetFront() * 2 * Mapchip::kChipSize;
		////左
		//m_Pos[0] = { m_Pos[3].x ,m_Pos[3].y + Mapchip::kChipSize };
		//m_Pos[1] = { m_Pos[5].x ,m_Pos[5].y + Mapchip::kChipSize };
		//m_Pos[2] = { m_Pos[4].x ,m_Pos[4].y + Mapchip::kChipSize };
		////右
		//m_Pos[6] = { m_Pos[3].x ,m_Pos[3].y - Mapchip::kChipSize };
		//m_Pos[7] = { m_Pos[5].x ,m_Pos[5].y - Mapchip::kChipSize };
		//m_Pos[8] = { m_Pos[4].x ,m_Pos[4].y - Mapchip::kChipSize };
		//
		////m_Box
		////真ん中
		//m_Box[3][0] = CenterFront;
		//m_Box[4][0] = CenterMiddle;
		//m_Box[5][0] = CenterBack;
		////左
		//m_Box[0][0] = LeftFront;
		//m_Box[1][0] = LeftMiddle;
		//m_Box[2][0] = LeftBack;
		////右
		//m_Box[6][0] = RightFront;
		//m_Box[7][0] = RightMiddle;
		//m_Box[8][0] = RightBack;
		break;
	default:
		break;
	}
	/*Novice::ScreenPrintf(400, 200, "player.Pos:%f,%f", player.GetPos().x, player.GetPos().y);
	Novice::ScreenPrintf(400, 220, "player.Pos:%f,%f", player.GetFront().x, player.GetFront().y);*/
}



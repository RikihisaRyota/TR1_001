#include "Player.h"
#include "Mapchip.h"
#include <Novice.h>

Player::Player() {
	Init();
}

void Player::Update(Mapchip* map, int& num)
{
	m_Vec = { 0.0f,0.0f };

	memcpy(m_PreKeys, m_Keys, 256);
	Novice::GetHitKeyStateAll(m_Keys);

	if (IsTriger(m_Keys, m_PreKeys)) {
		if (m_Keys[DIK_W]) {
			m_Vec = { 0.0f,-1.0f };
			SetState();
		}
		else if (m_Keys[DIK_S]) {
			m_Vec = { 0.0f,1.0f };
			SetState();
		}
		else if (m_Keys[DIK_A]) {
			m_Vec = { -1.0f,0.0f };
			SetState();
		}
		else if (m_Keys[DIK_D]) {
			m_Vec = { 1.0f,0.0f };
			SetState();
		}
		CheckMove(map, num);
	}
}

void Player::Draw()
{
	Novice::DrawQuad(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), 0, 0, Mapchip::kChipSize, Mapchip::kChipSize, 192, RED);
	switch (m_State)
	{
	case Player::Front:
		Novice::DrawQuad(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), 0, 0, Mapchip::kChipSize, Mapchip::kChipSize, m_FrontArrowTexture, RED);
		break;
	case Player::Back:
		Novice::DrawQuad(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), 0, 0, Mapchip::kChipSize, Mapchip::kChipSize, m_BackArrowTexture, RED);
		break;
	case Player::Right:
		Novice::DrawQuad(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), 0, 0, Mapchip::kChipSize, Mapchip::kChipSize, m_RightArrowTexture, RED);
		break;
	case Player::Left:
		Novice::DrawQuad(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), 0, 0, Mapchip::kChipSize, Mapchip::kChipSize, m_LeftArrowTexture, RED);
		break;
	default:
		break;
	}

}

void Player::SetState()
{
	if (m_Vec == Vec2(0.0f, 1.0f)) {
		m_Vec = { 0.0f,1.0f };
		SetFront(m_Vec);
		m_State = Front;
	}
	else if (m_Vec == Vec2(0.0f, -1.0f)) {
		m_Vec = { 0.0f,-1.0f };
		SetFront(m_Vec);
		m_State = Back;
	}
	else if (m_Vec == Vec2(1.0f, 0.0f)) {
		m_Vec = { 1.0f,0.0f };
		SetFront(m_Vec);
		m_State = Right;
	}
	else {
		m_Vec = { -1.0f,0.0f };
		SetFront(m_Vec);
		m_State = Left;
	}
}

void Player::Init()
{
	m_Pos = { Mapchip::kChipSize,Mapchip::kChipSize };
	m_Vec = { 0.0f,0.0f };
	m_Front = { 0.0f,1.0f };
	m_Vel = Mapchip::kChipSize;
	m_Size = Mapchip::kChipSize;
	m_State = Front;
	m_FrontArrowTexture = Novice::LoadTexture("./Resource./Arrow.png");
	m_BackArrowTexture = Novice::LoadTexture("./Resource./BackArrow.png");
	m_RightArrowTexture = Novice::LoadTexture("./Resource./RightArrow.png");
	m_LeftArrowTexture = Novice::LoadTexture("./Resource./LeftArrow.png");
}

void Player::CheckMove(Mapchip* map,int& num)
{
	Vec2 tmp = m_Pos;
	tmp += m_Vec * static_cast<float>(m_Vel);
	tmp.x = tmp.x  / Mapchip::kChipSize;
	tmp.y = tmp.y  / Mapchip::kChipSize;
	if (map->GetMapchip(tmp) == 0|| map->GetMapchip(tmp) == 3) {
		m_Pos = { tmp.x * Mapchip::kChipSize ,tmp.y * Mapchip::kChipSize };
	}
	if (map->GetMapchip(tmp) == 3) {
		num = 2;
	}
}

void Player::SetFront(Vec2 vec)
{
	m_Front = vec;
}

bool Player::IsTriger(char* key, char* prekey)
{
	if (prekey[DIK_A] == 0 && key[DIK_A] != 0) {
		return true;
	}
	
	if (prekey[DIK_D] == 0 && key[DIK_D] != 0) {
		return true;
	}
	
	if (prekey[DIK_W] == 0 && key[DIK_W] != 0) {
		return true;
	}
	
	if (prekey[DIK_S] == 0 && key[DIK_S] != 0) {
		return true;
	}

	return false;
		
}
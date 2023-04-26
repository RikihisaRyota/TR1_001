#include "Player.h"
#include "Mapchip.h"
#include <Novice.h>

Player::Player() {
	Init();
}

void Player::Update(Mapchip* map)
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
		CheckMove(map);
	}
}

void Player::Draw()
{
	Novice::DrawQuad(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y), static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.x + Mapchip::kChipSize - 1), static_cast<int>(m_Pos.y + Mapchip::kChipSize - 1), 0, 0, Mapchip::kChipSize, Mapchip::kChipSize, 192, RED);
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
}

void Player::CheckMove(Mapchip* map)
{
	Vec2 tmp = m_Pos;
	tmp += m_Vec * static_cast<float>(m_Vel);
	tmp.x = tmp.x  / Mapchip::kChipSize;
	tmp.y = tmp.y  / Mapchip::kChipSize;
	if (map->GetMapchip(tmp) == 0) {
		m_Pos = { tmp.x * Mapchip::kChipSize ,tmp.y * Mapchip::kChipSize };
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
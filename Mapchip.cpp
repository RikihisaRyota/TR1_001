#include "Mapchip.h"
#include <stdio.h>
#include <assert.h>
#include <Novice.h>
Mapchip::Mapchip()
{
	Init();
}

void Mapchip::Update()
{
	memcpy(m_PreKeys, m_Keys, 256);
	Novice::GetHitKeyStateAll(m_Keys);

	if (IsPress(m_Keys, m_PreKeys)) {
		m_DrawFlag = true;
	}
	else {
		m_DrawFlag = false;
	}
}

void Mapchip::Init()
{
	m_Texture = Novice::LoadTexture("./Resource/Texture.png");
	FILE* fp = NULL;
	fopen_s(&fp, "Resource/mapchip.csv", "rt");
	assert(fp != NULL);
	for (int y = 0; y < kMapChipWidth; y++) {
		for (int x = 0; x < kMapChipWidth; x++) {
			fscanf_s(fp, "%d,", &m_Mapchip[y][x]);
		}
	}
	fclose(fp);
}

bool Mapchip::IsPress(char* key, char* prekey)
{
	if (prekey[DIK_0] != 0 && key[DIK_0] != 0) {
		return true;
	}
	return false;
}


void Mapchip::Draw()
{
	Novice::ScreenPrintf(80, 260, "Map : 0");
	if (m_DrawFlag) {
		for (int y = 0; y < kMapChipWidth; y++) {
			for (int x = 0; x < kMapChipWidth; x++) {
				if (m_Mapchip[y][x] == 1) {
					Novice::DrawQuad(x * kChipSize, y * kChipSize, x * kChipSize + kChipSize - 1, y * kChipSize, x * kChipSize, y * kChipSize + kChipSize - 1, x * kChipSize + kChipSize - 1, y * kChipSize + kChipSize - 1, 0, 0, kChipSize, kChipSize, 192, 0xFFFFFF77);
				}
				else if (m_Mapchip[y][x] == 3) {
					Novice::DrawQuad(x * kChipSize, y * kChipSize, x * kChipSize + kChipSize - 1, y * kChipSize, x * kChipSize, y * kChipSize + kChipSize - 1, x * kChipSize + kChipSize - 1, y * kChipSize + kChipSize - 1, 0, 0, kChipSize, kChipSize, 192, 0xffff0077);
				}
			}
		}
	}

}
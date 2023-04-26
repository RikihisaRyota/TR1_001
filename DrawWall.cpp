#include "DrawWall.h"
#include <Novice.h>
#include "Matrix33 .h"
#include "Wall.h"

DrawWall::DrawWall()
{
	Init();
}

void DrawWall::Init()
{
	gridTop_ = 35.0f;
	center_ = { 1280.0f / 2.0f,(-720.0f / 2.0f) + gridTop_ };
	trapezoidCenter_ = { 1280.0f / 2.0f,(720.0f / 2.0f) };
	gridWidth_ = 672;
	gridHeight_ = 672;
	gridLeft_ = 1280.0f / 2.0f - static_cast<float>(gridWidth_ / 2.0f);
	grid_ = {
		center_,
		gridWidth_,
		gridHeight_,
	};
	frontLefttrapezoid_ = {
		{0.0f,0.0f},
		{5.0f,5.0f},
		{0.0f,32.0f},
		{5.0f,27.0f},
	};
	middleLefttrapezoid_ = {
		{0.0f,0.0f},
		{4.0f,4.0f},
		{0.0f,22.0f},
		{4.0f,18.0f}
	};
	backLefttrapezoid_ = {
		{0.0f,0.0f},
		{3.0f,3.0f},
		{0.0f,14.0f},
		{3.0f,11.0f},
	};

	backCentertrapezoid_ = {
		{0.0f,0.0f},
		{32.0f,0.0f},
		{0.0f,8.0f},
		{32.0f,8.0f}
	};

	middleCentertrapezoid_ = {
		{0.0f,0.0f},
		{32.0f,0.0f},
		{0.0f,14.0f},
		{32.0f,14.0f}
	};

	frontCentertrapezoid_ = {
		{0.0f,0.0f},
		{32.0f,0.0f},
		{0.0f,22.0f},
		{32.0f,22.0f},
	};

	backLeftWalltrapezoid_ = {
		{0.0f,0.0f},
		{9.0f,0.0f},
		{0.0f,14.0f},
		{9.0f,14.0f},
	};

	middleLeftWalltrapezoid_ = {
		{0.0f,0.0f},
		{5.0f,0.0f},
		{0.0f,22.0f},
		{5.0f,22.0f}
	};

	frontColor_ = 0xc0c0c0FF;
	middleColor_ = 0xa9a9a9FF;
	backColor_ = 0x808080FF;
	backGround_ = 0x696969FF;

	scale_ = 21.0f;
	rotateRight_ = static_cast<float>(M_PI);
	rotateLeft_ = 0.0f;
}

void DrawWall::Update(const Player& player, const Wall& wall)
{
	//左手前
	SetMatrix(frontLeftWorld_, frontLeftScale_, frontLeftRotate_, frontLeftTransform_, scale_, rotateLeft_, { grid_.LeftTop.x,grid_.LeftTop.y });
	
	//右手前
	SetMatrix(frontRightWorld_, frontRightScale_, frontRightRotate_, frontRightTransform_, scale_, rotateRight_, { grid_.RightTop.x,grid_.RightTop.y + gridHeight_ });


	//左真ん中
	Quad frontLeftTmp = frontLefttrapezoid_ * frontLeftWorld_;
	SetMatrix(middleLeftWorld_, middleLeftScale_, middleLeftRotate_, middleLeftTransform_, scale_, rotateLeft_, { frontLeftTmp.RightTop.x,frontLeftTmp.RightTop.y });
	//右真ん中
	Quad frontRightTmp = frontLefttrapezoid_ * frontRightWorld_;
	SetMatrix(middleRightWorld_, middleRightScale_, middleRightRotate_, middleRightTransform_, scale_, rotateRight_, { frontRightTmp.RightTop.x,frontRightTmp.RightTop.y });

	//左奥
	Quad middleLeftTmp = middleLefttrapezoid_ * middleLeftWorld_;
	SetMatrix(backLeftWorld_, backLeftScale_, backLeftRotate_, backLeftTransform_, scale_, rotateLeft_, { middleLeftTmp.RightTop.x,middleLeftTmp.RightTop.y });

	//右奥
	Quad middleRightTmp = middleLefttrapezoid_ * middleRightWorld_;
	SetMatrix(backRightWorld_, backRightScale_, backRightRotate_, backRightTransform_, scale_, rotateRight_, { middleRightTmp.RightTop.x,middleRightTmp.RightTop.y });

	//真ん中奥
	SetMatrix(backCenterWorld_, backCenterScale_, backCenterRotate_, backCenterTransform_, scale_, 0.0f, { trapezoidCenter_.x-336.0f, trapezoidCenter_.y - 97.0f });

	//真ん中真ん中
	SetMatrix(middleCenterWorld_, middleCenterScale_, middleCenterRotate_, middleCenterTransform_, scale_, 0.0f, { trapezoidCenter_.x -336.0f , trapezoidCenter_.y - 160.0f });

	//真ん中手前
	SetMatrix(frontCenterWorld_, frontCenterScale_, frontCenterRotate_, frontCenterTransform_, scale_, 0.0f, { trapezoidCenter_.x - 336.0f, trapezoidCenter_.y - 244.0f });

	//左奥壁
	SetMatrix(backLeftWallWorld_, backLeftWallScale_, backLeftWallRotate_, backLeftWallTransform_, scale_, rotateLeft_, { trapezoidCenter_.x - 336.0f, trapezoidCenter_.y-160.0f });

	//右奥壁
	SetMatrix(backRightWallWorld_, backRightWallScale_, backRightWallRotate_, backRightWallTransform_, scale_, rotateRight_, { trapezoidCenter_.x + 336.0f, trapezoidCenter_.y + 134.000031f });

	//左真ん中壁
	SetMatrix(middleLeftWallWorld_, middleLeftWallScale_, middleLeftWallRotate_, middleLeftWallTransform_, scale_, rotateLeft_, { trapezoidCenter_.x -336.0f, trapezoidCenter_.y-244.0f  });

	//左真ん中壁
	SetMatrix(middleRightWallWorld_, middleRightWallScale_, middleRightWallRotate_, middleRightWallTransform_, scale_, rotateRight_, { trapezoidCenter_.x+336.0f, trapezoidCenter_.y+218.0f });

	/*for (size_t i = 0; i < Wall::kMax; i++) {
		switch (i)
		{
		case Wall::backLeft:
			if (wall.getBox(i) == 1) {
				backLeftFlag = true;
			}
			else {
				backLeftFlag = false;
			}
			break;
		case Wall::backCenter:
			if (wall.getBox(i) == 1) {
				backCenterFlag = true;
			}
			else {
				backCenterFlag = false;
			}
			break;
		case Wall::backRight:
			if (wall.getBox(i) == 1) {
				backRightFlag = true;
			}
			else {
				backRightFlag = false;
			}
			break;
		case Wall::middleLeft:
			if (wall.getBox(i) == 1) {
				middleLeftFlag = true;
			}
			else {
				middleLeftFlag = false;
			}
			break;
		case Wall::middleCenter:
			if (wall.getBox(i) == 1) {
				middleCenterFlag = true;
			}
			else {
				middleCenterFlag = false;
			}
			break;
		case Wall::middleRight:
			if (wall.getBox(i) == 1) {
				middleRightFlag = true;
			}
			else {
				middleRightFlag = false;
			}
			break;
		case Wall::frontLeft:
			if (wall.getBox(i) == 1) {
				frontLeftFlag = true;
			}
			else {
				frontLeftFlag = false;
			}
			break;
		case Wall::frontCenter:
			if (wall.getBox(i) == 1) {
				frontCenterFlag = true;
			}
			else {
				frontCenterFlag = false;
			}
			break;
		case Wall::frontRight:
			if (wall.getBox(i) == 1) {
				frontRightFlag = true;
			}
			else {
				frontRightFlag = false;
			}
			break;
		}
	}*/

	//デバック
	memcpy(m_PreKeys, m_Keys, 256);
	Novice::GetHitKeyStateAll(m_Keys);

	if (IsTriger(m_Keys, m_PreKeys)) {
		if (m_Keys[DIK_1]) {
			if (!frontLeftFlag) {
				frontLeftFlag = true;
			}
			else {
				frontLeftFlag = false;
			}
		}
		else if (m_Keys[DIK_2]) {
			if (!middleLeftFlag) {
				middleLeftFlag = true;
			}
			else {
				middleLeftFlag = false;
			}
		}
		else if (m_Keys[DIK_3]) {
			if (!backLeftFlag) {
				backLeftFlag = true;
			}
			else {
				backLeftFlag = false;
			}
		}
		else if (m_Keys[DIK_4]) {
			if (!frontRightFlag) {
				frontRightFlag = true;
			}
			else {
				frontRightFlag = false;
			}
		}
		else if (m_Keys[DIK_5]) {
			if (!middleRightFlag) {
				middleRightFlag = true;
			}
			else {
				middleRightFlag = false;
			}
		}
		else if (m_Keys[DIK_6]) {
			if (!backRightFlag) {
				backRightFlag = true;
			}
			else {
				backRightFlag = false;
			}
		}
		else if (m_Keys[DIK_7]) {
			if (!backCenterFlag) {
				backCenterFlag = true;
			}
			else {
				backCenterFlag = false;
			}
		}
		else if (m_Keys[DIK_8]) {
			if (!middleCenterFlag) {
				middleCenterFlag = true;
			}
			else {
				middleCenterFlag = false;
			}
		}
		else if (m_Keys[DIK_9]) {
			if (!frontCenterFlag) {
				frontCenterFlag = true;
			}
			else {
				frontCenterFlag = false;
			}
		}
	}
}

void DrawWall::Draw()
{
	Novice::DrawBox(static_cast<int>(grid_.LeftTop.x), static_cast<int>(grid_.LeftTop.y), gridWidth_, gridHeight_, 0.0f, WHITE, kFillModeWireFrame);
	Novice::DrawBox(static_cast<int>(grid_.LeftTop.x), static_cast<int>(grid_.LeftTop.y), gridWidth_, gridHeight_, 0.0f, backGround_, kFillModeSolid);
	//Novice::DrawBox(static_cast<int>(grid_.LeftTop.x), static_cast<int>(grid_.LeftTop.y + gridHeight_ / 2.0f), gridWidth_, gridHeight_/2, 0.0f, WHITE, kFillModeSolid);
	Quad frontLeftTmp = frontLefttrapezoid_ * frontLeftWorld_;
	Quad frontRightTmp = frontLefttrapezoid_ * frontRightWorld_;
	Quad frontCenterTmp = frontCentertrapezoid_ * frontCenterWorld_;

	Quad middleLeftTmp = middleLefttrapezoid_ * middleLeftWorld_;
	Quad middleLeftWallTmp = middleLeftWalltrapezoid_ * middleLeftWallWorld_;
	Quad middleRightTmp = middleLefttrapezoid_ * middleRightWorld_;
	Quad middleRightWallTmp = middleLeftWalltrapezoid_ * middleRightWallWorld_;
	Quad middleCenterTmp = middleCentertrapezoid_ * middleCenterWorld_;

	Quad backLeftTmp = backLefttrapezoid_ * backLeftWorld_;
	Quad backLeftWallTmp = backLeftWalltrapezoid_ * backLeftWallWorld_;
	Quad backRightTmp = backLefttrapezoid_ * backRightWorld_;
	Quad backRightWallTmp = backLeftWalltrapezoid_ * backRightWallWorld_;
	Quad backCenterTmp = backCentertrapezoid_ * backCenterWorld_;

	if (backLeftFlag) {
		Novice::DrawQuad(backLeftTmp, backColor_);
		Novice::DrawQuad(backLeftWallTmp, backColor_);
	}
	if (backRightFlag) {
		Novice::DrawQuad(backRightTmp, backColor_);
		Novice::DrawQuad(backRightWallTmp, backColor_);
	}
	if (backCenterFlag) {
		Novice::DrawQuad(backCenterTmp, backColor_);
	}
	if (middleLeftFlag) {
		Novice::DrawQuad(middleLeftTmp, middleColor_);
		Novice::DrawQuad(middleLeftWallTmp, middleColor_);
	}
	if (middleRightFlag) {
		Novice::DrawQuad(middleRightTmp, middleColor_);
		Novice::DrawQuad(middleRightWallTmp, middleColor_);
	}
	if (middleCenterFlag) {
		Novice::DrawQuad(middleCenterTmp, middleColor_);
	}
	if (frontLeftFlag) {
		Novice::DrawQuad(frontLeftTmp, frontColor_);
	}
	if (frontRightFlag) {
		Novice::DrawQuad(frontRightTmp, frontColor_);
	}
	if (frontCenterFlag) {
		Novice::DrawQuad(frontCenterTmp, frontColor_);
	}
	



	//デバック
	//Novice::DrawLine(frontLeftTmp.RightTop.x, frontLeftTmp.RightTop.y, frontRightTmp.LeftBottom.x, frontRightTmp.RightBottom.y, BLACK);
	//Novice::DrawLine(frontCenterTmp.LeftTop.x, frontCenterTmp.LeftTop.y, grid_.LeftTop.x, frontCenterTmp.LeftTop.y, BLACK);
	//Novice::ScreenPrintf(500, 540, "X:%f", frontCenterTmp.LeftTop.x - grid_.LeftTop.x);
	//
	//Novice::DrawLine(frontCenterTmp.RightBottom.x, frontCenterTmp.RightBottom.y, frontRightTmp.RightTop.x, frontRightTmp.RightTop.y, BLACK);
	//Novice::ScreenPrintf(50, 500, "%f", frontCenterTmp.RightBottom.x);
	//Novice::ScreenPrintf(50, 520, "%f", frontRightTmp.RightTop.x);
	//Novice::ScreenPrintf(50, 540, "%f", frontCenterTmp.RightBottom.y);
	//Novice::ScreenPrintf(50, 560, "%f", frontRightTmp.RightTop.y);
	//
	//Novice::DrawLine(middleLeftWallTmp.RightTop.x, middleLeftWallTmp.RightTop.y,middleLeftTmp.LeftTop.x, middleLeftTmp.LeftTop.y, RED);
	//Novice::ScreenPrintf(500, 540, "X:%f", middleLeftWallTmp.RightTop.x - middleLeftTmp.LeftTop.x);
	//Novice::ScreenPrintf(500, 560, "Y:%f", middleLeftWallTmp.RightTop.y - middleLeftTmp.LeftTop.y);
	//
	//Novice::DrawLine(middleRightWallTmp.RightBottom.x, middleRightWallTmp.RightBottom.y, middleRightTmp.LeftBottom.x, middleRightTmp.LeftBottom.y, RED);
	//Novice::ScreenPrintf(500, 580, "X:%f", middleRightWallTmp.RightBottom.x - middleRightTmp.LeftBottom.x);
	//Novice::ScreenPrintf(500, 600, "Y:%f", middleRightWallTmp.RightBottom.y - middleRightTmp.LeftBottom.y);

	//Novice::DrawLine(backLeftWallTmp.RightTop.x, backLeftWallTmp.RightTop.y, backLeftTmp.LeftTop.x, backLeftTmp.LeftTop.y, BLUE);
	

	//下
	//Novice::DrawLine(backLeftTmp.RightBottom.x, backLeftTmp.RightBottom.y, grid_.LeftBottom.x, backLeftTmp.RightBottom.y, RED);
	//Novice::ScreenPrintf(500, 580, "RED:%f", backLeftTmp.RightBottom.x - grid_.LeftBottom.x);
	//
	//Novice::DrawLine(backLeftTmp.RightBottom.x, backLeftTmp.RightBottom.y, backLeftTmp.RightBottom.x, grid_.LeftTop.y + gridHeight_, BLUE);
	//Novice::ScreenPrintf(500, 600, "BLUE:%f", grid_.LeftTop.y + gridHeight_ - backLeftTmp.RightBottom.y);
	Novice::ScreenPrintf(1100, 200, "frontLeft  	:1");
	Novice::ScreenPrintf(1100, 220, "middleLeft 	:2");
	Novice::ScreenPrintf(1100, 240, "backLeft   	:3");
	Novice::ScreenPrintf(1100, 280, "frontRight	 :4");
	Novice::ScreenPrintf(1100, 300, "middleRight :5");
	Novice::ScreenPrintf(1100, 320, "backRight	  :6");
	Novice::ScreenPrintf(1100, 360, "backCenter	 :7");
	Novice::ScreenPrintf(1100, 380, "middleCenter:8");
	Novice::ScreenPrintf(1100, 400, "frontCenter :9");


	Novice::ScreenPrintf(1100, 200, "frontLeft  	:1");
	Novice::ScreenPrintf(1100, 220, "middleLeft 	:2");
	Novice::ScreenPrintf(1100, 240, "backLeft   	:3");
	Novice::ScreenPrintf(1100, 280, "frontRight	 :4");
	Novice::ScreenPrintf(1100, 300, "middleRight :5");
	Novice::ScreenPrintf(1100, 320, "backRight	  :6");
	Novice::ScreenPrintf(1100, 360, "backCenter	 :7");
	Novice::ScreenPrintf(1100, 380, "middleCenter:8");
	Novice::ScreenPrintf(1100, 400, "frontCenter :9");
}

void DrawWall::SetMatrix(Matrix33& world,Matrix33& matScale, Matrix33& matRotate, Matrix33& matTransform, const float scale, const float rotate, const Vec2 position)
{
	matScale = matScale.MakeScaling(scale);
	matRotate = matRotate.MakeRotation(rotate);
	matTransform = matTransform.MakeTranslation(position);
	world = matScale * matRotate * matTransform;
}

bool DrawWall::IsTriger(char* key, char* prekey)
{
	if (prekey[DIK_0] == 0 && key[DIK_0] != 0) {
		return true;
	}

	if (prekey[DIK_1] == 0 && key[DIK_1] != 0) {
		return true;
	}

	if (prekey[DIK_2] == 0 && key[DIK_2] != 0) {
		return true;
	}

	if (prekey[DIK_3] == 0 && key[DIK_3] != 0) {
		return true;
	}

	if (prekey[DIK_4] == 0 && key[DIK_4] != 0) {
		return true;
	}

	if (prekey[DIK_5] == 0 && key[DIK_5] != 0) {
		return true;
	}

	if (prekey[DIK_6] == 0 && key[DIK_6] != 0) {
		return true;
	}

	if (prekey[DIK_7] == 0 && key[DIK_7] != 0) {
		return true;
	}

	if (prekey[DIK_8] == 0 && key[DIK_8] != 0) {
		return true;
	}

	if (prekey[DIK_9] == 0 && key[DIK_9] != 0) {
		return true;
	}

	return false;

}
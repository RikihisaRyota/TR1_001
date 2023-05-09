#pragma once
#include "Quad.h"
#include "vec2.h"
class Player;
class Matrix33;
class Wall;
class DrawWall
{
public:
	DrawWall();

	void Init();

	void Update(const Player* player, const Wall* wall);

	void Draw();

private:
	void SetMatrix(Matrix33& world, Matrix33& matScale, Matrix33& matRotate, Matrix33& matTransform,const float scale,const float rotate,const Vec2 position);

	bool IsTriger(char* key, char* prekey);

	char m_Keys[256] = { 0 };
	char m_PreKeys[256] = { 0 };
	 
	Vec2 center_;
	Quad grid_;
	float gridTop_;
	float gridLeft_;
	int gridWidth_;
	int gridHeight_;
	float scale_;
	float rotateRight_;
	float rotateLeft_;

	Vec2 trapezoidCenter_;

	//左手前
	Quad frontLefttrapezoid_;
	Matrix33 frontLeftScale_;
	Matrix33 frontLeftRotate_;
	Matrix33 frontLeftTransform_;
	Matrix33 frontLeftWorld_;
	bool frontLeftFlag = false;

	//左真ん中
	Quad middleLefttrapezoid_;
	Matrix33 middleLeftScale_;
	Matrix33 middleLeftRotate_;
	Matrix33 middleLeftTransform_;
	Matrix33 middleLeftWorld_;
	bool middleLeftFlag = false;

	//左奥
	Quad backLefttrapezoid_;
	Matrix33 backLeftScale_;
	Matrix33 backLeftRotate_;
	Matrix33 backLeftTransform_;
	Matrix33 backLeftWorld_;
	bool backLeftFlag = false;

	//右手前
	Quad frontRighttrapezoid_;
	Matrix33 frontRightScale_;
	Matrix33 frontRightRotate_;
	Matrix33 frontRightTransform_;
	Matrix33 frontRightWorld_;
	bool frontRightFlag = false;

	//右真ん中
	Quad middleRighttrapezoid_;
	Matrix33 middleRightScale_;
	Matrix33 middleRightRotate_;
	Matrix33 middleRightTransform_;
	Matrix33 middleRightWorld_;
	bool middleRightFlag = false;

	//右奥
	Quad backRighttrapezoid_;
	Matrix33 backRightScale_;
	Matrix33 backRightRotate_;
	Matrix33 backRightTransform_;
	Matrix33 backRightWorld_;
	bool backRightFlag = false;

	//奥真ん中
	Quad backCentertrapezoid_;
	Matrix33 backCenterScale_;
	Matrix33 backCenterRotate_;
	Matrix33 backCenterTransform_;
	Matrix33 backCenterWorld_;
	bool backCenterFlag = false;
	
	//真ん中真ん中
	Quad middleCentertrapezoid_;
	Matrix33 middleCenterScale_;
	Matrix33 middleCenterRotate_;
	Matrix33 middleCenterTransform_;
	Matrix33 middleCenterWorld_;
	bool middleCenterFlag = false;

	//手前真ん中
	Quad frontCentertrapezoid_;
	Matrix33 frontCenterScale_;
	Matrix33 frontCenterRotate_;
	Matrix33 frontCenterTransform_;
	Matrix33 frontCenterWorld_;
	bool frontCenterFlag = false;

	//左奥壁
	Quad backLeftWalltrapezoid_;
	Matrix33  backLeftWallScale_;
	Matrix33  backLeftWallRotate_;
	Matrix33  backLeftWallTransform_;
	Matrix33  backLeftWallWorld_;

	//右奥壁
	Matrix33  backRightWallScale_;
	Matrix33  backRightWallRotate_;
	Matrix33  backRightWallTransform_;
	Matrix33  backRightWallWorld_;

	//左真ん中壁
	Quad middleLeftWalltrapezoid_;
	Matrix33  middleLeftWallScale_;
	Matrix33  middleLeftWallRotate_;
	Matrix33  middleLeftWallTransform_;
	Matrix33  middleLeftWallWorld_;

	//右真ん中壁
	Matrix33  middleRightWallScale_;
	Matrix33  middleRightWallRotate_;
	Matrix33  middleRightWallTransform_;
	Matrix33  middleRightWallWorld_;

	//天井

	//床
	unsigned int frontColor_;
	unsigned int frontCenterColor_;
	unsigned int middleColor_;
	unsigned int middleCenterColor_;
	unsigned int backColor_;
	unsigned int backCenterColor_;
	unsigned int backGround_;
	unsigned int frontBaseColor_;
	unsigned int middleBaseColor_;
	unsigned int goalBaseColor_;

};


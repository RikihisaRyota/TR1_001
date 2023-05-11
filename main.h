#include <Novice.h>
#include "Mapchip.h"
#include "Player.h"
#include "Wall.h"
#include "DrawWall.h"


//マップチップ
Mapchip* mapchip;

//プレイヤー
Player* player;

//Wall
Wall* wall;

//WallDraw
DrawWall* drawWall;

//GameScene
int gameScene = 1;
int nextGameScene = 1;
int sceneChangeColor = 0x00000000;
bool sceneChangeFlag = false;
bool sceneOnFlag = false;
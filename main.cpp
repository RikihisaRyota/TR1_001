#include "main.h"

const char kWindowTitle[] = "TR1";

void SnceneChange(int num) {
	if (!sceneOnFlag && sceneChangeColor < 255) {
		sceneChangeColor += 3;
	}
	else if (!sceneOnFlag) {
		gameScene = nextGameScene;
		sceneChangeColor = 0x000000FF;
		sceneOnFlag = true;
	}

	if (sceneChangeColor > 0 && sceneOnFlag) {
		sceneChangeColor -= 3;
	}
	else if (sceneOnFlag) {
		sceneChangeColor = 0x00000000;
		sceneOnFlag = false;
		sceneChangeFlag = false;
	}
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//Novice::SetWindowMode(kFullscreen);

	//マップチップ
	mapchip = new Mapchip;

	//プレイヤー
	player = new Player;

	//Wall
	wall = new Wall;

	//WallDraw
	drawWall = new DrawWall;

	int TITLE = Novice::LoadTexture("./Resource./TITLE.png");
	int ENDING = Novice::LoadTexture("./Resource./ENDING.png");

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (gameScene) {
			{
		case 0:
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
				player->Init();
				wall->Init();
				drawWall->Init();
				nextGameScene = 1;
				sceneChangeFlag = true;
			}
			break;
		case 1:
			mapchip->Update();
			player->Update(mapchip, nextGameScene);
			wall->Update(player, mapchip);
			drawWall->Update(player, wall);
			if (nextGameScene != 1) {
				nextGameScene = 2;
				sceneChangeFlag = true;
			}
			break;
		case 2:
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
				nextGameScene = 0;
				sceneChangeFlag = true;
			}
			break;
			}
		}
		if (sceneChangeFlag) {
			SnceneChange(nextGameScene);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (gameScene)
		{
		case 0:
			Novice::DrawQuad(0,0,1280,0,0,720,1280,720,0,0,1280,720,TITLE,WHITE);
			break;
		case 1:
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x333333FF, kFillModeSolid);
			mapchip->Draw();
			player->Draw();
			drawWall->Draw();
			break;
		case 2:
			Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, ENDING, WHITE);
			break;
		}

		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x00000000 + sceneChangeColor, kFillModeSolid);



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	//マップチップ
	delete mapchip;
	delete player;
	delete wall;
	delete drawWall;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
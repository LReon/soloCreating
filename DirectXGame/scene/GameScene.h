#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "SkyDome.h"

using namespace KamataEngine;

class GameScene {

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	Player* player_;
	Enemy* enemy_;
	SkyDome* skyDome_;

	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	uint32_t textureHandle_ = 0;

	// カメラ
	Camera* camera_;

};

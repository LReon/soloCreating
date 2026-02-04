#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "SkyDome.h"

using namespace KamataEngine;

/// <summary>
/// 各クラスをまとめて管理するクラス
/// </summary>
class GameScene {

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
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

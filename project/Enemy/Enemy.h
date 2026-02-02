#pragma once
#include <KamataEngine.h>
#include "EnemyBullet.h"
#include "Player.h"

using namespace KamataEngine;

class Player;

/// <summary>
/// 敵の動きを司るクラス
/// </summary>
class Enemy {


public:

	// 行動フェーズ
	enum class Phase {
		Circle,
		UpDown,
		Infinite
	};

	// 初期フェーズ
	Phase phase_ = Phase::Circle;

	// 初期化
	void Initialize(Camera* camera);
	void Fire();
	EnemyBullet* enemyBullet_ = nullptr;
	std::list<EnemyBullet*> enemyBullets_;

	// 発射間隔
	static const int kFireInterval = 30;

	// 更新
	void Update();
	// 描画
	void Draw();

	void CircleMove();
	float theta = 0.0f;
	float radius = 10.0f;
	float angleStep = 0.05f;
	float time = 0.0f;
	float centerX = 20.0f;
	float centerY = 0.0f;

	void UpDownMove();
	float moveTime = 0.0f;// 時間経過を記録する変数
	float amplitude = 10.0f;// 上下運動の振幅
	float frequency = 0.5f;// 周期

	void InfiniteMove();
	float infiniteTime = 0.0f;
	float a = 10.0f; // 軌道のサイズ

	int enemyFlag = 1;
		

	// キーボード入力
	Input* input_ = nullptr;

	int count = 1;

	// 衝突を検出したら呼び出されるコールバック
	void OnCollision();
	// 弾リストを取得
	/*const std::list<PlayerBullet*>& GetBullets() const {
		return enemyBullets_;;
	}*/

private:
	WorldTransform worldTransform;

	Model* model_ = nullptr;

	// カメラ
	Camera* camera_;

	// 発射タイマー
	int32_t fireTimer_ = 0;

};

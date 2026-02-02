#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;

/// <summary>
/// 敵の弾の動きを司るクラス
/// </summary>
class EnemyBullet {

public:
	// 初期化
	void Initialize(Camera* camera, const Vector3& position, const Vector3& velocity);
	// 更新
	void Update();
	// 描画
	void Draw();

	// 速度
	Vector3 velocity_;

	// 寿命
	static const int32_t kLifeTime = 60;
	// デスタイマー
	int32_t deathTimer_ = kLifeTime;
	// デスフラグ
	bool isDead_ = false;

	bool IsDead() const { return isDead_; }

	// 衝突を検出したら呼び出されるコールバック
	void OnCollision();

private:
	WorldTransform worldTransform;

	Model* model_ = nullptr;

	// カメラ
	Camera* camera_;

};

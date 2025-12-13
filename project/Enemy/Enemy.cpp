#include "Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cmath>

// 初期化
void Enemy::Initialize(Camera* camera) {
	model_ = Model::Create();
	input_ = Input::GetInstance();
	worldTransform.Initialize();
	worldTransform.scale_.x += 2.0f;
	worldTransform.scale_.y += 2.0f;
	worldTransform.scale_.z += 2.0f;
	worldTransform.translation_.x = 20.0f;
	worldTransform.UpdateMatrix();
	camera_ = camera;
	
}

// 更新
void Enemy::Update() { 

	// キー入力で移動パターンを切り替え
	if (input_->TriggerKey(DIK_SPACE)) {
		keyCount++;
	}
	if (keyCount == 1) {
		CircleMove();
	}
	else if (keyCount == 2) {
		UpDownMove();
	}
	else if (keyCount == 3) {
		InfiniteMove();
	} else if (keyCount > 3) {
		keyCount = 1;
	}

	worldTransform.UpdateMatrix();
}

// 描画
void Enemy::Draw() {
	model_->Draw(worldTransform, *camera_);
}

// 円運動
void Enemy::CircleMove() {

	theta += angleStep;

	if (theta > 2.0f * float(M_PI)) {
	    theta -= 2.0f * float(M_PI);
	}

	worldTransform.translation_.x = centerX + radius * cosf(theta);
	worldTransform.translation_.y = centerY + radius * sinf(theta);

}

// 上下運動
void Enemy::UpDownMove() {

	worldTransform.translation_.x = 20.0f; // X座標は固定

	// 時間を加算（フレームごとに少しずつ進める）
	moveTime += 1.0f / 60.0f;

	// サイン波でY座標を上下に変化させる
	worldTransform.translation_.y = amplitude * sinf(2.0f * static_cast<float>(M_PI) * frequency * moveTime);

}

// 無限大軌道運動
void Enemy::InfiniteMove() {

	// 初期化時の中心座標
	Vector3 center = {20.0f, 0.0f, 0.0f};
	
	infiniteTime += 0.05f; // 時間を進める（速度調整）

	a = 15.0f; // 軌道のサイズ

	// 無限大軌道（8の字）
	worldTransform.translation_.x = center.x + a * sin(infiniteTime);
	worldTransform.translation_.y = center.y + a * sin(infiniteTime) * cos(infiniteTime);
	worldTransform.translation_.z = 0.0f; // 平面上に固定

}



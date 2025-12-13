#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Enemy {

public:
	// 初期化
	void Initialize(Camera* camera);
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

	
		

	// キーボード入力
	Input* input_ = nullptr;

	int keyCount = 1;

private:
	WorldTransform worldTransform;

	Model* model_ = nullptr;

	// カメラ
	Camera* camera_;



};

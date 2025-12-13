#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Player {

public:
	// 初期化
	void Initialize(Camera* camera);
	// 更新
	void Update();
	// 描画
	void Draw();

	// キーボード入力
	Input* input_ = nullptr;

	

private:
	WorldTransform worldTransform;

	Model* model_ = nullptr;

	// カメラ
	Camera* camera_;
};

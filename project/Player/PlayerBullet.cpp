#include "PlayerBullet.h"
#define _USE_MATH_DEFINES
#include <math.h>
void PlayerBullet::Initialize(Camera* camera, const Vector3& position, const Vector3& velocity) {
	model_ = Model::Create();
	input_ = Input::GetInstance();
	worldTransform.Initialize();
	velocity_ = velocity;
	worldTransform.translation_ = position;
	worldTransform.UpdateMatrix();
	camera_ = camera;
}

void PlayerBullet::Update() { 
	worldTransform.translation_.x += velocity_.x;
	// 時間経過でデス
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
	worldTransform.UpdateMatrix();
}

void PlayerBullet::Draw() { 
	model_->Draw(worldTransform, *camera_);
}

void PlayerBullet::OnCollision() {
	isDead_ = true; 
}
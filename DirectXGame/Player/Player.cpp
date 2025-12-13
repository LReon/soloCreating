#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>



void Player::Initialize(Camera* camera) {
	model_ = Model::Create();
	input_ = Input::GetInstance();
	worldTransform.Initialize();
	camera_ = camera;
	

}

void Player::Update() {

	if (input_->PushKey(DIK_W)) {
		worldTransform.translation_.y += 1.0f;
	}
	if (input_->PushKey(DIK_S)) {
		worldTransform.translation_.y -= 1.0f;
	}
	if (input_->PushKey(DIK_A)) {
		worldTransform.translation_.x -= 1.0f;
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform.translation_.x += 1.0f;
	}


	worldTransform.UpdateMatrix();
}

void Player::Draw() { model_->Draw(worldTransform, *camera_); }

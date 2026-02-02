#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>



void Player::Initialize(Camera* camera) {
	model_ = Model::Create();
	input_ = Input::GetInstance();
	worldTransform.Initialize();
	camera_ = camera;
	

}

void Player::Attack() {
	

	

	if (input_->TriggerKey(DIK_SPACE)) {
		// 弾の速度
		const float kBulletSpeed = 1.0f;
		Vector3 velocity(kBulletSpeed, 0, 0);
		
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(camera_,worldTransform.translation_,velocity);
		playerBullets_.push_back(newBullet);
	}
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
	Attack();
	for (PlayerBullet* bullet : playerBullets_) {
		bullet->Update();
	}

	playerBullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

	worldTransform.UpdateMatrix();
}

void Player::Draw() { 
	model_->Draw(worldTransform, *camera_); 
	for (PlayerBullet* bullet : playerBullets_) {
		bullet->Draw();
	}
}

void Player::OnCollision() {}

Player::~Player() {

	delete playerBullet_; }

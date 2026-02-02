#include "GameScene.h"
// 初期化
void GameScene::Initialize() {

	camera_ = new Camera();
	camera_->Initialize();
	

	worldTransform_.Initialize();

	player_ = new Player();
	player_->Initialize(camera_);

	enemy_ = new Enemy();
	enemy_->Initialize(camera_);

	skyDome_ = new SkyDome();
	skyDome_->Initialize(camera_);

}

// 更新
void GameScene::Update() { 
	player_->Update();
	enemy_->Update();
	skyDome_->Update();
}

// 描画
void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Sprite::PreDraw(dxCommon->GetCommandList());
	Sprite::PostDraw();

	
	Model::PreDraw(dxCommon->GetCommandList());
	skyDome_->Draw();
	player_->Draw();
	enemy_->Draw();
	Model::PostDraw();
}

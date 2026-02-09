#include "TitleScene.h"

void TitleScene::Initialize() { 
	input_ = Input::GetInstance(); 
	/*textureHandle_ = TextureManager::Load("titleAndKey.png");
	
	sprite_ = Sprite::Create(textureHandle_, {});
	sprite_->SetPosition({0.0f, 0.0f});*/
}

void TitleScene::Update() {

	// タイトルの終了条件
	if (input_->TriggerKey(DIK_SPACE)) {
		finished_ = true;
	}
}

void TitleScene::Draw() {

	//sprite_->Draw(); 
}
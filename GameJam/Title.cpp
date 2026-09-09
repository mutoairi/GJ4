#include "Title.h"

using namespace KamataEngine;

Title::Title() {}

Title::~Title() {

    delete titleSprite_;
   
}

void Title::Initialize() {

    dxCommon_ = DirectXCommon::GetInstance();
    input_ = Input::GetInstance();

    isFinished_ = false;

    // ==============================
    // タイトル画像
    // ==============================

    titleTextureHandle_ =
        TextureManager::Load("Title.png");

    titleSprite_ = Sprite::Create(
        titleTextureHandle_,
        { 640.0f, 360.0f },
        { 1.0f, 1.0f, 1.0f, 1.0f },
        { 0.5f, 0.5f }
    );

    // 必要に応じて調整
    titleSprite_->SetSize({
        1280.0f,
        720.0f
        });


}

void Title::Update() {

    // SPACEを押したらタイトル終了
    if (input_->TriggerKey(DIK_SPACE)) {

        isFinished_ = true;
    }
}

void Title::Draw() {

    Sprite::PreDraw(
        dxCommon_->GetCommandList()
    );

    titleSprite_->Draw();
   
    Sprite::PostDraw();
}
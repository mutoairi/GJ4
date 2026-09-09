#include "ResultScene.h"

using namespace KamataEngine;

ResultScene::ResultScene() {}

ResultScene::~ResultScene() {

    delete score_;
    delete resultSprite_;
   
}

void ResultScene::Initialize(int finalScore) {

    dxCommon_ = DirectXCommon::GetInstance();
    input_ = Input::GetInstance();

    isFinished_ = false;

    // =========================
    // RESULT画像
    // =========================

    resultTextureHandle_ =
        TextureManager::Load("Clear.png");

    resultSprite_ = Sprite::Create(
        resultTextureHandle_,
        { 640.0f, 360.0f },
        { 1.0f, 1.0f, 1.0f, 1.0f },
        { 0.5f, 0.5f }
    );

    resultSprite_->SetSize({
        1280.0f,
        720.0f
        });

    // =========================
    // スコア
    // =========================

    score_ = new Score();
    score_->Initialize();
    score_->SetDigitSize({ 150.0f,130.0f});
    score_->SetPosition({ 250.0f, 350.0f });
    // GameSceneから受け取った最終スコア
    score_->AddScore(finalScore);

  
}

void ResultScene::Update() {

    // SPACEでタイトルへ戻る
    if (input_->TriggerKey(DIK_SPACE)) {
        isFinished_ = true;
    }
}

void ResultScene::Draw() {

    Sprite::PreDraw(
        dxCommon_->GetCommandList()
    );

    resultSprite_->Draw();

    score_->Draw();

   

    Sprite::PostDraw();
}
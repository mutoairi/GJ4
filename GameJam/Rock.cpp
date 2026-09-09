#include "Rock.h"

using namespace KamataEngine;

Rock::Rock() {}

Rock::~Rock() {
    delete sprite_;
}

void Rock::Initialize(Vector2 position) {

    position_ = position;

    // 岩画像
    // まだ無ければuvChecker.pngでもOK
    textureHandle_ =
        TextureManager::Load("rock.png");

    sprite_ = Sprite::Create(
        textureHandle_,
        position_,
        { 1.0f, 1.0f, 1.0f, 1.0f },
        { 0.5f, 0.5f }
    );

    sprite_->SetSize(size_);
}

void Rock::Update() {

    // 強制スクロール
    position_.x -= speed_;

    sprite_->SetPosition(position_);
}

void Rock::Draw() {

    sprite_->Draw();
}
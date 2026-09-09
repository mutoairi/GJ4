#include "Background.h"

using namespace KamataEngine;

Background::Background() {}

Background::~Background() {
    delete sprite1_;
    delete sprite2_;
}

void Background::Initialize()
{
    textureHandle_ =
        TextureManager::Load("background.png");

    position1_ = {
        0.0f,
        0.0f
    };

    position2_ = {
        1280.0f,
        0.0f
    };

    sprite1_ = Sprite::Create(
        textureHandle_,
        position1_
    );

    sprite2_ = Sprite::Create(
        textureHandle_,
        position2_
    );

    sprite1_->SetSize(size_);
    sprite2_->SetSize(size_);
}

void Background::Update()
{
    position1_.x -= speed_;
    position2_.x -= speed_;

    // 背景1が完全に左へ消えた
    if (position1_.x <= -1280.0f) {
        position1_.x = position2_.x + 1280.0f;
    }

    // 背景2が完全に左へ消えた
    if (position2_.x <= -1280.0f) {
        position2_.x = position1_.x + 1280.0f;
    }

    sprite1_->SetPosition(position1_);
    sprite2_->SetPosition(position2_);
}

void Background::Draw()
{
    sprite1_->Draw();
    sprite2_->Draw();
}
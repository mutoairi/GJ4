// Item.cpp
#include "Item.h"

using namespace KamataEngine;

Item::Item() {}

Item::~Item() {
    delete sprite_;
}

void Item::Initialize(Vector2 position) {

    position_ = position;

    textureHandle_ = TextureManager::Load("item.png");

    sprite_ = Sprite::Create(
        textureHandle_,
        position_
    );
}

void Item::Update() {

    if (isCollected_) {
        return;
    }

    // 強制スクロール
    position_.x -= speed_;

    sprite_->SetPosition(position_);
}

void Item::Draw() {

    if (isCollected_) {
        return;
    }

    sprite_->Draw();
}

bool Item::IsDead() const {

    return position_.x < -100.0f || isCollected_;
}
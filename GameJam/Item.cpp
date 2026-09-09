#include "Item.h"

using namespace KamataEngine;

Item::Item() {}

Item::~Item() {
    delete sprite_;
}

void Item::Initialize(Vector2 position) {

    position_ = position;

    isCollected_ = false;

    textureHandle_ =
        TextureManager::Load("item.png");

    sprite_ = Sprite::Create(
        textureHandle_,
        position_,
        { 1.0f, 1.0f, 1.0f, 1.0f },
        { 0.5f, 0.5f }
    );

    sprite_->SetSize(size_);
}

void Item::Update() {

    if (isCollected_) {
        return;
    }

    position_.x -= speed_;

    sprite_->SetPosition(position_);
}

void Item::Draw() {

    if (isCollected_) {
        return;
    }

    sprite_->Draw();
}
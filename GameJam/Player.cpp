#include "Player.h"

using namespace KamataEngine;

Player::Player() {}

Player::~Player() {
    delete sprite_;
}

void Player::Initialize(Input* input) {

    input_ = input;

    // 中央レーンから開始
    lane_ = 1;

    position_ = {
        200.0f,
        kLaneY[lane_]
    };

    textureHandle_ =
        TextureManager::Load("Player.png");

    sprite_ = Sprite::Create(
        textureHandle_,
        position_,
        { 1.0f, 1.0f, 1.0f, 1.0f },

        // Spriteの中心をpositionにする
        { 0.5f, 0.5f }
    );

    sprite_->SetSize(size_);
}

void Player::Update() {

    // 上
    if (input_->TriggerKey(DIK_W)) {

        if (lane_ > 0) {
            lane_--;
        }
    }

    // 下
    if (input_->TriggerKey(DIK_S)) {

        if (lane_ < 2) {
            lane_++;
        }
    }

    position_.y = kLaneY[lane_];

    sprite_->SetPosition(position_);
}

void Player::Draw() {

    sprite_->Draw();
}
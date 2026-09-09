#include "Player.h"
#include <algorithm>
#include <cassert>

using namespace KamataEngine;

void Player::Initialize(Input* input)
{
    input_ = input;

    lane_ = 1;

    position_ = {
        200.0f,
        kLaneY[lane_]
    };

    textureHandle_ = TextureManager::Load("uvChecker.png");

    sprite_ = Sprite::Create(
        textureHandle_,
        position_
    );
}

void Player::Update()
{
    if (input_->TriggerKey(DIK_W)) {
        lane_--;
    }

    if (input_->TriggerKey(DIK_S)) {
        lane_++;
    }

    // ★絶対に0～2から出さない
    lane_ = std::clamp(lane_, 0, 2);

    // ★デバッグ中に範囲外になったらここで止める
    assert(lane_ >= 0 && lane_ < 3);

    position_.y = kLaneY[lane_];

    sprite_->SetPosition(position_);
}

void Player::Draw()
{
    sprite_->Draw();
}
#include "Player.h"
using namespace KamataEngine;


void Player::Initialize(Input* input)
{
    input_ = input;

    position_ = {
       200.0f,
       kLaneY[lane_]
    };

    // プレイヤー画像読み込み
    textureHandle_ = TextureManager::Load("uvChecker.png");

    // Sprite生成
    sprite_ = Sprite::Create(
        textureHandle_,
        position_
    );
    
}

void Player::Update()
{
    
        if (input_->TriggerKey(DIK_W)) {
            if (lane_ > 0) {
                lane_--;
            }
        }

        if (input_->TriggerKey(DIK_S)) {
            if (lane_ < 2) {
                lane_++;
            }
        }

        position_.y = kLaneY[lane_];

        sprite_->SetPosition(position_);
    }

void Player::Draw()
{
    sprite_->Draw();
}

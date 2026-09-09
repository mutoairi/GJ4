#include "Rock.h"
#include "Lane.h"

#include <cstdlib>

using namespace KamataEngine;

Rock::Rock() {}

Rock::~Rock() {
    delete sprite_;
}

void Rock::Initialize() {

    textureHandle_ =
        TextureManager::Load("rock.png");

    // 最初の位置をランダムに決める
    Respawn();

    sprite_ =
        Sprite::Create(textureHandle_, position_);

    sprite_->SetSize(size_);
}

void Rock::Update() {

    // 左へ強制スクロール
    position_.x -= speed_;

    // 左端まで行ったら右端に戻す
    if (position_.x < -100.0f) {
        Respawn();
    }

    sprite_->SetPosition(position_);
}

void Rock::Draw() {

    sprite_->Draw();
}

void Rock::Respawn() {

    // 0～2をランダムに選択
    int lane = rand() % 3;

    // 右端から出現
    position_.x = 1300.0f;

    // ランダムなレーン
    position_.y = kLaneY[lane];
}
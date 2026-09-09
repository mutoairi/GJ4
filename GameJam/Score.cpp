#include "Score.h"

using namespace KamataEngine;

Score::Score() {}

Score::~Score() {

    for (Sprite* sprite : digitSprites_) {
        delete sprite;
    }
}

void Score::Initialize()
{
    //数字の読み込み
    numberTextures_[0] = TextureManager::Load("0.png");
    numberTextures_[1] = TextureManager::Load("1.png");
    numberTextures_[2] = TextureManager::Load("2.png");
    numberTextures_[3] = TextureManager::Load("3.png");
    numberTextures_[4] = TextureManager::Load("4.png");
    numberTextures_[5] = TextureManager::Load("5.png");
    numberTextures_[6] = TextureManager::Load("6.png");
    numberTextures_[7] = TextureManager::Load("7.png");
    numberTextures_[8] = TextureManager::Load("8.png");
    numberTextures_[9] = TextureManager::Load("9.png");

    score_ = 0;

    for (int i = 0; i < kDigitCount; i++) {

        Vector2 digitPosition = {
            position_.x + digitSize_.x * i,
            position_.y
        };

        digitSprites_[i] =
            Sprite::Create(
                numberTextures_[0],
                digitPosition
            );

        digitSprites_[i]->SetSize(digitSize_);
    }
}

void Score::AddScore(int value)
{
    score_ += value;
}

void Score::Draw()
{
    int value = score_;

    // 右端から数字を取り出す
    for (int i = kDigitCount - 1; i >= 0; i--) {

        int digit = value % 10;

        digitSprites_[i]->SetTextureHandle(
            numberTextures_[digit]
        );

        digitSprites_[i]->Draw();

        value /= 10;
    }
}
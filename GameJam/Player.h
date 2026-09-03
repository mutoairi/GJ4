#pragma once
#include<KamataEngine.h>

class Player {
public:
    void Initialize(KamataEngine::Input* input);
    void Update();
    void Draw();

    KamataEngine::Vector2 GetPosition() const {
        return position_;
    }

private:
    KamataEngine::Sprite* sprite_ = nullptr;
    KamataEngine::Input* input_ = nullptr;


    // プレイヤー画像
    uint32_t textureHandle_ = 0;

    int lane_ = 1;

    KamataEngine::Vector2 position_ = {
        50.0f,
        36.0f
    };

    const float kLaneY[3] = {
    5.0f,
    36.0f,
    72.0f
    };
};


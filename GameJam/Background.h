// Background.h
#pragma once
#include <KamataEngine.h>

class Background {
public:
    Background();
    ~Background();

    void Initialize();
    void Update();
    void Draw();

private:
    KamataEngine::Sprite* sprite1_ = nullptr;
    KamataEngine::Sprite* sprite2_ = nullptr;

    uint32_t textureHandle_ = 0;

    KamataEngine::Vector2 position1_{};
    KamataEngine::Vector2 position2_{};

    KamataEngine::Vector2 size_ = {
        1280.0f,
        720.0f
    };

    float speed_ = 3.0f;
};
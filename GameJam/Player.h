#pragma once
#include <KamataEngine.h>

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

    uint32_t textureHandle_ = 0;

    // 0 = 上
    // 1 = 中央
    // 2 = 下
    int lane_ = 1;

    KamataEngine::Vector2 position_ = {
        200.0f,
        36.0f
    };

    static constexpr float kLaneY[3] = {
        5.0f,
        36.0f,
        72.0f
    };
};
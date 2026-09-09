#pragma once
#include <KamataEngine.h>

class Player {
public:
    Player();
    ~Player();

    void Initialize(KamataEngine::Input* input);
    void Update();
    void Draw();

    // 位置取得
    KamataEngine::Vector2 GetPosition() const {
        return position_;
    }

    // 円当たり判定用
    float GetRadius() const {
        return radius_;
    }

private:
    KamataEngine::Sprite* sprite_ = nullptr;
    KamataEngine::Input* input_ = nullptr;

    uint32_t textureHandle_ = 0;

    // 現在のレーン
    // 0 = 上
    // 1 = 中央
    // 2 = 下
    int lane_ = 1;

    KamataEngine::Vector2 position_ = {
        200.0f,
        36.0f
    };

    KamataEngine::Vector2 size_ = {
        150.0f,
        150.0f
    };

    // 円当たり判定の半径
    float radius_ = 70.0f;

    // レーン位置
    static constexpr float kLaneY[3] = {
        50.0f,
        300.0f,
        600.0f
    };
};
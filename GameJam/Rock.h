#pragma once
#include <KamataEngine.h>

class Rock {
public:
    Rock();
    ~Rock();

    void Initialize(KamataEngine::Vector2 position);
    void Update();
    void Draw();

    // 位置
    KamataEngine::Vector2 GetPosition() const {
        return position_;
    }

    // 円当たり判定
    float GetRadius() const {
        return radius_;
    }

    // 画面外に出たか
    bool IsDead() const {
        return position_.x < -100.0f;
    }

private:
    KamataEngine::Sprite* sprite_ = nullptr;

    uint32_t textureHandle_ = 0;

    KamataEngine::Vector2 position_{};

    KamataEngine::Vector2 size_ = {
        150.0f,
        150.0f
    };

    // 当たり判定
    float radius_ = 70.0f;

    // スクロール速度
    float speed_ = 5.0f;
};
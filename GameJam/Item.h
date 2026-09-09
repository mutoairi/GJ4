#pragma once
#include <KamataEngine.h>

class Item {
public:
    Item();
    ~Item();

    void Initialize(KamataEngine::Vector2 position);
    void Update();
    void Draw();

    KamataEngine::Vector2 GetPosition() const {
        return position_;
    }

    float GetRadius() const {
        return radius_;
    }

    // 取得済みか
    bool IsCollected() const {
        return isCollected_;
    }

    // 取得する
    void Collect() {
        isCollected_ = true;
    }

    // 画面外
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

    float radius_ = 70.0f;

    float speed_ = 5.0f;

    bool isCollected_ = false;
};
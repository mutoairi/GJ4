// Item.h
#pragma once
#include <KamataEngine.h>

class Item {
public:
    Item();
    ~Item();

    void Initialize(KamataEngine::Vector2 position);
    void Update();
    void Draw();

    bool IsDead() const;
    bool IsCollected() const { return isCollected_; }

    void Collect() { isCollected_ = true; }

    KamataEngine::Vector2 GetPosition() const {
        return position_;
    }

private:
    KamataEngine::Sprite* sprite_ = nullptr;
    uint32_t textureHandle_ = 0;

    KamataEngine::Vector2 position_{};

    float speed_ = 5.0f;

    bool isCollected_ = false;
};
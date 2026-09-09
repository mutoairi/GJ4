#pragma once
#include <KamataEngine.h>

class Rock {
public:
    Rock();
    ~Rock();

    void Initialize();
    void Update();
    void Draw();

    KamataEngine::Vector2 GetPosition() const {
        return position_;
    }

    KamataEngine::Vector2 GetSize() const {
        return size_;
    }

private:
    void Respawn();

    KamataEngine::Sprite* sprite_ = nullptr;
    uint32_t textureHandle_ = 0;

    KamataEngine::Vector2 position_{};

    KamataEngine::Vector2 size_ = {
        32.0f,
        32.0f
    };

    float speed_ = 5.0f;
};
#pragma once
#include <KamataEngine.h>

class Title {
public:
    Title();
    ~Title();

    void Initialize();
    void Update();
    void Draw();

    // main.cppが遷移判定に使う
    bool IsFinished() const {
        return isFinished_;
    }

private:
    KamataEngine::DirectXCommon* dxCommon_ = nullptr;
    KamataEngine::Input* input_ = nullptr;

    // タイトル画像
    KamataEngine::Sprite* titleSprite_ = nullptr;
    uint32_t titleTextureHandle_ = 0;

    // シーン終了フラグ
    bool isFinished_ = false;
};
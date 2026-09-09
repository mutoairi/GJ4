#pragma once
#include <KamataEngine.h>
#include "Score.h"

class ResultScene {
public:
    ResultScene();
    ~ResultScene();

    void Initialize(int finalScore);
    void Update();
    void Draw();

    bool IsFinished() const {
        return isFinished_;
    }

private:
    KamataEngine::DirectXCommon* dxCommon_ = nullptr;
    KamataEngine::Input* input_ = nullptr;

    Score* score_ = nullptr;

    // RESULTの画像を出したいなら
    KamataEngine::Sprite* resultSprite_ = nullptr;
    uint32_t resultTextureHandle_ = 0;

    
    bool isFinished_ = false;
};
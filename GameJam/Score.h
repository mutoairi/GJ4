#pragma once
#include <KamataEngine.h>
#include <array>

class Score {
public:
    Score();
    ~Score();

    void Initialize();
    void Draw();

    // スコア加算
    void AddScore(int value);

    int GetScore() const {
        return score_;
    }

    void SetPosition(KamataEngine::Vector2 pos);

    void SetDigitSize(KamataEngine::Vector2 size);

private:
    int score_ = 0;

    // 0～9のテクスチャ
    std::array<uint32_t, 10> numberTextures_{};

    // 例えば6桁まで表示
    static constexpr int kDigitCount = 6;

    std::array<KamataEngine::Sprite*, kDigitCount> digitSprites_{};

    KamataEngine::Vector2 position_ = {
        10.0f,
        20.0f
    };

    KamataEngine::Vector2 digitSize_ = {
        100.0f,
        120.0f
    };
};
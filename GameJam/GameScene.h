#pragma once

#include <KamataEngine.h>

#include <vector>

#include "Player.h"
#include "Rock.h"
#include "Item.h"
#include "Score.h"
#include"Background.h"

class GameScene {
public:
	GameScene();
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

	// 当たり判定
	void CheckCollisions();

	// 円同士の当たり判定
	bool CheckCircleCollision(
		const KamataEngine::Vector2& posA,
		float radiusA,
		const KamataEngine::Vector2& posB,
		float radiusB
	);

	// 岩生成
	void SpawnRock();

	// アイテム生成
	void SpawnItem();

	// 画面外・取得済みオブジェクトの削除
	void RemoveDeadObjects();
	bool IsFinished() const {
		return isFinished_;
	}

	int GetFinalScore() const {
		return score_->GetScore();
	}
private:
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;

	//背景
	Background* backGround_ = nullptr;

	// 岩
	std::vector<Rock*> rocks_;

	// アイテム
	std::vector<Item*> items_;

	// スコア
	Score* score_ = nullptr;

	// ゲームオーバー
	bool isFinished_ = false;

	// -------------------------
	// 生成タイマー
	// -------------------------

	int rockSpawnTimer_ = 0;
	int itemSpawnTimer_ = 0;

	int Timer_ = 10;
	//BGM
	uint32_t bgmHandle_ = 0;
	uint32_t bgmVoiceHandle_ = 0;

	// 岩に当たった音
	uint32_t hitSEHandle_ = 0;

	// アイテム取得音
	uint32_t itemSEHandle_ = 0;

	// 約1.5秒
	static constexpr int kRockSpawnInterval = 90;

	// 約2秒
	static constexpr int kItemSpawnInterval = 120;

	// 画面右側から出す
	static constexpr float kSpawnX = 1300.0f;

	// 3レーン
	static constexpr float kLaneY[3] = {
		70.0f,
		350.0f,
		600.0f
	};
};
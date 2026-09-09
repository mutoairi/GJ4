#pragma once

#include <KamataEngine.h>

#include <vector>

#include "Player.h"
#include "Rock.h"
#include "Item.h"
#include "Score.h"

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

private:
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;

	// 岩
	std::vector<Rock*> rocks_;

	// アイテム
	std::vector<Item*> items_;

	// スコア
	Score* score_ = nullptr;

	// ゲームオーバー
	bool isGameOver_ = false;

	// -------------------------
	// 生成タイマー
	// -------------------------

	int rockSpawnTimer_ = 0;
	int itemSpawnTimer_ = 0;



	// 約1.5秒
	static constexpr int kRockSpawnInterval = 90;

	// 約2秒
	static constexpr int kItemSpawnInterval = 120;

	// 画面右側から出す
	static constexpr float kSpawnX = 1300.0f;

	// 3レーン
	static constexpr float kLaneY[3] = {
		50.0f,
		300.0f,
		600.0f
	};
};
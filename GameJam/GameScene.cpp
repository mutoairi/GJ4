#include "GameScene.h"

#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {

	// プレイヤー
	delete player_;

	// スコア
	delete score_;

	// 岩
	for (Rock* rock : rocks_) {
		delete rock;
	}
	rocks_.clear();

	// アイテム
	for (Item* item : items_) {
		delete item;
	}
	items_.clear();
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// -------------------------
	// プレイヤー
	// -------------------------

	player_ = new Player();
	player_->Initialize(input_);

	// -------------------------
	// スコア
	// -------------------------

	score_ = new Score();
	score_->Initialize();

	// -------------------------
	// 初期値
	// -------------------------

	isGameOver_ = false;

	rockSpawnTimer_ = 0;
	itemSpawnTimer_ = 0;

	// 乱数初期化
	srand(static_cast<unsigned int>(time(nullptr)));
}

void GameScene::Update() {

	// ===================================
	// ゲームオーバーなら更新停止
	// ===================================

	if (isGameOver_) {
		return;
	}

	// ===================================
	// Player
	// ===================================

	player_->Update();

	// ===================================
	// 岩生成
	// ===================================

	rockSpawnTimer_++;

	if (rockSpawnTimer_ >= kRockSpawnInterval) {

		SpawnRock();

		rockSpawnTimer_ = 0;
	}

	// ===================================
	// アイテム生成
	// ===================================

	itemSpawnTimer_++;

	if (itemSpawnTimer_ >= kItemSpawnInterval) {

		SpawnItem();

		itemSpawnTimer_ = 0;
	}

	// ===================================
	// 岩更新
	// ===================================

	for (Rock* rock : rocks_) {
		rock->Update();
	}

	// ===================================
	// アイテム更新
	// ===================================

	for (Item* item : items_) {

		if (!item->IsCollected()) {
			item->Update();
		}
	}

	// ===================================
	// 当たり判定
	// ===================================

	CheckCollisions();

	// ===================================
	// 不要オブジェクト削除
	// ===================================

	RemoveDeadObjects();
}

void GameScene::Draw() {

	ID3D12GraphicsCommandList* commandList =
		dxCommon_->GetCommandList();

	Sprite::PreDraw(commandList);

	// ===================================
	// 岩
	// ===================================

	for (Rock* rock : rocks_) {
		rock->Draw();
	}

	// ===================================
	// アイテム
	// ===================================

	for (Item* item : items_) {

		if (!item->IsCollected()) {
			item->Draw();
		}
	}

	// ===================================
	// Player
	// ===================================

	player_->Draw();

	// ===================================
	// Score
	// ===================================

	score_->Draw();

	Sprite::PostDraw();
}

// =======================================
// 岩生成
// =======================================

void GameScene::SpawnRock() {

	// 0～2のどれか
	int lane = rand() % 3;

	Vector2 position = {
		kSpawnX,
		kLaneY[lane]
	};

	Rock* rock = new Rock();

	rock->Initialize(position);

	rocks_.push_back(rock);
}

// =======================================
// アイテム生成
// =======================================

void GameScene::SpawnItem() {

	// 0～2のどれか
	int lane = rand() % 3;

	Vector2 position = {
		kSpawnX,
		kLaneY[lane]
	};

	Item* item = new Item();

	item->Initialize(position);

	items_.push_back(item);
}

// =======================================
// 当たり判定
// =======================================

void GameScene::CheckCollisions() {

	Vector2 playerPos =
		player_->GetPosition();

	float playerRadius =
		player_->GetRadius();

	// ===================================
	// Player × Rock
	// ===================================

	for (Rock* rock : rocks_) {

		if (CheckCircleCollision(
			playerPos,
			playerRadius,
			rock->GetPosition(),
			rock->GetRadius()
		)) {

			// 岩に当たった
			isGameOver_ = true;

			return;
		}
	}

	// ===================================
	// Player × Item
	// ===================================

	for (Item* item : items_) {

		// すでに取っているなら判定しない
		if (item->IsCollected()) {
			continue;
		}

		if (CheckCircleCollision(
			playerPos,
			playerRadius,
			item->GetPosition(),
			item->GetRadius()
		)) {

			// アイテム取得
			item->Collect();

			// 100点追加
			score_->AddScore(100);
		}
	}
}

// =======================================
// 円同士の当たり判定
// =======================================

bool GameScene::CheckCircleCollision(
	const Vector2& posA,
	float radiusA,
	const Vector2& posB,
	float radiusB
) {

	float dx = posA.x - posB.x;
	float dy = posA.y - posB.y;

	// 中心間距離の2乗
	float distanceSq =
		dx * dx +
		dy * dy;

	// 半径の合計
	float radiusSum =
		radiusA +
		radiusB;

	// 距離 <= 半径の合計なら衝突
	return distanceSq <=
		radiusSum * radiusSum;
}

// =======================================
// 画面外・取得済みオブジェクト削除
// =======================================

void GameScene::RemoveDeadObjects() {

	// -------------------------
	// 岩
	// -------------------------

	for (auto it = rocks_.begin();
		it != rocks_.end();) {

		if ((*it)->IsDead()) {

			delete* it;

			it = rocks_.erase(it);

		}
		else {

			++it;
		}
	}

	// -------------------------
	// アイテム
	// -------------------------

	for (auto it = items_.begin();
		it != items_.end();) {

		if ((*it)->IsDead() ||
			(*it)->IsCollected()) {

			delete* it;

			it = items_.erase(it);

		}
		else {

			++it;
		}
	}
}
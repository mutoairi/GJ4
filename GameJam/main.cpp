#include <Windows.h>
#include<KamataEngine.h>
#include"GameScene.h"
#include"Title.h"
#include"ResultScene.h"
using namespace KamataEngine;

enum class Scene{
	Title,
	Game,
	Result
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	// 汎用機能
	Input* input = nullptr;
	Audio* audio = nullptr;
	AxisIndicator* axisIndicator = nullptr;
	PrimitiveDrawer* primitiveDrawer = nullptr;

	
	// ゲームウィンドウの作成
	win = WinApp::GetInstance();
	// フルスクリーンに設定
	win->CreateGameWindow(L"4064_マグロは止まらない");

	//n->SetFullscreen(true);

	// DirectX初期化処理
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize();

#pragma region 汎用機能初期化
	// ImGuiの初期化
	//GuiManager* imguiManager = ImGuiManager::GetInstance();
	//guiManager->Initialize( dxCommon);

	// 入力の初期化
	input = Input::GetInstance();
	input->Initialize();

	// オーディオの初期化
	audio = Audio::GetInstance();
	audio->Initialize();

	// テクスチャマネージャの初期化
	TextureManager::GetInstance()->Initialize();
	TextureManager::Load("white1x1.png");

	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::kWindowWidth, WinApp::kWindowHeight);

	
	// 軸方向表示初期化
	axisIndicator = AxisIndicator::GetInstance();
	axisIndicator->Initialize();

	primitiveDrawer = PrimitiveDrawer::GetInstance();
	primitiveDrawer->Initialize();
	Scene scene = Scene::Title;

	//タイトル
	Title* title = nullptr;
	title = new Title();
	title->Initialize();
	//ゲーム
	GameScene* gameScene = nullptr;
	//Result
	ResultScene* resultScene = nullptr;
#pragma endregion

	

	// メインループ
	while (true) {
		// メッセージ処理
		if (win->ProcessMessage()) {
			break;
		}

		// ImGui受付開始
		//guiManager->Begin();
		// 入力関連の毎フレーム処理
		input->Update();
		// ゲームシーンの毎フレーム処理
		// ====================================
		// Scene Update
		// ====================================

		switch (scene) {

			// ------------------------------------
			// Title
			// ------------------------------------

		case Scene::Title:

			title->Update();

			// SPACEが押された
			if (title->IsFinished()) {

				// Title終了
				delete title;
				title = nullptr;


				// GameScene生成
				gameScene = new GameScene();

				gameScene->Initialize();


				// Scene変更
				scene = Scene::Game;
			}

			break;


			// ------------------------------------
			// Game
			// ------------------------------------

		case Scene::Game:

			gameScene->Update();

			// 岩に当たって、
			// バラバラ演出などが終了したらtrue
			if (gameScene->IsFinished()) {

				// ----------------------------
				// スコアを保存
				// ----------------------------

				int finalScore =
					gameScene->GetFinalScore();


				// ----------------------------
				// GameScene終了
				// ----------------------------

				delete gameScene;
				gameScene = nullptr;


				// ----------------------------
				// ResultScene生成
				// ----------------------------

				resultScene =
					new ResultScene();

				resultScene->Initialize(
					finalScore
				);


				// ----------------------------
				// Scene変更
				// ----------------------------

				scene = Scene::Result;
			}

			break;


			// ------------------------------------
			// Result
			// ------------------------------------

		case Scene::Result:

			resultScene->Update();

			// SPACEなどでタイトルへ戻る
			if (resultScene->IsFinished()) {

				// ResultScene削除
				delete resultScene;
				resultScene = nullptr;


				// TitleSceneを作り直す
				title = new Title();

				title->Initialize();


				// Titleへ
				scene = Scene::Title;
			}

			break;
		}

		
		// 軸表示の更新
		axisIndicator->Update();
		// ImGui受付終了
		//guiManager->End();
		Sprite::ResetInstanceCount();
		// 描画開始
		dxCommon->PreDraw();
		// ゲームシーンの描画
		switch (scene) {

		case Scene::Title:

			title->Draw();

			break;


		case Scene::Game:

			gameScene->Draw();

			break;


		case Scene::Result:

			resultScene->Draw();

			break;
		}

		// 軸表示の描画
		axisIndicator->Draw();
		// プリミティブ描画のリセット
		primitiveDrawer->Reset();
		// ImGui描画
		//guiManager->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}

	// 各種解放
	//delete gameScene;
	delete title;
	delete gameScene;
	delete resultScene;

	
	audio->Finalize();
	// ImGui解放
	//guiManager->Finalize();

	// ゲームウィンドウの破棄
	win->TerminateGameWindow();

	return 0;
}



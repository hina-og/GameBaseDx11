#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class TestScene : public GameObject
{
	int i = 0;
	int j = 0;
	int rand_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TestScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
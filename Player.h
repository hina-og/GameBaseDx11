#pragma once
#include "Engine/GameObject.h"

class Player
	: public GameObject
{
	int hModel_;
	XMFLOAT3 cameraPos_{0,0,0};
	bool isMove;
public:
	Player(GameObject* parent);

	void Initialize();

	//XV
	void Update();

	//•`‰æ
	void Draw();

	//ŠJ•ú
	void Release();
};


#pragma once
#include "Engine/GameObject.h"

class Player
	: public GameObject
{
	int hModel_;
	XMFLOAT3 cameraPos_{0,0,0};
	bool canMove;
public:
	Player(GameObject* parent);

	void Initialize();

	//XV
	void Update();

	//•`‰æ
	void Draw();

	//ŠJ•ú
	void Release();

	void OnCollision(GameObject* pTarget) override;
};


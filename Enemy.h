#pragma once
#include "Engine/GameObject.h"

class Enemy
	: public GameObject
{
	int hModel_;
	float moveSpeed;
	bool canMove;
public:
	Enemy(GameObject* parent);

	void Initialize();

	void Update();

	void Draw();

	void Release();
};


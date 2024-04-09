#pragma once
#include "Engine/GameObject.h"

class Enemy
	: public GameObject
{
public:
	Enemy(GameObject* parent);

	void Initialize();

	//XV
	void Update();

	//•`‰æ
	void Draw();

	//ŠJ•ú
	void Release();
};


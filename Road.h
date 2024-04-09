#pragma once
#include "Engine/GameObject.h"

class Road
	: public GameObject
{
	int hModel_;
public:
	Road(GameObject* parent);

	void Initialize();

	//XV
	void Update();

	//•`‰æ
	void Draw();

	//ŠJ•ú
	void Release();
};


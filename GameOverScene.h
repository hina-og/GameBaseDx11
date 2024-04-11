#pragma once
#include "Engine/GameObject.h"
class GameOverScene 
	: public GameObject
{
	int hPict_;
public:
	GameOverScene(GameObject* parent);

	void Initialize();

	void Update();

	void Draw();

	void Release();
};


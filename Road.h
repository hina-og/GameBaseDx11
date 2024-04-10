#pragma once
#include "Engine/GameObject.h"

class Road
	: public GameObject
{
	int hModel_;
	int speedLevel;
	float moveSpeed;
	bool canMove;
	int roadNum{ 10 };

	int tileSize{ 1 };
	const int ALLroadNum{ 10 };
public:
	bool canAddTile;

	Road(GameObject* parent);

	void Initialize();

	void Update();

	void Draw();

	void Release();


};


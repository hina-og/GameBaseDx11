#pragma once
#include "Engine/GameObject.h"

class Road
	: public GameObject
{
	int hModel_;
	float moveSpeed_;
	bool canMove_;
public:
	Road(GameObject* parent);

	void Initialize();

	void Update();

	void Draw();

	void Release();

	void SetSpeed(float _speed);
};


#pragma once
#include "Engine/GameObject.h"

class Enemy
	: public GameObject
{
public:
	Enemy(GameObject* parent);

	void Initialize();

	//�X�V
	void Update();

	//�`��
	void Draw();

	//�J��
	void Release();
};


#pragma once
#include "Engine/GameObject.h"

class Road
	: public GameObject
{
	int hModel_;
public:
	Road(GameObject* parent);

	void Initialize();

	//�X�V
	void Update();

	//�`��
	void Draw();

	//�J��
	void Release();
};


#include "Road.h"
#include "Engine/Model.h"

Road::Road(GameObject* parent)
	:GameObject(parent, "Road"), hModel_(-1)
{
	hModel_ = Model::Load("Model\\roadTile.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,-5,-10 };
	moveSpeed = 0.1;
	canMove = false;
}

void Road::Initialize()
{
	
}

void Road::Update()
{
	if (canMove)
	{
		transform_.position_.z += moveSpeed;
	}
	if (transform_.position_.y >= 0)
	{
		transform_.position_.y = 0;
		canMove = true;
	}
	else
	{
		transform_.position_.y += moveSpeed;
	}
	if (transform_.position_.z > 3)
	{
		KillMe();
	}
}

void Road::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Road::Release()
{
}


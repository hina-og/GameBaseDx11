#include "Road.h"
#include "Engine/Model.h"

Road::Road(GameObject* parent)
	:GameObject(parent, "Road"), hModel_(-1)
{
	hModel_ = Model::Load("Model\\roadTile.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,-5,-10 };
	moveSpeed_ = 0.1;
	canMove_ = false;
}

void Road::Initialize()
{
	
}

void Road::Update()
{
	if (canMove_)
	{
		transform_.position_.z += moveSpeed_;
	}
	if (transform_.position_.y >= 0)
	{
		transform_.position_.y = 0;
		canMove_ = true;
	}
	else
	{
		transform_.position_.y += moveSpeed_;
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

void Road::SetSpeed(float _speed)
{
	moveSpeed_ = _speed;
}


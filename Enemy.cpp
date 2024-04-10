#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,-5,-10 };
	moveSpeed = 0.1;
	canMove = false;
}

void Enemy::Initialize()
{
}

void Enemy::Update()
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

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

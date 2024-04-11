#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,-5,-10 };
	moveSpeed_ = 0.1;
	canMove_ = false;
}

void Enemy::Initialize()
{
	transform_.position_.x = (float)(rand() % 3 - 1);
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0, 0.5, 0), 0.45);
	AddCollider(collider);
}

void Enemy::Update()
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

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::SetSpeed(float _speed)
{
	moveSpeed_ = _speed;
}

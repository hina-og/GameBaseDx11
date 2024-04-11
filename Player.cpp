#include "Player.h"
#include "Road.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
	hModel_ = Model::Load("Model\\player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	canMove = false;
}

void Player::Initialize()
{
	
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0, 0.5, 0), 0.45);
	AddCollider(collider);
}

void Player::Update()
{
	
	if (Input::IsKey(DIK_RIGHT))
	{
		if (transform_.position_.x >= 0 && !canMove)
		{
			transform_.position_.x -= 1;
		}
		canMove = true;
	}
	else if (Input::IsKey(DIK_LEFT))
	{
		if (transform_.position_.x < 1 && !canMove)
		{
			transform_.position_.x += 1;
		}
		canMove = true;
	}
	else
	{
		canMove = false;
	}

	cameraPos_ = { transform_.position_.x + 0, transform_.position_.y + 2 ,transform_.position_.z + 4 };
	Camera::SetPosition(cameraPos_);
	Camera::SetTarget(transform_.position_);
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		KillMe();
	}
}

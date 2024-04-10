#include "Player.h"
#include "Road.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	isMove = false;
}

void Player::Update()
{
	
	if (Input::IsKey(DIK_RIGHT))
	{
		if (transform_.position_.x >= 0 && !isMove)
		{
			transform_.position_.x -= 1;
		}
		isMove = true;
	}
	else if (Input::IsKey(DIK_LEFT))
	{
		if (transform_.position_.x < 1 && !isMove)
		{
			transform_.position_.x += 1;
		}
		isMove = true;
	}
	else
	{
		isMove = false;
	}
	//SphereCollider* collision = new SphereCollider(transform_.position_.x, transform_.position_.y + 0.5f, transform_.position_.z, 0.5f);
	//AddCollider(collision);

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

#include "Player.h"
#include "Road.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

void Player::Update()
{
	cameraPos_ = { transform_.position_.x + 0, transform_.position_.y + 2 ,transform_.position_.z + 4 };
	Camera::SetPosition(cameraPos_);
	//Camera::SetPosition(XMFLOAT3{0,2,4});
	Camera::SetTarget(transform_.position_);
	if (transform_.position_.x>=0 && transform_.position_.x<4)
	{
		if (Input::IsKey(DIK_LEFT))
		{
			if (!pushL)
			{
				pushL = true;
			}
			if (transform_.position_.x >= 0)
			{
				transform_.position_.x += 1;
			}
		}
		else
		{
			pushL = false;
		}
		if (Input::IsKey(DIK_RIGHT))
		{
			transform_.position_.x -= 1;
			if (!pushR)
			{
				pushR = true;
			}
		}
		else
		{
			pushR = false;
		}
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

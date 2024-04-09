#include "Road.h"
#include "Engine/Model.h"

Road::Road(GameObject* parent)
	:GameObject(parent, "Road"), hModel_(-1)
{
}

void Road::Initialize()
{
	hModel_ = Model::Load("road.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

void Road::Update()
{
}

void Road::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Road::Release()
{
}

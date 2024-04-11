#include "TitleScene.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "Player"), hPict_(-1)
{
}

void TitleScene::Initialize()
{
	hPict_ = Image::Load("Image\\TitleScene");
	assert(hPict_ >= 0);
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleScene::Release()
{
}

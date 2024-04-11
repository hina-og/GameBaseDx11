#include "GameOverScene.h"
#include "Engine/Image.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"Title"),hPict_(-1)
{
}

void GameOverScene::Initialize()
{
	hPict_ = Image::Load("Image\\ClearScene");
	assert(hPict_ >= 0);
}

void GameOverScene::Update()
{
}

void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void GameOverScene::Release()
{
}

#include "TestScene.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<Player>(this);
	
}

//更新
void TestScene::Update()
{
	rand_ = rand();
	if (i == 10)
	{
		i = 0;
		Instantiate<Road>(this);
	}
	if (j == 80)
	{
		j = 0;
		/*Enemy* enemy = Instantiate<Enemy>(this);
		enemy->SetPosition(XMFLOAT3{ rand_ % 3,-5,-8});*/
		Instantiate<Enemy>(this);
	}
	i++;
	j++;
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}

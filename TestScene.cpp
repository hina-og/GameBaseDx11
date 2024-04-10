#include "TestScene.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Instantiate<Player>(this);
	
}

//�X�V
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

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}

#include "PlayScene.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	speed_ = 0.25;
	speedRate_ = 1 / speed_;
}

//更新
void PlayScene::Update()
{
	if (i == speedRate_)
	{
		i = 0;
		Road* road = Instantiate<Road>(this);
		road->SetSpeed(speed_);
	}
	if (j == speedRate_ * 5)
	{
		j = 0;
		Enemy* enemy1 = Instantiate<Enemy>(this);
		enemy1->SetSpeed(speed_);
		enemypos_ = enemy1->GetPosition();
		if (enemypos_.x == 1)
		{
			Enemy* enemy2 = Instantiate<Enemy>(this);
			enemy2->SetPosition(XMFLOAT3{ enemypos_.x - 2,enemypos_.y,enemypos_.z });
			enemy2->SetSpeed(speed_);
		}
		else
		{
			Enemy* enemy2 = Instantiate<Enemy>(this);
			enemy2->SetPosition(XMFLOAT3{ enemypos_.x + 1,enemypos_.y,enemypos_.z });
			enemy2->SetSpeed(speed_);
		}
	}
	i++;
	j++;
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}

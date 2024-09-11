#include "TestScene.h"
#include "Player.h"
#include "KuruKuruImage.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Instantiate <Player>(this);
	kImage = new KuruKuruImage();
	kImage->Load("roundTimer.png");

}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
	kImage->Draw(transform_, RECT{ 0,0, 512,512 }, 1.0, 0, 360);
}

//開放
void TestScene::Release()
{
}

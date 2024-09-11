#include "TestScene.h"
#include "Player.h"
#include "KuruKuruImage.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Instantiate <Player>(this);
	kImage = new KuruKuruImage();
	kImage->Load("roundTimer.png");

}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
	kImage->Draw(transform_, RECT{ 0,0, 512,512 }, 1.0, 0, 360);
}

//�J��
void TestScene::Release()
{
}

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
	static float start = 90;
	static float end = 90;
	//start,end�͂O�`�R�U�O�œ���
	kImage->Draw(transform_, RECT{ 0,0, 512,512 }, 1.0, start, end);
	end = end + 0.166;
	if (end > 360)
		end = end - 360;
	
}

//�J��
void TestScene::Release()
{
}

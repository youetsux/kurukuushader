#include "TestScene.h"
#include "Player.h"
#include "CircleGauge.h"
#include "Engine/Input.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),pGauge(nullptr)
{
}

//������
void TestScene::Initialize()
{	
	pGauge = Instantiate<CircleGauge>(this);

	pGauge->SetAngle(0, true);
	pGauge->SetLapTime(10);
	pGauge->SetPosition(-0.8, 0, 0);
	pGauge->SetScale(0.3, 0.3, 0);
}

//�X�V
void TestScene::Update()
{
	if(Input::IsKeyDown(DIK_SPACE))
	{
		pGauge->Start();
	}
}

//�`��
void TestScene::Draw()
{

	
}

//�J��
void TestScene::Release()
{
}

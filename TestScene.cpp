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
	pGauge->SetAngle(0, false);
	pGauge->SetLapTime(15);
	pGauge->SetPosition(0, 0.6, 0);
	pGauge->SetScale(0.3, 0.3, 0);
	pGauge->SetRotate(0, 0, 90);
}

//�X�V
void TestScene::Update()
{
	static bool isStart = false;
	if(Input::IsKeyDown(DIK_SPACE))
	{
		if (isStart)
		{
			pGauge->Stop();
			isStart = false;
		}
		else
		{
			pGauge->Start();
			isStart = true;
		}
	}
	if (Input::IsKeyDown(DIK_R))
	{
		pGauge->Stop();
		pGauge->Reset();
		isStart = false;
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

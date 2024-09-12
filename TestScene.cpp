#include "TestScene.h"
#include "Player.h"
#include "CircleGauge.h"
#include "Engine/Input.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),pGauge(nullptr)
{
}

//初期化
void TestScene::Initialize()
{	
	pGauge = Instantiate<CircleGauge>(this);
	pGauge->SetLapTime(15);
	pGauge->SetStartAngle(0, false);
	pGauge->SetPosition(-0.8, 0, 0);
	pGauge->SetScale(0.5, 0.5, 0);
}

//更新
void TestScene::Update()
{
	if(Input::IsKeyDown(DIK_SPACE))
	{
		pGauge->Start();
	}
}

//描画
void TestScene::Draw()
{

	
}

//開放
void TestScene::Release()
{
}

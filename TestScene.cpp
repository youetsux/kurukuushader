#include "TestScene.h"
#include "Player.h"
#include "KuruKuruImage.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//‰Šú‰»
void TestScene::Initialize()
{	
	kImage = new KuruKuruImage();
	kImage->Load("roundTimer.png");
}

//XV
void TestScene::Update()
{
}

//•`‰æ
void TestScene::Draw()
{
	static float start = 90;
	static float end = 90;
	//start,end‚Í‚O`‚R‚U‚O‚Å“ü—Í
	kImage->Draw(transform_, RECT{ 0,0, 512,512 }, 1.0, start, end);
	end = end + 0.166;
	if (end > 360)
		end = end - 360;
	
}

//ŠJ•ú
void TestScene::Release()
{
}

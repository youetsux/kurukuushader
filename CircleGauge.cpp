#include "CircleGauge.h"
#include "KuruKuruImage.h"
#include "Engine/Image.h"

CircleGauge::CircleGauge(GameObject* parent)
	:GameObject(parent, "KuruKuru"),
	gaugeAngle_(0), def_gaugeAngle_(0), kImage_(nullptr), lapTime_(0)
{
}

void CircleGauge::Initialize()
{
	hFrame = Image::Load("gaugeImage.png");
	hBack = Image::Load("circleBack.png");

	kImage_ = new KuruKuruImage();
	kImage_->Load("circle.png");
	lapTime_ = 60; //秒で指定？ デフォルトは６０ｓ
	lapFrameTime_ = 360.0f / (lapTime_ * 60);
	def_gaugeAngle_ = gaugeAngle_; //リセット用に初期位置を保存
	isIncrease_ = true;
	isActive_ = false;
}

void CircleGauge::Update()
{
	if (isActive_)
	{
		//start,endは０～３６０で入力
		gaugeAngle_ = gaugeAngle_ + lapFrameTime_;
		//if (gaugeAngle_ > 360.0f) //ないと思うけど保険
		//	gaugeAngle_ = gaugeAngle_ - 360.0f;
		if (gaugeAngle_ > 360.0) {
			gaugeAngle_ = 360.0f;
			Stop();
		}
	}
	//角度、回転方向、増えるゲージか、減るゲージか
	kImage_->SetDrawProperties(gaugeAngle_, true, isIncrease_);
}

void CircleGauge::Draw()
{
	XMFLOAT3 isize = kImage_->GetTextureSize();
	transform_.Calclation();
	Image::SetTransform(hBack, transform_);
	Image::Draw(hBack);
	kImage_->Draw(transform_, RECT{ 0, 0, (int)isize.x, (int)isize.y }, 1.0);
	Image::SetTransform(hFrame, transform_);
	Image::Draw(hFrame);
}

void CircleGauge::Release()
{
	delete kImage_;
}


void CircleGauge::SetAngle(float angle, bool isinc)
{
	gaugeAngle_ = angle;

	def_gaugeAngle_ = gaugeAngle_; //リセット用に初期位置を保存

	isIncrease_ = isinc;
}

void CircleGauge::SetLapTime(float laptime)
{
	lapTime_ = laptime; //秒で指定？
	lapFrameTime_ = 360.0f / (lapTime_ * 60);
}

void CircleGauge::Start()
{
	isActive_ = true;
}

void CircleGauge::Stop()
{
	isActive_ = false;
}

void CircleGauge::Reset()
{
	isActive_ = false;
	gaugeAngle_ = def_gaugeAngle_;
}

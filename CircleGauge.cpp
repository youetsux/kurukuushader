#include "CircleGauge.h"
#include "KuruKuruImage.h"

CircleGauge::CircleGauge(GameObject* parent)
	:GameObject(parent, "KuruKuru"),
	startAngle_(0), endAngle_(0), kImage_(nullptr), lapTime_(0)
{
}

void CircleGauge::Initialize()
{
	startAngle_ = 90;
	endAngle_ = 90;
	kImage_ = new KuruKuruImage();
	kImage_->Load("roundTimer.png");
	lapTime_ = 60; //秒で指定？ デフォルトは６０ｓ
	lapFrameTime_ = 360.0f / (lapTime_ * 60);
	def_startAngle_ = startAngle_; //リセット用に初期位置を保存
	def_endAngle_ = endAngle_;		//リセット用に初期位置を保存
	isIncrease_ = true;
	isActive_ = false;
}

void CircleGauge::Update()
{
	if (isActive_)
	{
		//start,endは０～３６０で入力
		endAngle_ = endAngle_ + lapFrameTime_;
		if (endAngle_ > 360.0f)
			endAngle_ = endAngle_ - 360.0f;
	}
}

void CircleGauge::Draw()
{
	kImage_->GetTextureSize();
	transform_.Calclation();
	if (isIncrease_)
		kImage_->Draw(transform_, RECT{ 0, 0, 512, 512 }, 1.0, startAngle_, endAngle_);
	else
		kImage_->Draw(transform_, RECT{ 0, 0, 512, 512 }, 1.0, endAngle_, startAngle_);
}

void CircleGauge::Release()
{
	delete kImage_;
}


void CircleGauge::SetStartAngle(float start, bool isinc)
{
	if (isinc) {
		startAngle_ = start;
		endAngle_ = start - 0.0001f;
	}
	def_startAngle_ = startAngle_; //リセット用に初期位置を保存
	def_endAngle_ = endAngle_;		//リセット用に初期位置を保存

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
	startAngle_ = def_startAngle_;
	endAngle_ = def_endAngle_;
}

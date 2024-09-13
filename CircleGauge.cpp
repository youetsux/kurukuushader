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
	lapTime_ = 60; //�b�Ŏw��H �f�t�H���g�͂U�O��
	lapFrameTime_ = 360.0f / (lapTime_ * 60);
	def_startAngle_ = startAngle_; //���Z�b�g�p�ɏ����ʒu��ۑ�
	def_endAngle_ = endAngle_;		//���Z�b�g�p�ɏ����ʒu��ۑ�
	isIncrease_ = true;
	isActive_ = false;
}

void CircleGauge::Update()
{
	if (isActive_)
	{
		//start,end�͂O�`�R�U�O�œ���
		endAngle_ = endAngle_ + lapFrameTime_;
		if (endAngle_ > 360.0f)
			endAngle_ = endAngle_ - 360.0f;
	}
}

void CircleGauge::Draw()
{
	XMFLOAT3 isize = kImage_->GetTextureSize();
	transform_.Calclation();
	if (isIncrease_)
		kImage_->Draw(transform_, RECT{ 0, 0, (int)isize.x, (int)isize.y }, 1.0, startAngle_, endAngle_);
	else
		kImage_->Draw(transform_, RECT{ 0, 0, (int)isize.x, (int)isize.y }, 1.0, endAngle_, startAngle_);
}

void CircleGauge::Release()
{
	delete kImage_;
}


void CircleGauge::SetStartAngle(float start, bool isinc)
{
	startAngle_ = start;
	endAngle_ = start;
	def_startAngle_ = startAngle_; //���Z�b�g�p�ɏ����ʒu��ۑ�
	def_endAngle_ = endAngle_;		//���Z�b�g�p�ɏ����ʒu��ۑ�
	isIncrease_ = isinc;
}

void CircleGauge::SetLapTime(float laptime)
{
	lapTime_ = laptime; //�b�Ŏw��H
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

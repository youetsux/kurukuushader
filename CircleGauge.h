#pragma once
#include "Engine/GameObject.h"

class KuruKuruImage;

class CircleGauge :
    public GameObject
{
	int hFrame;
	KuruKuruImage* kImage_;
	float gaugeAngle_;
	float def_gaugeAngle_;//�����ʒu��ۑ�
	float lapTime_;
	float lapFrameTime_;
	bool  isActive_;
	bool isIncrease_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CircleGauge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetAngle(float angle, bool isinc);
	void SetLapTime(float laptime);
	void Start();
	void Stop();
	void Reset();
};


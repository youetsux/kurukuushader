#pragma once
#include "Engine/GameObject.h"

class KuruKuruImage;

class CircleGauge :
    public GameObject
{
	int hFrame;
	KuruKuruImage* kImage_;
	float gaugeAngle_;
	float def_gaugeAngle_;//初期位置を保存
	float lapTime_;
	float lapFrameTime_;
	bool  isActive_;
	bool isIncrease_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CircleGauge(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetAngle(float angle, bool isinc);
	void SetLapTime(float laptime);
	void Start();
	void Stop();
	void Reset();
};


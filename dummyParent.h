#pragma once
#include "Engine/GameObject.h"
class dummyParent :
    public GameObject
{
public:
	dummyParent(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};


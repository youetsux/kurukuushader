#pragma once
#include "Engine\GameObject.h"

class Weapon :
    public GameObject
{
	int hWeapon_;
	Transform localPos;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Weapon(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

public:
	void SetPos(const XMFLOAT3& pos){ transform_.position_ = pos; }
	void SetWpos(const Transform& tr);
};


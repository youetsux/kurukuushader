#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Weapon.h"

class CircleGauge;
//�e�X�g�V�[�����Ǘ�����N���X
class TestScene : public GameObject
{
public:
	CircleGauge* pGauge;
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TestScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};
#pragma once
#include "GameEngineObject.h"
#include "GameEngineActor.h"
#include <list>
#include <string>
#include <map>

// ���� : ȭ��Ȥ�� ����� ǥ���մϴ�.
// Ÿ��Ʋ ���
// �÷��� ���
// ���� ���

// ���漱��
class GameEngineCamera;
class GameEngineLevel : public GameEngineObject
{
	friend class GameEngineActor;
	friend class GameEngineCore;

public:
	// constrcuter destructer
	GameEngineLevel();
	~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;


	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0)
	{
		std::list<GameEngineActor*>& GroupList = AllActors[_Order];
		GameEngineActor* NewActor = new ActorType();
		ActorInit(NewActor);
		GroupList.push_back(NewActor);

		return dynamic_cast<ActorType*>(NewActor);
	}


protected:

private:
	// ���������ϸ� �ش��� �ʿ��ϴ�
	// �����ʹ� ���漱���� ���ܸ�ȴ�
	GameEngineCamera* MainCamera;
	GameEngineCamera* UICamera;
	// ��
	// �÷��̾�
	// ����

	// -10�� std::list<> ���� ���� ���� ���� 
	// 0�� std::list<> ���� ���� ���� ����
	// 1�� std::list<> ���� ���� ���� ����

	std::map<int, std::list<GameEngineActor*>> AllActors;

	void ActorInit(GameEngineActor* _Actor);

	void ActorUpdate(float _Delta);
	void ActorRender();
};


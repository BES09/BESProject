#include "GameEngineActor.h"
#include "GameEngineRenderer.h"
#include "GameEngineLevel.h"
#include "GameEngineCamera.h"
#include <GameEngineBase/GameEngineDebug.h>

GameEngineActor::GameEngineActor()
{
}

GameEngineActor::~GameEngineActor()
{
	for (GameEngineRenderer* Render : AllRenderer)
	{
		delete Render;
		Render = nullptr;
	}
}

void GameEngineActor::ActorRelease()
{
	std::list<GameEngineRenderer*>& Group = AllRenderer;

	std::list<GameEngineRenderer*>::iterator ObjectStartIter = Group.begin();
	std::list<GameEngineRenderer*>::iterator ObjectEndIter = Group.end();

	for (; ObjectStartIter != ObjectEndIter; )
	{
		GameEngineRenderer* Object = *ObjectStartIter;
		if (false == Object->IsDeath())
		{
			++ObjectStartIter;
			continue;
		}

		if (nullptr == Object)
		{
			MsgBoxAssert("nullptr�� ���Ͱ� ������ ����Ʈ�� �� �־����ϴ�.");
			continue;
		}

		delete Object;
		Object = nullptr;

		// [s] [a] [a]     [a] [e]
		ObjectStartIter = Group.erase(ObjectStartIter);

	}
}

GameEngineRenderer* GameEngineActor::CreateRenderer(const std::string& _ImageName, int _Order)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	GetLevel()->MainCamera->PushRenderer(NewRenderer, _Order);

	NewRenderer->Master = this;
	if (_ImageName != "")
	{
		NewRenderer->SetTexture(_ImageName);
	}
	AllRenderer.push_back(NewRenderer);

	return NewRenderer;
}
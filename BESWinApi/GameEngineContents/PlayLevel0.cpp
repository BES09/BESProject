#include "PlayLevel0.h"
#include "Player.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>

PlayLevel0::PlayLevel0()
{

}

PlayLevel0::~PlayLevel0()
{

}


void PlayLevel0::Start()
{							
	// ResourcesManager::GetInst().TextureLoad("AAA.Png", 경로);
	// 플레이 레벨이 만들어졌다.
	// 이 레벨에는 뭐가 있어야지?
	// 플레이어 만들고
	// 맵만들고
	// 몬스터 만들고
	// 액터

	// 자기 임의대로 만들겠다는 것이고 xxxxx
	// Player* NewPlayer = new Player();

	CreateActor<Player>();
}


void PlayLevel0::Update(float _Delta)
{
	// GameEngineCore::ChangeLevel("TitleLevel");
}
void PlayLevel0::Render()
{
}
void PlayLevel0::Release()
{
}
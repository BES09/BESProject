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
	// ResourcesManager::GetInst().TextureLoad("AAA.Png", ���);
	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �ʸ����
	// ���� �����
	// ����

	// �ڱ� ���Ǵ�� ����ڴٴ� ���̰� xxxxx
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
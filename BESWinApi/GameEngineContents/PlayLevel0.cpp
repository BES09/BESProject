#include "PlayLevel0.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>


// Contents
#include "Player.h"
#include "BackGround.h"

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

	BackGround* Back = CreateActor<BackGround>();
	Back->Init("1st part test.Bmp");

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
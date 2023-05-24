#include "PlayLevel0.h"
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "Monster.h"


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

	if (false == ResourcesManager::GetInst().IsLoadTexture("1st part test.Bmp"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");

		GameEnginePath FolderPath = FilePath;

		FilePath.MoveChild("ContentsResources\\Texture\\Map\\");
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("1st part test2.bmp"));
	}


	// ResourcesManager::GetInst().TextureLoad("AAA.Png", ���);

	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �ʸ����
	// ���� �����
	// ����

	// �ڱ� ���Ǵ�� ����ڴٴ� ���̰� xxxxx
	// Player* NewPlayer = new Player();
	BackGroundPtr = CreateActor<BackGround>();
	BackGroundPtr->Init("1st part test.Bmp", "1st part test2.bmp");

	LevelPlayer = CreateActor<Player>();
	LevelPlayer->SetGroundTexture("1st part test2.bmp");

	LevelPlayer = CreateActor<Player>();
}


void PlayLevel0::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown('O'))
	{
		GameEngineCore::ChangeLevel("TitleLevel0");
	}

	if (true == GameEngineInput::IsDown('J'))
	{
		BackGroundPtr->SwitchRender();
	}

	if (1.0f <= GetLiveTime())
	{
		Monster* NewMonster = CreateActor<Monster>();
		ResetLiveTime();
	}

	// GameEngineCore::ChangeLevel("TitleLevel");
}
void PlayLevel0::Render()
{
}
void PlayLevel0::Release()
{
}

void PlayLevel0::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (nullptr == LevelPlayer)
	{
		MsgBoxAssert("�÷��̾ ���������� �ʾҽ��ϴ�");
	}
	LevelPlayer->SetGroundTexture("1st part test2.bmp");

	//float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	//LevelPlayer->SetPos(WinScale.Half());
	// 0 0
	// x y
	//GetMainCamera()->SetPos(LevelPlayer->GetPos() - WinScale.Half());

}

void PlayLevel0::LevelEnd(GameEngineLevel* _NextLevel)
{

}
#include "ContentCore.h"
#include "TitleLevel0.h"
#include "PlayLevel0.h"
#include "EndingLevel0.h"
#include <GameEnginePlatform/GameEngineWindow.h>

ContentCore::ContentCore()
{
}

ContentCore::~ContentCore()
{
}

void ContentCore::Start()
{
	GameEngineWindow::MainWindow.SetPosAndScale({ 100, 100 }, { 1280, 720 });

	GameEngineCore::CreateLevel<TitleLevel0>("TitleLevel0");
	GameEngineCore::CreateLevel<PlayLevel0>("PlayLevel0");
	GameEngineCore::CreateLevel<EndingLevel0>("EndingLevel0");

	// �� ������ ȭ�鿡 ������.
	GameEngineCore::ChangeLevel("PlayLevel0");
}

// �ൿ�Ѱ�.
void ContentCore::Update(float _Delta)
{
}

// �׷�����.
void ContentCore::Render()
{
}

// �����ȴ�.
void ContentCore::Release()
{
}
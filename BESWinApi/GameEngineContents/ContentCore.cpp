#include "ContentCore.h"
#include "TitleLevel0.h"
#include "PlayLevel0.h"
#include "EndingLevel0.h"

ContentCore::ContentCore()
{
}

ContentCore::~ContentCore()
{
}

void ContentCore::Start()
{
	GameEngineCore::CreateLevel<TitleLevel0>("TitleLevel0");
	GameEngineCore::CreateLevel<PlayLevel0>("PlayLevel0");
	GameEngineCore::CreateLevel<EndingLevel0>("EndingLevel0");

	// �� ������ ȭ�鿡 ������.
	GameEngineCore::ChangeLevel("PlayLevel0");
}

// �ൿ�Ѱ�.
void ContentCore::Update()
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
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

	// 이 레벨이 화면에 보여라.
	GameEngineCore::ChangeLevel("PlayLevel0");
}

// 행동한고.
void ContentCore::Update()
{
}

// 그려지고.
void ContentCore::Render()
{
}

// 정리된다.
void ContentCore::Release()
{
}
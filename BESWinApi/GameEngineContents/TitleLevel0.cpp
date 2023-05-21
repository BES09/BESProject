#include "TitleLevel0.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>

TitleLevel0::TitleLevel0()
{
}

TitleLevel0::~TitleLevel0()
{
}

void TitleLevel0::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown('P'))
	{
		GameEngineCore::ChangeLevel("PlayLevel0");
	}
}
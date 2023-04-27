#include "GameEngineCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

GameEngineCore::GameEngineCore() 
{
}

GameEngineCore::~GameEngineCore() 
{
}

void GameEngineCore::EnsgineStart(HINSTANCE _Inst)
{
	GameEngineWindow::MessageLoop()
}

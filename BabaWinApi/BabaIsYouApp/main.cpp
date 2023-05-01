#include <iostream>
#include <GameEngineCore/GameEngineCore.h>

#include <BabaContents/PlayLevel0.h>
#include <BabaContents/TitleLevel0.h>
#include <list>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	GameEngineCore::EngineStart("MyWindow", hInstance);
	return 0;
}
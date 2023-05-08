#include "Player.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEngineCore/ResourcesManager.h>

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Test.Bmp"))
	{
		// 무조건 자동으로 현재 실행중인 위치가 된다.
		// 경로
		// 시작위치 
		// 
		// 시작위치 
		// 도착위치 
		GameEnginePath FilePath;
		// 시작위치 
		FilePath.GetCurrentPath();
		// 시작위치 

		// ContentsResources

		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Texture\\Player\\Test.bmp");

		ResourcesManager::GetInst().TextureLoad(FilePath.GetStringPath());
	}


	SetPos({ 200, 200 });
	SetScale({ 100, 100 });
}

void Player::Update(float _Delta)
{
	// 아주 어리석은 절대로 아마 안될 계산을 하는것이다.
	// Player->GetPos() == Monster->GetPos();
	// float Time = GameEngineTime::MainTimer.GetDeltaTime();

	AddPos({ 100.0f * _Delta, 0.0f });
}

void Player::Render()
{
	//SetPos({ 200, 200 });
	//SetScale({ 100, 100 });

	// 그렸을때 화면에 나오는건 언제나 window에 있는 BackBuffer에다가 그려야만 한다.
	// 모든건 다 Texture고 
	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Test.Bmp");
	BackBuffer->BitCopy(FindTexture, GetPos(), GetScale());

}

void Player::Release()
{
}
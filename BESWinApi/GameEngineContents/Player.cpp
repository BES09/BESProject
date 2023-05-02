#include "Player.h"
#include <Windows.h>
#include <GameEnginePlatform/GameEngineWindow.h>

Player::Player()
{
}

Player::~Player()
{
}


void Player::Start()
{
	SetPos({ 200, 200 });
	SetScale({ 100, 100 });
}

void Player::Update()
{
	// 실수익때문에 계산이 안될것이다.
	// Player->getpos == Monster->getpos

	AddPos({ 1.0f, 0.0f });
}

void Player::Render()
{
	//SetPos({ 200, 200 });
	//SetScale({ 100, 100 });

	HDC WindowDC = GameEngineWindow::MainWindow.GetHDC();

	Rectangle(WindowDC,
		GetPos().iX() - GetScale().ihX(),
		GetPos().iY() - GetScale().ihY(),
		GetPos().iX() + GetScale().ihX(),
		GetPos().iY() + GetScale().ihY()
	);

	// 그려야죠?
}

void Player::Release()
{
}
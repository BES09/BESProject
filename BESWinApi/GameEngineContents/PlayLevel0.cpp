#include "PlayLevel0.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>

PlayLevel0::PlayLevel0()
{

}

PlayLevel0::~PlayLevel0()
{

}


void PlayLevel0::Start()
{
	// �÷��� ������ ���������.
	// �� �������� ���� �־����?
	// �÷��̾� �����
	// �ʸ����
	// ���� �����
	// ����

	// �ڱ� ���Ǵ�� ����ڴٴ� ���̰� xxxxx
	// Player* NewPlayer = new Player();

	CreateActor<Player>();
}


void PlayLevel0::Update()
{
	GameEngineCore::
}
void PlayLevel0::Render()
{
}
void PlayLevel0::Release()
{
}
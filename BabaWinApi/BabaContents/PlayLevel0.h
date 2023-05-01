#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class PlayLevel0 : public GameEngineLevel
{
public:
	PlayLevel0();
	~PlayLevel0();

	//
	PlayLevel0(const PlayLevel0& _Other) = delete;
	PlayLevel0(PlayLevel0& _Other) noexcept = delete;
	PlayLevel0& operator=(const PlayLevel0& _Other) = delete;
	PlayLevel0& operator=(PlayLevel0& _Other) noexcept = delete;

protected:

private:

};


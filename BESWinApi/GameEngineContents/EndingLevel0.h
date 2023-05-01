#pragma once
#include <GameEngineCore/GameEngineLevel.h>


class EndingLevel0 : public GameEngineLevel
{
public:
	EndingLevel0();
	~EndingLevel0();

	//
	EndingLevel0(const EndingLevel0& _Other) = delete;
	EndingLevel0(EndingLevel0& _Other) noexcept = delete;
	EndingLevel0& operator=(const EndingLevel0& _Other) = delete;
	EndingLevel0& operator=(EndingLevel0& _Other) noexcept = delete;

protected:

private:

};


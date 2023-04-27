#pragma once
#include <GameEngineCore/GameEngineLevel.h>


class EngineLevel0 : public GameEngineLevel
{
public:
	EngineLevel0();
	~EngineLevel0();

	//
	EngineLevel0(const EngineLevel0& _Other) = delete;
	EngineLevel0(EngineLevel0& _Other) noexcept = delete;
	EngineLevel0& operator=(const EngineLevel0& _Other) = delete;
	EngineLevel0& operator=(EngineLevel0& _Other) noexcept = delete;

protected:

private:

};


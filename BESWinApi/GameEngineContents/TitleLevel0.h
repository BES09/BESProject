#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class TitleLevel0 : public GameEngineLevel
{
public:
	TitleLevel0();
	~TitleLevel0();

	//
	TitleLevel0(const TitleLevel0& _Other) = delete;
	TitleLevel0(TitleLevel0& _Other) noexcept = delete;
	TitleLevel0& operator=(const TitleLevel0& _Other) = delete;
	TitleLevel0& operator=(TitleLevel0& _Other) noexcept = delete;

protected:

private:

};


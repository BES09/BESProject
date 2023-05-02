#pragma once
class GameEngineTime
{
public:
	GameEngineTime();
	~GameEngineTime();

	//
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime& _Other) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) noexcept = delete;

protected:

private:

};


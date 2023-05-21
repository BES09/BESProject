#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class PlayLevel0 : public GameEngineLevel
{
public:
	// constrcuter destructer
	PlayLevel0();
	~PlayLevel0();

	// delete Function
	PlayLevel0(const PlayLevel0& _Other) = delete;
	PlayLevel0(PlayLevel0&& _Other) noexcept = delete;
	PlayLevel0& operator=(const PlayLevel0& _Other) = delete;
	PlayLevel0& operator=(PlayLevel0&& _Other) noexcept = delete;

protected:
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	void Start() override;
	void Update(float _Delta) override;
	void Render() override;
	void Release() override;

	class Player* LevelPlayer = nullptr;
};




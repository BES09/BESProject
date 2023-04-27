#pragma once
class PlayLevel0
{
public:
	PlayLevel0();
	~PlayLevel0();

	//
	PlayLevel0(const PlayLevel0& _Other) = delete;
	PlayLevel0(PlayLevel& _Other) noexcept = delete;
	PlayLevel0& operator=(const PlayLevel0& _Other) = delete;
	PlayLevel0& operator=(const PlayLevel0& _Other) noexcept = delete;

protected:

private:

};


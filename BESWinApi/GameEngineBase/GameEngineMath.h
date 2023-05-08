#pragma once

// 설명 :
class GameEngineMath
{
};

class float4
{
public:
	static const float4 ZERO;

	// 실수는 기본적으로 == 이 거의 불가능하다.
	// 실수를 처히하는 방식이 애초에 정확하지 않기 때문이다.
	// 부동소수점 계산방식은 기본적으로 오차를 가지고 있고
	// + - 등을 할때 여러분들이 생각하는 정확한 값이 나오지 않을 수 있다.
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
	float W = 1.0f;

	inline int iX() const
	{
		return static_cast<int>(X);
	}

	inline int iY() const
	{
		return static_cast<int>(Y);
	}

	inline int ihX() const
	{
		return static_cast<int>(X * 0.5f);
	}

	inline int ihY() const
	{
		return static_cast<int>(Y * 0.5f);
	}

	float4& operator+=(const float4& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		Z += _Other.Z;

		return *this;
	}

};
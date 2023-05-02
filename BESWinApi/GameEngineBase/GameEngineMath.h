#pragma once

// ���� :
class GameEngineMath
{
};

class float4
{
public:
	// �Ǽ��� �⺻������ == �� ���� �Ұ����ϴ�.
	// �Ǽ��� ó���ϴ� ����� ���ʿ� ��Ȯ���� �ʱ� �����̴�.
	// �ε��Ҽ��� ������� �⺻������ ������ ������ �ְ�
	// + - ���� �Ҷ� �����е��� �����ϴ� ��Ȯ�� ���� ������ ���� �� �ִ�.
	float X;
	float Y;
	float Z;
	float W;

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
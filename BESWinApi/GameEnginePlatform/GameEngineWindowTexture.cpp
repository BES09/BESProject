#include "GameEngineWindowTexture.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEngineWindow.h"

#pragma comment(lib, "msimg32.lib")


GameEngineWindowTexture::GameEngineWindowTexture()
{
}

GameEngineWindowTexture::~GameEngineWindowTexture()
{
}

void GameEngineWindowTexture::ResLoad(const std::string& _Path)
{
	// 단순히 비트맵만 로드하는 함수가 아니라서 우리에게 그냥 HANDLE을 준다
	// 선생님 기억으로는 커서 아이콘등도 이녀석으로 로드할수 있었나? 하는데 그래서 

	// LoadBitmapA()

	// LPCSTR == const char*

	HANDLE ImageHandle = LoadImageA(nullptr, _Path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (nullptr == ImageHandle)
	{
		MsgBoxAssert("이미지 로드에 실패했습니다." + _Path);
		return;
	}

	// 이미지의 핸들일 뿐이고.
	BitMap = static_cast<HBITMAP>(ImageHandle);

	// 없던 권한을 새롭게 만들어야 한다.
	// Window에서 얻어온 DC
	ImageDC = CreateCompatibleDC(nullptr);
	// 이미지의 수정 권한을 만들어 내고

	// ImageDC 권한에
	// BitMap 2차원의 색깔 집합을 연결해라.
	// 사실 이미 만들어지자마자 내부에 1,1 이미지와 연결되어있고
	// 내가 로드한 이미지를 그 1,1짜리를 밀어내고 교체하는 작업을 하는데.
	// 이 함수의 리턴값이 기존에 연결되어있던 애를 리턴해주는것.
	OldBitMap = static_cast<HBITMAP>(SelectObject(ImageDC, BitMap));

	ScaleCheck();
}

void GameEngineWindowTexture::ResCreate(const float4& _Scale)
{
	// 그냥 비어있는 흰색 이미지를 하나 만드는 함수인거에요.
	HANDLE ImageHandle = CreateCompatibleBitmap(GameEngineWindow::MainWindow.GetHDC(), _Scale.iX(), _Scale.iY());

	if (nullptr == ImageHandle)
	{
		MsgBoxAssert("이미지 생성에 실패했습니다.");
		return;
	}

	// 이미지의 핸들일 뿐이고.
	BitMap = static_cast<HBITMAP>(ImageHandle);

	// 없던 권한을 새롭게 만들어야 한다.
	// Window에서 얻어온 DC
	ImageDC = CreateCompatibleDC(nullptr);
	// 이미지의 수정 권한을 만들어 내고

	// ImageDC 권한에
	// BitMap 2차원의 색깔 집합을 연결해라.
	// 사실 이미 만들어지자마자 내부에 1,1 이미지와 연결되어있고
	// 내가 로드한 이미지를 그 1,1짜리를 밀어내고 교체하는 작업을 하는데.
	// 이 함수의 리턴값이 기존에 연결되어있던 애를 리턴해주는것.
	OldBitMap = static_cast<HBITMAP>(SelectObject(ImageDC, BitMap));

	ScaleCheck();
}

void GameEngineWindowTexture::ScaleCheck()
{
	GetObject(BitMap, sizeof(BITMAP), &Info);

	BITMAP OldInfo;

	GetObject(OldBitMap, sizeof(BITMAP), &OldInfo);
}

float4 GameEngineWindowTexture::GetScale()
{

	return { static_cast<float>(Info.bmWidth), static_cast<float>(Info.bmHeight) };
}



void GameEngineWindowTexture::BitCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos)
{
	BitCopy(_CopyTexture, _Pos, _CopyTexture->GetScale());
}

void GameEngineWindowTexture::BitCopy(
	GameEngineWindowTexture* _CopyTexture,
	const float4& _Pos,
	const float4& _Scale)
{
	HDC CopyImageDC = _CopyTexture->GetImageDC();

	//// 특정 DC에 연결된 색상을
	//// 특정 DC에 고속복사하는 함수입니다.
	BitBlt(ImageDC,
		_Pos.iX() - _Scale.ihX(),
		_Pos.iY() - _Scale.ihY(),
		_Scale.iX(),
		_Scale.iY(),
		CopyImageDC,
		0,
		0,
		SRCCOPY);

}

void GameEngineWindowTexture::TransCopy(GameEngineWindowTexture* _CopyTexture, const float4& _Pos, const float4& _Scale, const float4& _OtherPos, const float4& _OtherScale, int _TransColor/* = RGB(255, 0, 255)*/)
{
	HDC CopyImageDC = _CopyTexture->GetImageDC();

	//// 특정 DC에 연결된 색상을
	//// 특정 DC에 고속복사하는 함수입니다.
	TransparentBlt(ImageDC,
		_Pos.iX() - _Scale.ihX(),
		_Pos.iY() - _Scale.ihY(),
		_Scale.iX(),
		_Scale.iY(),
		CopyImageDC,
		_OtherPos.iX(), // 카피하려는 이미지의 왼쪽위 x
		_OtherPos.iY(), // 카피하려는 이미지의 왼쪽위 y
		_OtherScale.iX(), // 그부분부터 사이즈  x
		_OtherScale.iY(), // 그부분부터 사이즈  y
		_TransColor
	);

}

unsigned int GameEngineWindowTexture::GetColor(unsigned int _DefaultColor, float4 _Pos)
{
	if (0 > _Pos.iX())
	{
		return _DefaultColor;
	}

	if (0 > _Pos.iY())
	{
		return _DefaultColor;
	}

	if (GetScale().iX() <= _Pos.iX())
	{
		return _DefaultColor;
	}

	if (GetScale().iX() <= _Pos.iY())
	{
		return _DefaultColor;
	}

	return GetPixel(ImageDC, _Pos.iX(), _Pos.iY());
}
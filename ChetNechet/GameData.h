#pragma once
#include "framework.h"
enum WindowsClass
{
	End = -1,
	Main = 0,
	Size = 1,
	Game = 2,
	Win = 3
};

enum CellStaus
{
	clear = 2,
	chet = 0,
	nechet = 1
};
class GameData
{
public:
	int window = 0;
	int nCmdShow = 0;
	int** arr = nullptr;
	wchar_t deltaSTR[15];
	size_t resultFristPlayer = 0;
	size_t resultSecondPlayer = 0;
	size_t count = 0;
	size_t CountResult(bool chet);
	const wchar_t* Winner() const;
	void SetSize(size_t size);
	size_t GetSize();
	LPWSTR Finish(bool chet);
protected:
	void NewArray();
	size_t size = 0;
	void DeleteArray();
	LPWSTR first = LPWSTR(L"Первый игрок  ");
	LPWSTR second = LPWSTR(L"Второй игрок  ");
};


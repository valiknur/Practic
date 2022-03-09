#include "GameData.h"
size_t GameData::CountResult(bool chet)
{
	size_t rowSumm = 0, count = 0;
	for (size_t i = 0; i < size; i++)
	{
		rowSumm = 0;
		for (size_t j = 0; j < size; j++)
		{
			rowSumm += arr[i][j] != 0 ? 1 : 0;
		}
		if (bool(rowSumm % 2) == chet) count++;
	}
    return count;
}

const wchar_t* GameData::Winner() const
{
	if (resultFristPlayer > resultSecondPlayer) return L"1 Игрок победил";
	if (resultFristPlayer < resultSecondPlayer) return L"2 Игрок победил";
	return L"Ничья";
}

void GameData::SetSize(size_t size)
{
	resultFristPlayer = 0;
	resultSecondPlayer = 0;
	count = 0;
	DeleteArray();
	this->size = size;
	NewArray();
}

size_t GameData::GetSize()
{
	return size;
}

LPWSTR GameData::Finish(bool chet)
{
	size_t& T = (chet ? resultSecondPlayer : resultFristPlayer);
	if (chet)
	{
		for (size_t i = 0; i < 16; i++)
		{
			deltaSTR[i] = second[i];
		}
	}
	else
	{
		for (size_t i = 0; i < 16; i++)
		{
			deltaSTR[i] = first[i];
		}
	}
	deltaSTR[13] = (T / 10 != 0? (T / 10) + '0': ' ');
	deltaSTR[14] = T + '0';
	return LPWSTR(deltaSTR);
}

void GameData::NewArray()
{
	if (arr == nullptr)
	{
	arr = new int*[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = new int[size];
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j] = CellStaus::clear;
		}
	}
}

void GameData::DeleteArray()
{
	if (arr != nullptr)
	{
		for (size_t i = 0; i < size; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;
	}
}


#pragma once
#include "UnityWindow.h"
class GameWindow :
    public UnityWindow
{
    HWND staticTextForField;
public:
    void ResetParameters();
    GameWindow(GameData* data);
    PCWSTR  ClassName() const override { return L"Main"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
    void ShowContext() override;
protected:
    bool chet = false;
    void DrawCell(HDC hdc, int x, int y, int state);
};


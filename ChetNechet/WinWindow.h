#pragma once
#include "UnityWindow.h"
class WinWindow :
    public UnityWindow
{
public:
    HWND staticTextForWinner;
    HWND staticTextForNeChet;
    HWND staticTextForChet;
    HWND playButton;
    HWND exitButton;
    WinWindow(GameData* data);
    PCWSTR  ClassName() const override { return L"Main"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
    void ShowContext() override;
};

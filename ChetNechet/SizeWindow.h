#pragma once
#include "UnityWindow.h"
class SizeWindow :
    public UnityWindow
{
    HWND staticTextForField;
    HWND sizeField;
    HWND playButton;
    HWND exitButton;
public:
    SizeWindow(GameData* data);
    PCWSTR  ClassName() const override { return L"Main"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
    void ShowContext() override;
};


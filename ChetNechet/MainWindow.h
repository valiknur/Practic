#pragma once
#include "SizeWindow.h"
#include "UnityWindow.h"
class MainWindow :
    public UnityWindow
{
public:
    MainWindow(GameData* data);
    PCWSTR  ClassName() const override { return L"Main"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
    void ShowContext() override;
    void CreateSizeWindow();
};


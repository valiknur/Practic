#pragma once
#include "BaseWindow.h"
#include "GameData.h"
class UnityWindow : public BaseWindow<UnityWindow>
{
public:
    GameData* data;
    UnityWindow(GameData* data);
    virtual PCWSTR  ClassName() const override { return L"Sample Window Class"; }
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
    virtual void ShowContext();
};


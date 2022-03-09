#include "WinWindow.h"

WinWindow::WinWindow(GameData* data) : UnityWindow(data)
{
    scaleX = 400;
    scaleY = 200;
    zeroPosX = 400;
    zeroPosY = 400;
}

LRESULT WinWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        data->window = End;
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(m_hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(m_hwnd, &ps);
    }
    case WM_COMMAND:
        if (wParam == IDB_Button1)
        {
            data->window = WindowsClass::Size;
            PostQuitMessage(0);
            return 0;
        }
        if (wParam == IDB_Button2)
        {
            data->window = End;
            DestroyWindow(this->m_hwnd);
            PostQuitMessage(0);
            return 0;
        }
    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
    return TRUE;
}

void WinWindow::ShowContext()
{
    staticTextForWinner = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        data->Winner(),      // Button text 
        WS_BORDER | WS_CHILD | WS_VISIBLE | ES_CENTER | ES_AUTOVSCROLL,  // Styles 
        50,         // x position 
        30,         // y position 
        250,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    staticTextForNeChet = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        data->Finish(false),      // Button text 
        WS_BORDER | WS_CHILD | WS_VISIBLE | ES_CENTER | ES_AUTOVSCROLL,  // Styles 
        50,         // x position 
        50,         // y position 
        125,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    staticTextForChet = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        data->Finish(true),      // Button text 
        WS_BORDER | WS_CHILD | WS_VISIBLE | ES_CENTER | ES_AUTOVSCROLL,  // Styles 
        175,         // x position 
        50,         // y position 
        125,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    playButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Реванш",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        50,         // x position 
        80,         // y position 
        100,        // Button width
        30,        // Button height
        this->Window(),     // Parent window
        (HMENU)IDB_Button1,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    exitButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Выход",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        200,         // x position 
        80,         // y position 
        100,        // Button width
        30,        // Button height
        this->Window(),     // Parent window
        (HMENU)IDB_Button2,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);
}

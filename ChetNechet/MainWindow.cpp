#include "MainWindow.h"


MainWindow::MainWindow(GameData* data) : UnityWindow(data)
{
    scaleX = 400;
    scaleY = 200;
    zeroPosX = 400;
    zeroPosY = 400;
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        this->bOn = false;
        data->window = WindowsClass::End;
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
            DestroyWindow(this->m_hwnd);
            PostQuitMessage(0);
            return 0;
        }
    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
    return TRUE;
}

void MainWindow::ShowContext()
{
    HWND staticTextForField = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        L"Игра \"Чёт - нечёт\"",      // Button text 
        WS_CHILD | WS_VISIBLE | ES_CENTER,  // Styles 
        100,         // x position 
        20,         // y position 
        200,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    HWND playButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Старт",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        100,         // x position 
        50,         // y position 
        50,        // Button width
        30,        // Button height
        this->Window(),     // Parent window
        (HMENU)IDB_Button1,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    HWND exitButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Выход",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        250,         // x position 
        50,         // y position 
        50,        // Button width
        30,        // Button height
        this->Window(),     // Parent window
        (HMENU)IDB_Button2,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
}

void MainWindow::CreateSizeWindow()
{
}

#include "SizeWindow.h"

SizeWindow::SizeWindow(GameData* data) : UnityWindow(data)
{
    scaleX = 400;
    scaleY = 200;
    zeroPosX = 400;
    zeroPosY = 400;
}

LRESULT SizeWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        this->bOn = false;
        data->window = WindowsClass::Main;
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
            LPWSTR text = new WCHAR[3];
            Edit_GetText(sizeField, text, 3);
            data->SetSize(min(max(3, _wtoi(text)), 9));
            data->window = WindowsClass::Game;
            delete[] text;
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

void SizeWindow::ShowContext()
{
    staticTextForField = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        L"Введите размер от 3 до 9 здесь",      // Button text 
        WS_BORDER | WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_NUMBER | ES_AUTOVSCROLL,  // Styles 
        100,         // x position 
        30,         // y position 
        200,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    sizeField = CreateWindow(
        L"EDIT",  // Predefined class; Unicode assumed 
        L"",      // Button text 
        WS_BORDER | WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_NUMBER | ES_AUTOVSCROLL,  // Styles 
        100,         // x position 
        50,         // y position 
        200,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    playButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Играть",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        100,         // x position 
        80,         // y position 
        50,        // Button width
        30,        // Button height
        this->Window(),     // Parent window
        (HMENU)IDB_Button1,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
    exitButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Назад",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        250,         // x position 
        80,         // y position 
        50,        // Button width
        30,        // Button height
        this->Window(),     // Parent window
        (HMENU)IDB_Button2,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);
}

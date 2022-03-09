#include "GameWindow.h"

void GameWindow::ResetParameters()
{
    scaleX = data->GetSize() * 50 + 300;
    scaleY = data->GetSize() * 50 + 100;
    zeroPosX = 200;
    zeroPosY = 200;
}

GameWindow::GameWindow(GameData* data) : UnityWindow(data)
{
    
}

LRESULT GameWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
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
        for (size_t i = 0; i < data->GetSize(); i++)
        {
            for (size_t j = 0; j < data->GetSize(); j++)
            {
                DrawCell(hdc, 10 + i * 50, 10 + j * 50, data->arr[i][j]);
            }
        }
        EndPaint(m_hwnd, &ps);
    }
    case WM_LBUTTONDOWN:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        if (x > 10 &&
            y > 10 &&
            x < data->GetSize() * 50 + 10 &&
            y < data->GetSize() * 50 + 10 &&
            data->arr[(x - 10) / 50][(y - 10) / 50] == CellStaus::clear)
        {
            data->count++;

            data->arr[(x - 10) / 50][(y - 10) / 50] = chet ? 0 : 1;

            chet = !chet;
            if (chet) SetWindowText(staticTextForField, L"Ходит Игрок 2");
            else SetWindowText(staticTextForField, L"Ходит Игрок 1");

            RECT updatePlace;
            updatePlace.left = (x - 10) / 50 * 50 + 10;
            updatePlace.right = (x - 10) / 50 * 50 + 50 + 10;
            updatePlace.bottom = (y - 10) / 50 * 50 + 10;
            updatePlace.top = (y - 10) / 50 * 50 + 50 + 10;
            InvalidateRect(m_hwnd, &updatePlace, FALSE);

            if (data->count == data->GetSize() * data->GetSize())
            {
                int delta = 0;
                for (size_t i = 0; i < data->GetSize(); i++)
                {
                    delta = 0;
                    for (size_t j = 0; j < data->GetSize(); j++)
                    {
                        delta += data->arr[i][j];
                    }
                    if (delta % 2 == 0) data->resultSecondPlayer++;
                    else data->resultFristPlayer++;
                }
                data->window = WindowsClass::Win;
                PostQuitMessage(0);
                return 0;
            }
        }
    }
    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
    return TRUE;
}

void GameWindow::ShowContext()
{
    
    staticTextForField = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        L"Ходит Игрок 1",      // Button text 
        WS_BORDER | WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_LEFT | ES_AUTOVSCROLL,  // Styles 
        50 + data->GetSize() * 50,         // x position 
        30,         // y position 
        130,        // Button width
        20,        // Button height
        this->Window(),     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(this->Window(), GWLP_HINSTANCE),
        NULL);      // Pointer not needed.
}

void GameWindow::DrawCell(HDC hdc, int x, int y, int state)
{
    for (size_t i = x; i <= x + 50; i++)
    {
        SetPixel(hdc, i, y, RGB(128, 128, 128));
    }
    for (size_t i = y; i <= y + 50; i++)
    {
        SetPixel(hdc, x, i, RGB(128, 128, 128));
    }
    for (size_t i = x; i <= x + 50; i++)
    {
        SetPixel(hdc, i, y + 50, RGB(128, 128, 128));
    }
    for (size_t i = y; i <= y + 50; i++)
    {
        SetPixel(hdc, x + 50, i, RGB(128, 128, 128));
    }
    for (size_t i = x + 1; i < x + 50; i++)
    {
        for (size_t j = y + 1; j < y + 50; j++)
        {
            SetPixel(hdc, i, j, RGB(192, 192, 192));
        }
    }
    switch (state)
    {
    case CellStaus::clear:
        break;
    case CellStaus::nechet:
        for (size_t i = x + 24; i < x + 27; i++)
        {
            for (size_t j = y + 1; j < y + 50; j++)
            {
                SetPixel(hdc, i, j, RGB(0, 0, 0));
            }
        }
        break;
    case CellStaus::chet:
        for (size_t i = x+22; i <= x + 29; i++)
        {
            SetPixel(hdc, i, y+1, RGB(128, 128, 128));
        }
        for (size_t i = y+1; i < y + 50; i++)
        {
            SetPixel(hdc, x+22, i, RGB(128, 128, 128));
        }
        for (size_t i = x+22; i <= x + 29; i++)
        {
            SetPixel(hdc, i, y + 49, RGB(128, 128, 128));
        }
        for (size_t i = y+1; i < y + 50; i++)
        {
            SetPixel(hdc, x + 29, i, RGB(128, 128, 128));
        }
        break;
    default:
        break;
    }
}

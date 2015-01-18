#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

#include "domino.h"
#include "half_domino.h"
#include "painter.h"

const wchar_t g_szClassName[] = L"myWindowClass";

const int CONST_WIN_HEIGHT = 900;
const int CONST_WIN_WIDTH = 1400;

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

  srand(time(NULL));

  static Domino dominos[7] = {
    Domino(200, 100, RGB(30, 30, 30), 4, 3),
    Domino(200, 100, RGB(30, 30, 30), 0, 2),
    Domino(200, 100, RGB(30, 30, 30), 5, 6),
    Domino(200, 100, RGB(rand() % 256, rand() % 256, rand() % 256), 2, 5),
    Domino(200, 100, RGB(30, 30, 30), 1, 4),     
    Domino(200, 100, RGB(60, 60, 60), 3, 1),
    Domino(200, 100, RGB(50, 50, 50), 6, 2)
  };

  HDC hDC;
  PAINTSTRUCT Ps;

  switch (msg)
  {
  case WM_PAINT: {
    hDC = BeginPaint(hwnd, &Ps);
    PaintDominos(hDC, dominos);
    EndPaint(hwnd, &Ps);
  }
                 break;
  case WM_CLOSE:
    DestroyWindow(hwnd);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_CHAR:
    if (wParam == 'r') {
      for (int i = 0; i < 7; ++i) {
        dominos[i].set_domino_color(RGB(rand() % 256, rand() % 256, rand() % 256));
      }
    }
    InvalidateRect(hwnd, NULL, true);
    break;
  default:
    return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow)
{
  WNDCLASSEX wc;
  HWND hwnd;
  MSG Msg;

  //Step 1: Registering the Window Class
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = 0;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wc.lpszMenuName = NULL;
  wc.lpszClassName = g_szClassName;
  wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

  if (!RegisterClassEx(&wc))
  {
    MessageBox(NULL, L"Window Registration Failed!", L"Error!",
      MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  // Step 2: Creating the Window
  hwnd = CreateWindowEx(
    WS_EX_CLIENTEDGE,
    g_szClassName,
    L"Scott Burnette",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, CONST_WIN_WIDTH, CONST_WIN_HEIGHT,
    NULL, NULL, hInstance, NULL);

  if (hwnd == NULL)
  {
    MessageBox(NULL, L"Window Creation Failed!", L"Error!",
      MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  // Step 3: The Message Loop
  while (GetMessage(&Msg, NULL, 0, 0) > 0)
  {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }
  return Msg.wParam;
}
/*#include <windows.h>
#include <string>
using namespace std;

//http://www.winprog.org/tutorial/simple_window.html

const wchar_t g_szClassName[] = L"myWindowClass";


void line(HDC hdc, int x1, int y1, int x2, int y2)
{
  MoveToEx(hdc, x1, y1, NULL);
  LineTo(hdc, x2, y2);
}




// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HDC hDC;            // handle to the device context (permission to draw)
  PAINTSTRUCT Ps;     // a variable that you need
  HPEN hRedPen;       // the handle to the red pen
  HBRUSH hMainBrush;  // the handle to the main brush
  HFONT hFont;        // the handle to the font
  int fontHeight;
  RECT rect;

  static int red = 200;
  static int green = 0;
  static int blue = 90;

  static int x = 320;
  static int y = 240;
  static double radius = 50;

  static bool isEllipse = true;

  switch (msg)
  {
  case WM_PAINT:
    hDC = BeginPaint(hwnd, &Ps);
    //Create a red pen
    hRedPen = CreatePen(PS_SOLID, 25, RGB(red, green, blue));
    //Create the brush
    hMainBrush = CreateSolidBrush(RGB(200, 0, 200));
    fontHeight = 35;
    hFont = CreateFont(fontHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");

    SelectObject(hDC, hRedPen);
    SelectObject(hDC, hMainBrush);
    SelectObject(hDC, hFont);

    if (isEllipse)
    {
      Ellipse(hDC, x - (int)radius, y - (int)radius, x + (int)radius, y + (int)radius);
    }
    else
    {
      Rectangle(hDC, x - (int)radius, y - (int)radius, x + (int)radius, y + (int)radius);
    }


    // draw a line using a function called line (see top of this file)

    line(hDC, 400, 50, 500, 350);


    // Draw some text

    //int i will be 10,20 and 30
    for (int i = 10; i <= 30; i += 10)
    {
      rect.top = 300 + 3 * i;
      rect.bottom = 500 + 3 * i;
      rect.left = 50;
      rect.right = 400;

      //remember to add "#include <string>" at the top of this file 
      //remember to add "using namespace std" at the top of this file 

      // Convert i to a string and imbed it in the wstring displayString. (Thanks Michael!)

      wstring displayString = L"Hello " + to_wstring(i) + L" Windows!";

      // Convert the C++ wstring to old fashion C style double byte string and display it.  

      DrawText(hDC, displayString.c_str(), -1, &rect, DT_CENTER | DT_WORDBREAK);          //Centered
      //DrawText(hDC,displayString.c_str(),-1,&rect, DT_WORDBREAK);                   //Non-centered
    }



    DeleteObject(hMainBrush);
    DeleteObject(hRedPen);

    EndPaint(hwnd, &Ps);
    break;
  case WM_CHAR:
    if (wParam == 'e')
    {
      isEllipse = true;
    }
    else if (wParam == 'r')
    {
      isEllipse = false;
    }
    else if (wParam == 'c')
    {
      red = rand() % 256;
      green = rand() % 256;
      blue = rand() % 256;
    }

    InvalidateRect(hwnd, NULL, true);
    break;
  case WM_KEYDOWN:
    if (wParam == VK_RIGHT)
    {
      x += 10;
    }
    else if (wParam == VK_LEFT)
    {
      x -= 10;
    }
    else if (wParam == VK_UP)
    {
      y -= 10;
    }
    else if (wParam == VK_DOWN)
    {
      y += 10;
    }
    else if (wParam == VK_PRIOR)
    {
      radius *= 1.1;

    }
    else if (wParam == VK_NEXT)
    {
      radius *= 0.9;
    }

    InvalidateRect(hwnd, NULL, true);
    break;
  case WM_CLOSE:
    DestroyWindow(hwnd);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
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
    L"My Dumb Window",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
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
}*/
# CreateHatchBrush function

## Description

The **CreateHatchBrush** function creates a logical brush that has the specified hatch pattern and color.

## Parameters

### `iHatch` [in]

The [hatch style of the brush](https://learn.microsoft.com/windows/desktop/gdi/hatch-brush). This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **HS_BDIAGONAL** | 45-degree upward left-to-right hatch |
| **HS_CROSS** | Horizontal and vertical crosshatch |
| **HS_DIAGCROSS** | 45-degree crosshatch |
| **HS_FDIAGONAL** | 45-degree downward left-to-right hatch |
| **HS_HORIZONTAL** | Horizontal hatch |
| **HS_VERTICAL** | Vertical hatch |

### `color` [in]

The foreground color of the brush that is used for the hatches. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value identifies a logical brush.

If the function fails, the return value is **NULL**.

## Remarks

A brush is a bitmap that the system uses to paint the interiors of filled shapes.

After an application creates a brush by calling **CreateHatchBrush**, it can select that brush into any device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function. It can also call [SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode) to affect the rendering of the brush.

If an application uses a hatch brush to fill the backgrounds of both a parent and a child window with matching color, you must set the brush origin before painting the background of the child window. You can do this by calling the [SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex) function. Your application can retrieve the current brush origin by calling the [GetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbrushorgex) function.

When you no longer need the brush, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

**ICM:** No color is defined at brush creation. However, color management is performed when the brush is selected into an ICM-enabled device context.

#### Examples

The following example creates a logical brush that has the specified hatch pattern and color. You can also set a hatch brush background to transparent or to opaque.

```cpp

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <stddef.h>

#include <gdiplus.h>
#include <assert.h>

using namespace Gdiplus;

// Reference to the GDI+ static library).
#pragma comment (lib,"Gdiplus.lib")

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Win32 Application Hatch Brush");

HINSTANCE hInst;

#define BTN_MYBUTTON_ID_1    503
#define BTN_MYBUTTON_ID_2    504

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(hPrevInstance);

    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    hInst = hInstance; // Store instance handle in our global variable

    // The parameters to CreateWindow:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        1000, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    // Create button controls.
    CreateWindowEx(NULL, L"BUTTON", L"Transparent", WS_VISIBLE | WS_CHILD,
        35, 35, 120, 20, hWnd, (HMENU)BTN_MYBUTTON_ID_1, NULL, NULL);

    CreateWindowEx(NULL, L"BUTTON", L"Opaque", WS_VISIBLE | WS_CHILD,
        35, 65, 120, 20, hWnd, (HMENU)BTN_MYBUTTON_ID_2, NULL, NULL);

    // The parameters to ShowWindow:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

/***
 *    This function creates the following rectangles:
 *        1.    An outer rectangle using a solid brush with blue background.
 *        2.    An inner rectangle using a hatch brush with red horizontal lines and yellow background.
 *    It makes the background of the inner rectangle transparent or opaque in function of the user's input.
 *    Inputs:
 *        1.    hdc, the display device context.
 *        2.    transparent, the hatch brush background user's value; true if transparent, false if opaque.
 ***/
VOID SetHatchBrushBackground(HDC hdc, bool transparent)
{
    // Define a brush handle.
    HBRUSH hBrush;

    // Create a solid blue brush.
    hBrush = CreateSolidBrush (RGB(0, 0, 255));

    // Associate the brush with the display device context.
    SelectObject (hdc, hBrush);

    // Draw a rectangle with blue background.
    Rectangle (hdc,  400,40,800,400);

    // Create a hatch brush that draws horizontal red lines.
    hBrush = CreateHatchBrush(HatchStyleHorizontal, RGB(255, 0, 0));

    // Set the background color to yellow.
    SetBkColor(hdc, RGB(255, 255, 0));

    // Select the hatch brush background transparency based on user's input.
    if (transparent == true)
        // Make the hatch brush background transparent.
        // This displays the outer rectangle blue background.
        SetBkMode(hdc, TRANSPARENT);
    else
        // Make the hatch brush background opaque.
        // This displays the inner rectangle yellow background.
        SetBkMode(hdc, OPAQUE);

    // Associate the hatch brush with the current device context.
    SelectObject(hdc, hBrush);

    // Draw a rectangle with the specified hatch brush.
    Rectangle(hdc,  500,130,700,300);

}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Select your brush background.");
    TCHAR wmId;
    TCHAR wmEvent;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        // Start application-specific layout section.
        // Just print the greeting string in the top left corner.
        TextOut(hdc,
            5, 5,
            greeting, (int)_tcslen(greeting));
        // End application-specific layout section.

        // Draw rectangles using hatch brush.
        SetHatchBrushBackground(hdc, true);

        EndPaint(hWnd, &ps);
        break;

    case WM_COMMAND:
        wmId    = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        hdc = GetDC(hWnd);

        switch (wmId) {

            case BTN_MYBUTTON_ID_1:
                // Draw the inner rectangle using a hatch brush transparent background.
                SetHatchBrushBackground(hdc, true);
                MessageBox(hWnd, _T("Hatch brush background is TRANSPARENT"), _T("Information"), MB_OK);
                break;

            case BTN_MYBUTTON_ID_2:
                // Draw the inner rectangle using a hatch brush opaque background.
                SetHatchBrushBackground(hdc, false);
                MessageBox(hWnd, _T("Hatch brush background is OPAQUE"), _T("Information"), MB_OK);
                break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}

```

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[CreateDIBPatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrush)

[CreateDIBPatternBrushPt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibpatternbrushpt)

[CreatePatternBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpatternbrush)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbrushorgex)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)
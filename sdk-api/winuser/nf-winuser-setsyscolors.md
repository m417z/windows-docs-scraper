# SetSysColors function

## Description

Sets the colors for the specified display elements. Display elements are the various parts of a window and the display that appear on the system display screen.

## Parameters

### `cElements` [in]

Type: **int**

The number of display elements in the *lpaElements* array.

### `lpaElements` [in]

Type: **const INT***

An array of integers that specify the display elements to be changed. For a list of display elements, see
[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor).

### `lpaRgbValues` [in]

Type: **const COLORREF***

An array of
[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) values that contain the new red, green, blue (RGB) color values for the display elements in the array pointed to by the *lpaElements* parameter.

To generate a
[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the
[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SetSysColors** function sends a
[WM_SYSCOLORCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-syscolorchange) message to all windows to inform them of the change in color. It also directs the system to repaint the affected portions of all currently visible windows.

It is best to respect the color settings specified by the user. If you are writing an application to enable the user to change the colors, then it is appropriate to use this function. However, this
function affects only the current session. The new colors are not saved when the system terminates.

#### Examples

The following example demonstrates the use of the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) and **SetSysColors** functions. First, the example uses **GetSysColor** to retrieve the colors of the window background and active caption and displays the red, green, blue (RGB) values in hexadecimal notation. Next, example uses **SetSysColors** to change the color of the window background to light gray and the active title bars to dark purple. After a 10-second delay, the example restores the previous colors for these elements using [SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors).

```
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

void main()
{
    int aElements[2] = {COLOR_WINDOW, COLOR_ACTIVECAPTION};
    DWORD aOldColors[2];
    DWORD aNewColors[2];

    // Get the current color of the window background.

    aOldColors[0] = GetSysColor(aElements[0]);

    printf("Current window color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aOldColors[0]),
        GetGValue(aOldColors[0]),
        GetBValue(aOldColors[0]));

    // Get the current color of the active caption.

    aOldColors[1] = GetSysColor(aElements[1]);

    printf("Current active caption color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aOldColors[1]),
        GetGValue(aOldColors[1]),
        GetBValue(aOldColors[1]));

    // Define new colors for the elements

    aNewColors[0] = RGB(0x80, 0x80, 0x80);  // light gray
    aNewColors[1] = RGB(0x80, 0x00, 0x80);  // dark purple

    printf("\nNew window color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aNewColors[0]),
        GetGValue(aNewColors[0]),
        GetBValue(aNewColors[0]));

    printf("New active caption color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aNewColors[1]),
        GetGValue(aNewColors[1]),
        GetBValue(aNewColors[1]));

    // Set the elements defined in aElements to the colors defined
    // in aNewColors

    SetSysColors(2, aElements, aNewColors);

    printf("\nWindow background and active border have been changed.\n");
    printf("Reverting to previous colors in 10 seconds...\n");

    Sleep(10000);

    // Restore the elements to their original colors

    SetSysColors(2, aElements, aOldColors);
}
```

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)
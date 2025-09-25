# MenuHelp function

## Description

Processes [WM_MENUSELECT](https://learn.microsoft.com/windows/desktop/menurc/wm-menuselect) and [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages and displays Help text about the current menu in the specified status window.

## Parameters

### `uMsg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Message being processed. This can be either [WM_MENUSELECT](https://learn.microsoft.com/windows/desktop/menurc/wm-menuselect) or [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command).

### `wParam`

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

wParam of the message specified in
*uMsg*.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

lParam of the message specified in
*uMsg*.

### `hMainMenu`

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the application's main menu.

### `hInst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the module that contains the string resources.

### `hwndStatus`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the status window.

### `lpwIDs`

Type: **LPUINT**

Pointer to an array of values that contains pairs of string resource identifiers and menu handles. The function searches the array for the handle to the selected menu and, if found, uses the corresponding resource identifier to load the appropriate Help string.

## Remarks

The **MenuHelp** function is a helper function. Helper functions are available as a convenience to programming. They combine into one call a sequence of frequently used calls. You use **MenuHelp** to send [WM_MENUSELECT](https://learn.microsoft.com/windows/desktop/menurc/wm-menuselect) and [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages.
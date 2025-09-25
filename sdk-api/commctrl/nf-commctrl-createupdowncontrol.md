# CreateUpDownControl function

## Description

Creates an up-down control.
Note: This function is obsolete. It is a 16 bit function and cannot handle 32 bit values for range and position.

## Parameters

### `dwStyle`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Window styles for the control. This parameter should include the [WS_CHILD](https://learn.microsoft.com/windows/desktop/winmsg/window-styles), [WS_BORDER](https://learn.microsoft.com/windows/desktop/winmsg/window-styles), and [WS_VISIBLE](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) styles, and it may include any of the window styles specific to the up-down control.

### `x`

Type: **int**

Horizontal coordinate, in client coordinates, of the upper-left corner of the control.

### `y`

Type: **int**

Vertical coordinate, in client coordinates, of the upper-left corner of the control.

### `cx`

Type: **int**

Width, in pixels, of the up-down control.

### `cy`

Type: **int**

Height, in pixels, of the up-down control.

### `hParent`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the parent window of the up-down control.

### `nID`

Type: **int**

Identifier for the up-down control.

### `hInst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the module instance of the application creating the up-down control.

### `hBuddy`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the window associated with the up-down control. If this parameter is **NULL**, the control has no buddy window.

### `nUpper`

Type: **int**

Upper limit (range) of the up-down control.

### `nLower`

Type: **int**

Lower limit (range) of the up-down control.

### `nPos`

Type: **int**

Position of the control.

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is the window handle to the up-down control. If the function fails, the return value is **NULL**.
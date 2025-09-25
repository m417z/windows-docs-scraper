# WINDOWINFO structure

## Description

Contains window information.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. The caller must set this member to `sizeof(WINDOWINFO)`.

### `rcWindow`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The coordinates of the window.

### `rcClient`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The coordinates of the client area.

### `dwStyle`

Type: **DWORD**

The window styles. For a table of window styles, see [Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles).

### `dwExStyle`

Type: **DWORD**

The extended window styles. For a table of extended window styles, see [Extended Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

### `dwWindowStatus`

Type: **DWORD**

The window status. If this member is **WS_ACTIVECAPTION** (0x0001), the window is active. Otherwise, this member is zero.

### `cxWindowBorders`

Type: **UINT**

The width of the window border, in pixels.

### `cyWindowBorders`

Type: **UINT**

The height of the window border, in pixels.

### `atomWindowType`

Type: **ATOM**

The window class atom (see [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)).

### `wCreatorVersion`

Type: **WORD**

The Windows version of the application that created the window.

## See also

**Conceptual**

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[GetWindowInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowinfo)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
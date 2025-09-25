# TileWindows function

## Description

Tiles the specified child windows of the specified parent window.

## Parameters

### `hwndParent` [in, optional]

Type: **HWND**

A handle to the parent window. If this parameter is **NULL**, the desktop window is assumed.

### `wHow` [in]

Type: **UINT**

The tiling flags. This parameter can be one of the following values—optionally combined with **MDITILE_SKIPDISABLED** to prevent disabled MDI child windows from being tiled.

| Value | Meaning |
| --- | --- |
| **MDITILE_HORIZONTAL**<br><br>0x0001 | Tiles windows horizontally. |
| **MDITILE_VERTICAL**<br><br>0x0000 | Tiles windows vertically. |

### `lpRect` [in, optional]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a structure that specifies the rectangular area, in client coordinates, within which the windows are arranged. If this parameter is **NULL**, the client area of the parent window is used.

### `cKids` [in]

Type: **UINT**

The number of elements in the array specified by the *lpKids* parameter. This parameter is ignored if *lpKids* is **NULL**.

### `lpKids` [in, optional]

Type: **const HWND***

An array of handles to the child windows to arrange. If a specified child window is a top-level window with the style **WS_EX_TOPMOST** or **WS_EX_TOOLWINDOW**, the child window is not arranged. If this parameter is **NULL**, all child windows of the specified parent window (or of the desktop window) are arranged.

## Return value

Type: **WORD**

If the function succeeds, the return value is the number of windows arranged.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Calling **TileWindows** causes all maximized windows to be restored to their previous size.

## See also

[CascadeWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-cascadewindows)

**Conceptual**

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
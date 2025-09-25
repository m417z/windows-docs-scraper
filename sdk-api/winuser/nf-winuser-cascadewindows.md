# CascadeWindows function

## Description

Cascades the specified child windows of the specified parent window.

## Parameters

### `hwndParent` [in, optional]

Type: **HWND**

A handle to the parent window. If this parameter is **NULL**, the desktop window is assumed.

### `wHow` [in]

Type: **UINT**

A cascade flag. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MDITILE_SKIPDISABLED**<br><br>0x0002 | Prevents disabled MDI child windows from being cascaded. |
| **MDITILE_ZORDER**<br><br>0x0004 | Arranges the windows in Z order. If this value is not specified, the windows are arranged using the order specified in the *lpKids* array. |

### `lpRect` [in, optional]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a structure that specifies the rectangular area, in client coordinates, within which the windows are arranged. This parameter can be **NULL**, in which case the client area of the parent window is used.

### `cKids` [in]

Type: **UINT**

The number of elements in the array specified by the
*lpKids* parameter. This parameter is ignored if *lpKids* is **NULL**.

### `lpKids` [in, optional]

Type: **const HWND***

An array of handles to the child windows to arrange. If a specified child window is a top-level window with the style **WS_EX_TOPMOST** or **WS_EX_TOOLWINDOW**, the child window is not arranged. If this parameter is **NULL**, all child windows of the specified parent window (or of the desktop window) are arranged.

## Return value

Type: **WORD**

If the function succeeds, the return value is the number of windows arranged.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

By default, **CascadeWindows** arranges the windows in the order provided by the *lpKids* array, but preserves the [Z-Order](https://learn.microsoft.com/windows/desktop/winmsg/window-features). If you specify the **MDITILE_ZORDER** flag, **CascadeWindows** arranges the windows in Z order.

Calling **CascadeWindows** causes all maximized windows to be restored to their previous size.

## See also

[Windows Overview](https://learn.microsoft.com/windows/desktop/winmsg/windows)
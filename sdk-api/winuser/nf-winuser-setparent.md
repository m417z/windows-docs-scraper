# SetParent function

## Description

Changes the parent window of the specified child window.

## Parameters

### `hWndChild` [in]

Type: **HWND**

A handle to the child window.

### `hWndNewParent` [in, optional]

Type: **HWND**

A handle to the new parent window. If this parameter is **NULL**, the desktop window becomes the new parent window.
If this parameter is **HWND_MESSAGE**, the child window becomes a [message-only window](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

## Return value

Type: **HWND**

If the function succeeds, the return value is a handle to the previous parent window.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application can use the **SetParent** function to set the parent window of a pop-up, overlapped, or child window.

If the window identified by the *hWndChild* parameter is visible, the system performs the appropriate redrawing and repainting.

For compatibility reasons, **SetParent** does not modify the **WS_CHILD** or **WS_POPUP** window styles of the window whose parent is being changed. Therefore, if *hWndNewParent* is **NULL**, you should also clear the **WS_CHILD** bit and set the **WS_POPUP** style after calling **SetParent**. Conversely, if *hWndNewParent* is not **NULL** and the window was previously a child of the desktop, you should clear the **WS_POPUP** style and set the **WS_CHILD** style before calling **SetParent**.

 When you change the parent of a window, you should synchronize the UISTATE of both windows. For more information, see [WM_CHANGEUISTATE](https://learn.microsoft.com/windows/desktop/menurc/wm-changeuistate) and [WM_UPDATEUISTATE](https://learn.microsoft.com/windows/desktop/menurc/wm-updateuistate).

Unexpected behavior or errors may occur if *hWndNewParent* and *hWndChild* are running in different DPI awareness modes. The table below outlines this behavior:

| Operation | Windows 8.1 | Windows 10 (1607 and earlier) | Windows 10 (1703 and later) |
| --- | --- | --- | --- |
| SetParent (In-Proc) | N/A | **Forced reset** (of current process) | **Fail** (ERROR_INVALID_STATE) |
| SetParent (Cross-Proc) | **Forced reset** (of child window's process) | **Forced reset** (of child window's process) | **Forced reset** (of child window's process) |

 For more information on DPI awareness, see [the Windows High DPI documentation.](https://learn.microsoft.com/windows/desktop/hidpi/high-dpi-desktop-application-development-on-windows)

## See also

**Conceptual**

[GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
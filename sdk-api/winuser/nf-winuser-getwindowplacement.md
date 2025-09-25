# GetWindowPlacement function

## Description

Retrieves the show state and the restored, minimized, and maximized positions of the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `lpwndpl` [in, out]

Type: **[WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement)***

A pointer to the [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) structure that receives the show state and position information. Before calling **GetWindowPlacement**, set the **length** member to `sizeof(WINDOWPLACEMENT)`. **GetWindowPlacement** fails if *lpwndpl*-> *length* is not set correctly.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **flags** member of [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) retrieved by this function is always zero. If the window identified by the *hWnd* parameter is maximized, the **showCmd** member is SW_SHOWMAXIMIZED. If the window is minimized, **showCmd** is SW_SHOWMINIMIZED. Otherwise, it is SW_SHOWNORMAL.

The **length** member of [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) must be set to sizeof(**WINDOWPLACEMENT**). If this member is not set correctly, the function returns **FALSE**. For additional remarks on the proper use of window placement coordinates, see **WINDOWPLACEMENT**.

## See also

**Conceptual**

**Reference**

[SetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowplacement)

[WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
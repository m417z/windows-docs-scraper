# SetWindowPlacement function

## Description

Sets the show state and the restored, minimized, and maximized positions of the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `lpwndpl` [in]

Type: **const [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement)***

A pointer to a [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) structure that specifies the new show state and window positions.

 Before calling **SetWindowPlacement**, set the **length** member of the [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) structure to sizeof(**WINDOWPLACEMENT**). **SetWindowPlacement** fails if the **length** member is not set correctly.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the information specified in [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) would result in a window that is completely off the screen, the system will automatically adjust the coordinates so that the window is visible, taking into account changes in screen resolution and multiple monitor configuration.

The **length** member of [WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement) must be set to `sizeof(WINDOWPLACEMENT)`. If this member is not set correctly, the function returns **FALSE**. For additional remarks on the proper use of window placement coordinates, see **WINDOWPLACEMENT**.

## See also

**Conceptual**

[GetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowplacement)

**Reference**

[WINDOWPLACEMENT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowplacement)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
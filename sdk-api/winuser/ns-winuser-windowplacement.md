# WINDOWPLACEMENT structure

## Description

Contains information about the placement of a window on the screen.

## Members

### `length`

Type: **UINT**

The length of the structure, in bytes. Before calling the [GetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowplacement) or [SetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowplacement) functions, set this member to `sizeof(WINDOWPLACEMENT)`.

[GetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowplacement) and [SetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowplacement) fail if this member is not set correctly.

### `flags`

Type: **UINT**

The flags that control the position of the minimized window and the method by which the window is restored. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WPF_ASYNCWINDOWPLACEMENT**<br><br>0x0004 | If the calling thread and the thread that owns the window are attached to different input queues, the system posts the request to the thread that owns the window. This prevents the calling thread from blocking its execution while other threads process the request. |
| **WPF_RESTORETOMAXIMIZED**<br><br>0x0002 | The restored window will be maximized, regardless of whether it was maximized before it was minimized. This setting is only valid the next time the window is restored. It does not change the default restoration behavior.<br><br>This flag is only valid when the **SW_SHOWMINIMIZED** value is specified for the **showCmd** member. |
| **WPF_SETMINPOSITION**<br><br>0x0001 | The coordinates of the minimized window may be specified.<br><br>This flag must be specified if the coordinates are set in the **ptMinPosition** member. |

### `showCmd`

Type: **UINT**

The current show state of the window. It can be any of the values that can be specified in the *nCmdShow* parameter for the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

### `ptMinPosition`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The coordinates of the window's upper-left corner when the window is minimized.

### `ptMaxPosition`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The coordinates of the window's upper-left corner when the window is maximized.

### `rcNormalPosition`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The window's coordinates when the window is in the restored position.

### `rcDevice`

## Remarks

If the window is a top-level window that does not have the **WS_EX_TOOLWINDOW** window style, then the coordinates represented by the following members are in workspace coordinates: **ptMinPosition**, **ptMaxPosition**, and **rcNormalPosition**. Otherwise, these members are in screen coordinates.

Workspace coordinates differ from screen coordinates in that they take the locations and sizes of application toolbars (including the taskbar) into account. Workspace coordinate (0,0) is the upper-left corner of the workspace area, the area of the screen not being used by application toolbars.

The coordinates used in a **WINDOWPLACEMENT** structure should be used only by the [GetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowplacement) and [SetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowplacement) functions. Passing workspace coordinates to functions which expect screen coordinates (such as [SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)) will result in the window appearing in the wrong location. For example, if the taskbar is at the top of the screen, saving window coordinates using **GetWindowPlacement** and restoring them using **SetWindowPos** causes the window to appear to "creep" up the screen.

## See also

**Conceptual**

[GetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowplacement)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[SetWindowPlacement](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowplacement)

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
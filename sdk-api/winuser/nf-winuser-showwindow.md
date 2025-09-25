# ShowWindow function

## Description

Sets the specified window's show state.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `nCmdShow` [in]

Type: **int**

Controls how the window is to be shown. This parameter is ignored the first time an application calls **ShowWindow**, if the program that launched the application provides a [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure. Otherwise, the first time **ShowWindow** is called, the value should be the value obtained by the [WinMain](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-winmain) function in its *nCmdShow* parameter. In subsequent calls, this parameter can be one of the following values.

| Value | Meaning |
|-------|---------|
| **SW\_HIDE**<br>0 | Hides the window and activates another window. |
| **SW\_SHOWNORMAL**<br>**SW\_NORMAL**<br>1 | Activates and displays a window. If the window is minimized, maximized, or arranged, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time. |
| **SW\_SHOWMINIMIZED**<br>2 | Activates the window and displays it as a minimized window. |
| **SW\_SHOWMAXIMIZED**<br>**SW\_MAXIMIZE**<br>3 | Activates the window and displays it as a maximized window. |
| **SW\_SHOWNOACTIVATE**<br>4 | Displays a window in its most recent size and position. This value is similar to **SW_SHOWNORMAL**, except that the window is not activated. |
| **SW\_SHOW**<br>5 | Activates the window and displays it in its current size and position. |
| **SW\_MINIMIZE**<br>6 | Minimizes the specified window and activates the next top-level window in the Z order. |
| **SW\_SHOWMINNOACTIVE**<br>7 | Displays the window as a minimized window. This value is similar to **SW_SHOWMINIMIZED**, except the window is not activated. |
| **SW\_SHOWNA**<br>8 | Displays the window in its current size and position. This value is similar to **SW\_SHOW**, except that the window is not activated. |
| **SW\_RESTORE**<br>9 | Activates and displays the window. If the window is minimized, maximized, or arranged, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window. |
| **SW\_SHOWDEFAULT**<br>10 | Sets the show state based on the **SW\_** value specified in the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure passed to the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function by the program that started the application. |
| **SW\_FORCEMINIMIZE**<br>11 | Minimizes a window, even if the thread that owns the window is not responding. This flag should only be used when minimizing windows from a different thread. |

## Return value

Type: **BOOL**

If the window was previously visible, the return value is nonzero.

If the window was previously hidden, the return value is zero.

## Remarks

To perform certain special effects when showing or hiding a window, use [AnimateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-animatewindow).

The first time an application calls **ShowWindow**, it should use the [WinMain](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-winmain) function's *nCmdShow* parameter as its *nCmdShow* parameter. Subsequent calls to **ShowWindow** must use one of the values in the given list, instead of the one specified by the **WinMain** function's *nCmdShow* parameter.

As noted in the discussion of the *nCmdShow* parameter, the *nCmdShow* value is ignored in the first call to **ShowWindow** if the program that launched the application specifies startup information in the structure. In this case, **ShowWindow** uses the information specified in the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure to show the window. On subsequent calls, the application must call **ShowWindow** with *nCmdShow* set to **SW_SHOWDEFAULT** to use the startup information provided by the program that launched the application. This behavior is designed for the following situations:

* Applications create their main window by calling [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) with the **WS_VISIBLE** flag set.
* Applications create their main window by calling [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) with the **WS_VISIBLE** flag cleared, and later call **ShowWindow** with the **SW_SHOW** flag set to make it visible.

#### Examples

For an example, see [Creating a Main Window](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

## See also

[AnimateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-animatewindow)

**Conceptual**

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

**Other Resources**

**Reference**

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)

[ShowOwnedPopups](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showownedpopups)

[ShowWindowAsync](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindowasync)

[WinMain](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-winmain)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
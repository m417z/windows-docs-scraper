# EndDeferWindowPos function

## Description

Simultaneously updates the position and size of one or more windows in a single screen-refreshing cycle.

## Parameters

### `hWinPosInfo` [in]

Type: **HDWP**

A handle to a multiple-window
– position structure that contains size and position information for one or more windows. This internal structure is returned by the [BeginDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-begindeferwindowpos) function or by the most recent call to the [DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **EndDeferWindowPos** function sends the [WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging) and [WM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanged) messages to each window identified in the internal structure.

## See also

[BeginDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-begindeferwindowpos)

**Conceptual**

[DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos)

**Reference**

[WM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanged)

[WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
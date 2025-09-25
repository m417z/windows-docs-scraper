# LockSetForegroundWindow function

## Description

The foreground process can call the **LockSetForegroundWindow** function to disable calls to the [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) function.

## Parameters

### `uLockCode` [in]

Type: **UINT**

Specifies whether to enable or disable calls to [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow). This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LSFW_LOCK**<br><br>1 | Disables calls to [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow). |
| **LSFW_UNLOCK**<br><br>2 | Enables calls to [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow). |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system automatically enables calls to [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) if the user presses the ALT key or takes some action that causes the system itself to change the foreground window (for example, clicking a background window).

This function is provided so applications can prevent other applications from making a foreground change that can interrupt its interaction with the user.

## See also

[AllowSetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-allowsetforegroundwindow)

**Conceptual**

**Reference**

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
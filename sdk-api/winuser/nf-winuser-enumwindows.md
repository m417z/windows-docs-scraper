# EnumWindows function

## Description

Enumerates all top-level windows on the screen by passing the handle to each window, in turn, to an application-defined callback function. **EnumWindows** continues until the last top-level window is enumerated or the callback function returns **FALSE**.

## Parameters

### `lpEnumFunc` [in]

Type: **WNDENUMPROC**

A pointer to an application-defined callback function. For more information, see [EnumWindowsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633498(v=vs.85)).

### `lParam` [in]

Type: **LPARAM**

An application-defined value to be passed to the callback function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If [EnumWindowsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633498(v=vs.85)) returns zero, the return value is also zero. In this case, the callback function should call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to obtain a meaningful error code to be returned to the caller of **EnumWindows**.

## Remarks

The **EnumWindows** function does not enumerate child windows, with the exception of a few top-level windows owned by the system that have the **WS_CHILD** style.

This function is more reliable than calling the [GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow) function in a loop. An application that calls **GetWindow** to perform this task risks being caught in an infinite loop or referencing a handle to a window that has been destroyed.

**Note** For Windows 8 and later, **EnumWindows** enumerates only top-level windows of desktop apps.

## See also

**Conceptual**

[EnumChildWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumchildwindows)

[EnumWindowsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633498(v=vs.85))

[GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
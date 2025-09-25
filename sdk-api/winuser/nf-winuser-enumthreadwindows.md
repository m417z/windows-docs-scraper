# EnumThreadWindows function

## Description

Enumerates all nonchild windows associated with a thread by passing the handle to each window, in turn, to an application-defined callback function. **EnumThreadWindows** continues until the last window is enumerated or the callback function returns **FALSE**. To enumerate child windows of a particular window, use the [EnumChildWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumchildwindows) function.

## Parameters

### `dwThreadId` [in]

Type: **DWORD**

The identifier of the thread whose windows are to be enumerated.

### `lpfn` [in]

Type: **WNDENUMPROC**

A pointer to an application-defined callback function. For more information, see [EnumThreadWndProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633496(v=vs.85)).

### `lParam` [in]

Type: **LPARAM**

An application-defined value to be passed to the callback function.

## Return value

Type: **BOOL**

If the callback function returns **TRUE** for all windows in the thread specified by *dwThreadId*, the return value is **TRUE**. If the callback function returns **FALSE** on any enumerated window, or if there are no windows found in the thread specified by *dwThreadId*, the return value is **FALSE**.

## See also

**Conceptual**

[EnumChildWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumchildwindows)

[EnumThreadWndProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633496(v=vs.85))

[EnumWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumwindows)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
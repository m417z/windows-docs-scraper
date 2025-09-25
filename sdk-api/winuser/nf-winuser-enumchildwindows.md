# EnumChildWindows function

## Description

Enumerates the child windows that belong to the specified parent window by passing the handle to each child window, in turn, to an application-defined callback function. **EnumChildWindows** continues until the last child window is enumerated or the callback function returns **FALSE**.

## Parameters

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the parent window whose child windows are to be enumerated. If this parameter is **NULL**, this function is equivalent to [EnumWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumwindows).

### `lpEnumFunc` [in]

Type: **WNDENUMPROC**

A pointer to an application-defined callback function. For more information, see [EnumChildProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633493(v=vs.85)).

### `lParam` [in]

Type: **LPARAM**

An application-defined value to be passed to the callback function.

## Return value

Type: **BOOL**

The return value is not used.

## Remarks

If a child window has created child windows of its own, **EnumChildWindows** enumerates those windows as well.

A child window that is moved or repositioned in the Z order during the enumeration process will be properly enumerated. The function does not enumerate a child window that is destroyed before being enumerated or that is created during the enumeration process.

## See also

**Conceptual**

[EnumChildProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633493(v=vs.85))

[EnumThreadWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumthreadwindows)

[EnumWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumwindows)

[GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
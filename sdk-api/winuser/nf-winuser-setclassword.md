# SetClassWord function

## Description

Replaces the 16-bit (**WORD**) value at the specified offset into the extra class memory for the window class to which the specified window belongs.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [SetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclasslonga) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex` [in]

Type: **int**

The zero-based byte offset of the value to be replaced. Valid values are in the range zero through the number of bytes of class memory minus two; for example, if you specified 10 or more bytes of extra class memory, a value of 8 would be an index to the fifth 16-bit integer.

### `wNewWord` [in]

Type: **WORD**

The replacement value.

## Return value

Type: **WORD**

If the function succeeds, the return value is the previous value of the specified 16-bit integer. If the value was not previously set, the return value is zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Reserve extra class memory by specifying a nonzero value in the
**cbClsExtra** member of the [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure used with the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) function.

## See also

**Conceptual**

[GetClassWord](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassword)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[SetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclasslonga)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)
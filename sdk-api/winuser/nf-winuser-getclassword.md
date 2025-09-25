# GetClassWord function

## Description

Retrieves the 16-bit (**WORD**) value at the specified offset into the extra class memory for the window class to which the specified window belongs.

**Note** This function is deprecated for any use other than *nIndex* set to **GCW_ATOM**. The function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga) or [GetClassLongPtr](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslongptra) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex` [in]

Type: **int**

The zero-based byte offset of the value to be retrieved. Valid values are in the range zero through the number of bytes of class memory, minus two; for example, if you specified 10 or more bytes of extra class memory, a value of eight would be an index to the fifth 16-bit integer. There is an additional valid value as shown in the following table.

| Value | Meaning |
| --- | --- |
| **GCW_ATOM**<br><br>-32 | Retrieves an **ATOM** value that uniquely identifies the window class. This is the same atom that the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function returns. |

## Return value

Type: **WORD**

If the function succeeds, the return value is the requested 16-bit value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Reserve extra class memory by specifying a nonzero value in the
**cbClsExtra** member of the [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure used with the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) function.

## See also

**Conceptual**

[GetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclasslonga)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetClassWord](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclassword)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)
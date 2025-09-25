## Description

Retrieves the 16-bit (**DWORD**) value at the specified offset into the extra window memory.

## Parameters

### `hWnd`

A handle to the window and, indirectly, the class to which the window belongs.

### `nIndex`

The zero-based offset to the value to be retrieved. Valid values are in the range zero through the number of bytes of extra window memory, minus four; for example, if you specified 12 or more bytes of extra memory, a value of 8 would be an index to the third 32-bit integer. To retrieve any other value, specify one of the following values.

| Constant | Value | Meaning |
|-----------|-------|---------|
| GWW_HINSTANCE | -6 | Retrieves a handle to the application instance. |
| GWW_HWNDPARENT -8 | Retrieves a handle to the parent window, if any. |
| GWW_ID | -12 | Retrieves the identifier of the window. |

## Return value

If the function succeeds, the return value is the requested value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Reserve extra window memory by specifying a nonzero value in the **cbWndExtra** member of the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

## See also
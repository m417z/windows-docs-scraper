# GetCaretPos function

## Description

Copies the caret's position to the specified [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure.

## Parameters

### `lpPoint` [out]

Type: **LPPOINT**

A pointer to the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that is to receive the client coordinates of the caret.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caret position is always given in the client coordinates of the window that contains the caret.

### DPI Virtualization

This API does not participate in DPI virtualization. The returned values are interpreted as logical sizes in terms of the window in question. The calling thread is not taken into consideration.

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[SetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretpos)
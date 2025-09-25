# HideCaret function

## Description

Removes the caret from the screen. Hiding a caret does not destroy its current shape or invalidate the insertion point.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window that owns the caret. If this parameter is **NULL**, **HideCaret** searches the current task for the window that owns the caret.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**HideCaret** hides the caret only if the specified window owns the caret. If the specified window does not own the caret, **HideCaret** does nothing and returns **FALSE**.

Hiding is cumulative. If your application calls **HideCaret** five times in a row, it must also call [ShowCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcaret) five times before the caret is displayed.

For an example, see [Hiding a Caret](https://learn.microsoft.com/windows/desktop/menurc/using-carets).

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

[CreateCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcaret)

[DestroyCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycaret)

[GetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcaretpos)

**Reference**

[SetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretpos)

[ShowCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcaret)
# ShowCaret function

## Description

Makes the caret visible on the screen at the caret's current position. When the caret becomes visible, it begins flashing automatically.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window that owns the caret. If this parameter is **NULL**, **ShowCaret** searches the current task for the window that owns the caret.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**ShowCaret** shows the caret only if the specified window owns the caret, the caret has a shape, and the caret has not been hidden two or more times in a row. If one or more of these conditions is not met, **ShowCaret** does nothing and returns **FALSE**.

Hiding is cumulative. If your application calls [HideCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-hidecaret) five times in a row, it must also call **ShowCaret** five times before the caret reappears.

The system provides one caret per queue. A window should create a caret only when it has the keyboard focus or is active. The window should destroy the caret before losing the keyboard focus or becoming inactive.

#### Examples

For an example, see [Creating and Displaying a Caret](https://learn.microsoft.com/windows/desktop/menurc/using-carets).

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

[CreateCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcaret)

[DestroyCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycaret)

[GetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcaretpos)

[HideCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-hidecaret)

**Reference**

[SetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretpos)
# DestroyCaret function

## Description

Destroys the caret's current shape, frees the caret from the window, and removes the caret from the screen.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**DestroyCaret** destroys the caret only if a window in the current task owns the caret. If a window that is not in the current task owns the caret, **DestroyCaret** does nothing and returns **FALSE**.

The system provides one caret per queue. A window should create a caret only when it has the keyboard focus or is active. The window should destroy the caret before losing the keyboard focus or becoming inactive.

For an example, see [Destroying a Caret](https://learn.microsoft.com/windows/desktop/menurc/using-carets)

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

[CreateCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcaret)

[HideCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-hidecaret)

**Reference**

[ShowCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcaret)
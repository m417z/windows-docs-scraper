# GetCaretBlinkTime function

## Description

Retrieves the time required to invert the caret's pixels.
The user can set this value.

## Return value

Type: **UINT**

If the function succeeds, the return value is the blink time, in milliseconds.

A return value of **INFINITE** indicates that the caret does not blink.

A return value is zero indicates that the function has failed.
To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

**Reference**

[SetCaretBlinkTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretblinktime)
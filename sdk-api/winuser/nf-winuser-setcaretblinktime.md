# SetCaretBlinkTime function

## Description

Sets the caret blink time to the specified number of milliseconds. The blink time is the elapsed time, in milliseconds, required to invert the caret's pixels.

## Parameters

### `uMSeconds` [in]

Type: **UINT**

The new blink time, in milliseconds.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The user can set the blink time using the Control Panel. Applications should respect the setting that the user has chosen. The **SetCaretBlinkTime** function should only be used by application that allow the user to set the blink time, such as a Control Panel applet.

If you change the blink time, subsequently activated applications will use the modified blink time, even if you restore the previous blink time when you lose the keyboard focus or become inactive. This is due to the multithreaded environment, where deactivation of your application is not synchronized with the activation of another application. This feature allows the system to activate another application even if the current application is not responding.

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

[GetCaretBlinkTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcaretblinktime)

**Reference**
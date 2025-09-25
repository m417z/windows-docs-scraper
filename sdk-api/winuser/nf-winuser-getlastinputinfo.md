# GetLastInputInfo function

## Description

Retrieves the time of the last input event.

## Parameters

### `plii` [out]

Type: **PLASTINPUTINFO**

A pointer to a [LASTINPUTINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-lastinputinfo) structure that receives the time of the last input event.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

This function is useful for input idle detection. However, **GetLastInputInfo** does not provide system-wide user input information across all running sessions. Rather, **GetLastInputInfo** provides session-specific user input information for only the session that invoked the function.

The tick count when the last input event was received (see [LASTINPUTINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-lastinputinfo)) is not guaranteed to be incremental. In some cases, the value might be less than the tick count of a prior event. For example, this can be caused by a timing gap between the raw input thread and the desktop thread or an event raised by [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput), which supplies its own tick count.

## See also

**Conceptual**

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LASTINPUTINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-lastinputinfo)

**Reference**
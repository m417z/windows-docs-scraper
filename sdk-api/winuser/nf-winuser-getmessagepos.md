# GetMessagePos function

## Description

Retrieves the cursor position for the last message retrieved by the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) function.

To determine the current position of the cursor, use the [GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos) function.

## Return value

Type: **DWORD**

The return value specifies the x- and y-coordinates of the cursor position. The x-coordinate is the low order **short** and the y-coordinate is the high-order **short**.

## Remarks

As noted above, the x-coordinate is in the low-order **short** of the return value; the y-coordinate is in the high-order **short** (both represent *signed* values because they can take negative values on systems with multiple monitors). If the return value is assigned to a variable, you can use the [MAKEPOINTS](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-makepoints) macro to obtain a [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure from the return value. You can also use the [GET_X_LPARAM](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-get_x_lparam) or [GET_Y_LPARAM](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-get_y_lparam) macro to extract the x- or y-coordinate.

**Important** Do not use the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) or [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) macros to extract the x- and y- coordinates of the cursor position because these macros return incorrect results on systems with multiple monitors. Systems with multiple monitors can have negative x- and y- coordinates, and **LOWORD** and **HIWORD** treat the coordinates as unsigned quantities.

## See also

**Conceptual**

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[GetMessageTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessagetime)

[HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85))

[LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85))

[MAKEPOINTS](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-makepoints)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Other Resources**

[POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points)

**Reference**
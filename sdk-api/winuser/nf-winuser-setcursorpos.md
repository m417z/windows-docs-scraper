# SetCursorPos function

## Description

Moves the cursor to the specified screen coordinates. If the new coordinates are not within the screen rectangle set by the most recent [ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor) function call, the system automatically adjusts the coordinates so that the cursor stays within the rectangle.

## Parameters

### `X` [in]

Type: **int**

The new x-coordinate of the cursor, in screen coordinates.

### `Y` [in]

Type: **int**

The new y-coordinate of the cursor, in screen coordinates.

## Return value

Type: **BOOL**

Returns nonzero if successful or zero otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The cursor is a shared resource. A window should move the cursor only when the cursor is in the window's client area.

The calling process must have **WINSTA_WRITEATTRIBUTES** access to the window station.

The input desktop must be the current desktop when you call **SetCursorPos**. Call [OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop) to determine whether the current desktop is the input desktop. If it is not, call [SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop) with the **HDESK** returned by **OpenInputDesktop** to switch to that desktop.

#### Examples

For an example, see [Using the Keyboard to Move the Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

## See also

[ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

**Reference**

[SetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretpos)

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)
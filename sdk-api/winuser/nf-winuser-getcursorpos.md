# GetCursorPos function

## Description

Retrieves the position of the mouse cursor, in screen coordinates.

## Parameters

### `lpPoint` [out]

Type: **LPPOINT**

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the screen coordinates of the cursor.

## Return value

Type: **BOOL**

Returns nonzero if successful or zero otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The cursor position is always specified in screen coordinates and is not affected by the mapping mode of the window that contains the cursor.

The calling process must have **WINSTA_READATTRIBUTES** access to the window station.

The input desktop must be the current desktop when you call **GetCursorPos**. Call [OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop) to determine whether the current desktop is the input desktop. If it is not, call [SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop) with the **HDESK** returned by **OpenInputDesktop** to switch to that desktop.

#### Examples

For an example, see [Using the Keyboard to Move the Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

## See also

[ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorinfo)

[GetMessagePos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessagepos)

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)
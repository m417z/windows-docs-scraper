# SetCursor function

## Description

Sets the cursor shape.

## Parameters

### `hCursor` [in, optional]

Type: **HCURSOR**

A handle to the cursor.

The cursor must have been created by either the [CreateCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcursor) or the [CreateIconIndirect](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createiconindirect) function, or loaded by either the [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora) or the [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) function.

If this parameter is **NULL**, the cursor is removed from the screen.

## Return value

Type: **HCURSOR**

The return value is the handle to the previous cursor, if there was one.

If there was no previous cursor, the return value is **NULL**.

## Remarks

The cursor is set only if the new cursor is different from the previous cursor; otherwise, the function returns immediately.

The cursor is a shared resource. A window should set the cursor shape only when the cursor is in its client area or when the window is capturing mouse input. In systems without a mouse, the window should restore the previous cursor before the cursor leaves the client area or before it relinquishes control to another window.

If your application must set the cursor while it is in a window, make sure the class cursor for the specified window's class is set to **NULL**. If the class cursor is not **NULL**, the system restores the class cursor each time the mouse is moved.

The cursor is not shown on the screen if the internal cursor display count is less than zero. This occurs if the application uses the [ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor) function to hide the cursor more times than to show the cursor.

#### Examples

For an example, see [Displaying a Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[Creating a Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors#creating-a-cursor)

[CreateCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcursor)

[CreateIconIndirect](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createiconindirect)

[GetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursor)

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

**Reference**

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)
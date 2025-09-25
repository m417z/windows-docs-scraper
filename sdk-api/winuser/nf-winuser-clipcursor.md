# ClipCursor function

## Description

Confines the cursor to a rectangular area on the screen. If a subsequent cursor position (set by the [SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos) function or the mouse) lies outside the rectangle, the system automatically adjusts the position to keep the cursor inside the rectangular area.

## Parameters

### `lpRect` [in, optional]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to the structure that contains the screen coordinates of the upper-left and lower-right corners of the confining rectangle. If this parameter is **NULL**, the cursor is free to move anywhere on the screen.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The cursor is a shared resource. If an application confines the cursor, it must release the cursor by using **ClipCursor** before relinquishing control to another application.

The calling process must have **WINSTA_WRITEATTRIBUTES** access to the window station.

#### Examples

For an example, see [Confining a Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipcursor)

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)
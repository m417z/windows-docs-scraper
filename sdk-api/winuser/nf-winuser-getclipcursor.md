# GetClipCursor function

## Description

Retrieves the screen coordinates of the rectangular area to which the cursor is confined.

## Parameters

### `lpRect` [out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the screen coordinates of the confining rectangle. The structure receives the dimensions of the screen if the cursor is not confined to a rectangle.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The cursor is a shared resource. If an application confines the cursor with the [ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor) function, it must later release the cursor by using **ClipCursor** before relinquishing control to another application.

The calling process must have **WINSTA_READATTRIBUTES** access to the window station.

#### Examples

For an example, see [Confining a Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

## See also

[ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**
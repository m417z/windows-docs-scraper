# ShowCursor function

## Description

Displays or hides the cursor.

## Parameters

### `bShow` [in]

Type: **BOOL**

If *bShow* is **TRUE**, the display count is incremented by one. If *bShow* is **FALSE**, the display count is decremented by one.

## Return value

Type: **int**

The return value specifies the new display counter.

## Remarks

**Windows 8**: Call [GetCursorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorinfo) to determine the cursor visibility.

This function sets an internal display counter that determines whether the cursor should be displayed. The cursor is displayed only if the display count is greater than or equal to 0. If a mouse is installed, the initial display count is 0. If no mouse is installed, the display count is
–1.

## See also

[ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)
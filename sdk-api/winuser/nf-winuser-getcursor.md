# GetCursor function

## Description

Retrieves a handle to the current cursor.

To get information on the global cursor, even if it is not owned by the current thread, use [GetCursorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorinfo).

## Return value

Type: **HCURSOR**

The return value is the handle to the current cursor. If there is no cursor, the return value is **NULL**.

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorinfo)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)
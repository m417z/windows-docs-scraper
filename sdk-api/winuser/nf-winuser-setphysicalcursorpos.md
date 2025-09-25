# SetPhysicalCursorPos function

## Description

Sets the position of the cursor in physical coordinates.

## Parameters

### `X` [in]

Type: **int**

The new x-coordinate of the cursor, in physical coordinates.

### `Y` [in]

Type: **int**

The new y-coordinate of the cursor, in physical coordinates.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise **FALSE**.

## Remarks

For a description of the difference between logical coordinates and physical coordinates, see [PhysicalToLogicalPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-physicaltologicalpoint).

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be called to get more information about any error that is generated.

## See also

[ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

[GetPhysicalCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getphysicalcursorpos)

**Reference**

[SetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretpos)

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)
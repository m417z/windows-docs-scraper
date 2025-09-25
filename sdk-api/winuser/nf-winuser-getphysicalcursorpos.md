# GetPhysicalCursorPos function

## Description

Retrieves the position of the cursor in physical coordinates.

## Parameters

### `lpPoint` [out]

Type: **LPPOINT**

The position of the cursor, in physical coordinates.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise **FALSE**.

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be called to get more information about any error that is generated.

## Remarks

For a description of the difference between logical coordinates and physical coordinates, see [PhysicalToLogicalPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-physicaltologicalpoint).

## See also

[ClipCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clipcursor)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorpos)

**Reference**

[SetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcaretpos)

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[SetCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursorpos)

[SetPhysicalCursorPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setphysicalcursorpos)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)
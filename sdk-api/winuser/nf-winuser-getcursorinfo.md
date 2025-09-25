# GetCursorInfo function

## Description

Retrieves information about the global cursor.

## Parameters

### `pci` [in, out]

Type: **PCURSORINFO**

A pointer to a [CURSORINFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-cursorinfo) structure that receives the information. Note that you must set the **cbSize** member to `sizeof(CURSORINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CURSORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-cursorinfo)

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo)

**Reference**
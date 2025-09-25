# SetMenu function

## Description

Assigns a new menu to the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to which the menu is to be assigned.

### `hMenu` [in, optional]

Type: **HMENU**

A handle to the new menu. If this parameter is **NULL**, the window's current menu is removed.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The window is redrawn to reflect the menu change. A menu can be assigned to any window that is not a child window.

The **SetMenu** function replaces the previous menu, if any, but it does not destroy it. An application should call the [DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu) function to accomplish this task.

## See also

**Conceptual**

[DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu)

[GetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenu)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
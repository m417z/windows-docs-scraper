# DrawMenuBar function

## Description

Redraws the menu bar of the specified window. If the menu bar changes after the system has created the window, this function must be called to draw the changed menu bar.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose menu bar is to be redrawn.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[DeleteMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deletemenu)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[RemoveMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removemenu)

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)
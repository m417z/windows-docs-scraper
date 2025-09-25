# GetMenuBarInfo function

## Description

Retrieves information about the specified menu bar.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window (menu bar) whose information is to be retrieved.

### `idObject` [in]

Type: **LONG**

The menu object. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **OBJID_CLIENT**<br><br>((LONG)0xFFFFFFFC) | The popup menu associated with the window. |
| **OBJID_MENU**<br><br>((LONG)0xFFFFFFFD) | The menu bar associated with the window (see the [GetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenu) function). |
| **OBJID_SYSMENU**<br><br>((LONG)0xFFFFFFFF) | The system menu associated with the window (see the [GetSystemMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmenu) function). |

### `idItem` [in]

Type: **LONG**

The item for which to retrieve information. If this parameter is zero, the function retrieves information about the menu itself. If this parameter is 1, the function retrieves information about the first item on the menu, and so on.

### `pmbi` [in, out]

Type: **PMENUBARINFO**

A pointer to a [MENUBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menubarinfo) structure that receives the information. Note that you must set the **cbSize** member to `sizeof(MENUBARINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[GetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenu)

[GetSystemMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmenu)

[MENUBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menubarinfo)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
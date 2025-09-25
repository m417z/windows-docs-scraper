# GetMenuInfo function

## Description

Retrieves information about a specified menu.

## Parameters

### `unnamedParam1` [in]

Type: **HMENU**

A handle on a menu.

### `unnamedParam2` [in, out]

Type: **LPMENUINFO**

A pointer to a [MENUINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuinfo) structure containing information for the menu. Note that you must set the **cbSize** member to `sizeof(MENUINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)
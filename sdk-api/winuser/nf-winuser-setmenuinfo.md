# SetMenuInfo function

## Description

Sets information for a specified menu.

## Parameters

### `unnamedParam1` [in]

Type: **HMENU**

A handle to a menu.

### `unnamedParam2` [in]

Type: **LPCMENUINFO**

A pointer to a [MENUINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuinfo) structure for the menu.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)
# GetMenuItemCount function

## Description

Determines the number of items in the specified menu.

## Parameters

### `hMenu` [in, optional]

Type: **HMENU**

A handle to the menu to be examined.

## Return value

Type: **int**

If the function succeeds, the return value specifies the number of items in the menu.

If the function fails, the return value is -1. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[GetMenuItemID](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemid)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
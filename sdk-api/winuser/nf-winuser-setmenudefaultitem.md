# SetMenuDefaultItem function

## Description

Sets the default menu item for the specified menu.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu to set the default item for.

### `uItem` [in]

Type: **UINT**

The identifier or position of the new default menu item or -1 for no default item. The meaning of this parameter depends on the value of
*fByPos*.

### `fByPos` [in]

Type: **UINT**

The meaning of *uItem*. If this parameter is **FALSE**, *uItem* is a menu item identifier. Otherwise, it is a menu item position. See [About Menus](https://learn.microsoft.com/windows/desktop/menurc/about-menus) for more information.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

**Conceptual**

[GetMenuDefaultItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenudefaultitem)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
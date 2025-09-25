# GetMenuDefaultItem function

## Description

Determines the default menu item on the specified menu.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu for which to retrieve the default menu item.

### `fByPos` [in]

Type: **UINT**

Indicates whether to retrieve the menu item's identifier or its position. If this parameter is **FALSE**, the identifier is returned. Otherwise, the position is returned.

### `gmdiFlags` [in]

Type: **UINT**

Indicates how the function should search for menu items. This parameter can be zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **GMDI_GOINTOPOPUPS**<br><br>0x0002L | If the default item is one that opens a submenu, the function is to search recursively in the corresponding submenu. If the submenu has no default item, the return value identifies the item that opens the submenu. By default, the function returns the first default item on the specified menu, regardless of whether it is an item that opens a submenu. |
| **GMDI_USEDISABLED**<br><br>0x0001L | The function is to return a default item, even if it is disabled. By default, the function skips disabled or grayed items. |

## Return value

Type: **UINT**

If the function succeeds, the return value is the identifier or position of the menu item.

If the function fails, the return value is -1. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuDefaultItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenudefaultitem)
# GetMenuItemID function

## Description

Retrieves the menu item identifier of a menu item located at the specified position in a menu.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu that contains the item whose identifier is to be retrieved.

### `nPos` [in]

Type: **int**

The zero-based relative position of the menu item whose identifier is to be retrieved.

## Return value

Type: **UINT**

The return value is the identifier of the specified menu item. If the menu item identifier is **NULL** or if the specified item opens a submenu, the return value is -1.

## See also

**Conceptual**

[GetMenuItemCount](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemcount)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
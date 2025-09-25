# GetSubMenu function

## Description

Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu.

### `nPos` [in]

Type: **int**

The zero-based relative position in the specified menu of an item that activates a drop-down menu or submenu.

## Return value

Type: **HMENU**

If the function succeeds, the return value is a handle to the drop-down menu or submenu activated by the menu item. If the menu item does not activate a drop-down menu or submenu, the return value is **NULL**.

## See also

**Conceptual**

[CreatePopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createpopupmenu)

[GetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenu)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
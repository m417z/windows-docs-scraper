# MENUBARINFO structure

## Description

Contains menu bar information.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. The caller must set this to `sizeof(MENUBARINFO)`.

### `rcBar`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The coordinates of the menu bar, popup menu, or menu item.

### `hMenu`

Type: **HMENU**

A handle to the menu bar or popup menu.

### `hwndMenu`

Type: **HWND**

A handle to the submenu.

### `fBarFocused`

Type: **BOOL**

If the menu bar or popup menu has the focus, this member is **TRUE**. Otherwise, the member is **FALSE**.

### `fFocused`

Type: **BOOL**

If the menu item has the focus, this member is **TRUE**. Otherwise, the member is **FALSE**.

## See also

**Conceptual**

[GetMenuBarInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenubarinfo)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**
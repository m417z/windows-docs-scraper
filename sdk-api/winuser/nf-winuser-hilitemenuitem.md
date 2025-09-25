# HiliteMenuItem function

## Description

Adds or removes highlighting from an item in a menu bar.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window that contains the menu.

### `hMenu` [in]

Type: **HMENU**

A handle to the menu bar that contains the item.

### `uIDHiliteItem` [in]

Type: **UINT**

The menu item. This parameter is either the identifier of the menu item or the offset of the menu item in the menu bar, depending on the value of the *uHilite* parameter.

### `uHilite` [in]

Type: **UINT**

Controls the interpretation of the *uItemHilite* parameter and indicates whether the menu item is highlighted. This parameter must be a combination of either **MF_BYCOMMAND** or **MF_BYPOSITION** and **MF_HILITE** or **MF_UNHILITE**.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that *uItemHilite* gives the identifier of the menu item. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that *uItemHilite* gives the zero-based relative position of the menu item. |
| **MF_HILITE**<br><br>0x00000080L | Highlights the menu item. If this flag is not specified, the highlighting is removed from the item. |
| **MF_UNHILITE**<br><br>0x00000000L | Removes highlighting from the menu item. |

## Return value

Type: **BOOL**

If the menu item is set to the specified highlight state, the return value is nonzero.

If the menu item is not set to the specified highlight state, the return value is zero.

## Remarks

The **MF_HILITE** and **MF_UNHILITE** flags can be used only with the **HiliteMenuItem** function; they cannot be used with the [ModifyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-modifymenua) function.

## See also

**Conceptual**

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

[ModifyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-modifymenua)

**Reference**
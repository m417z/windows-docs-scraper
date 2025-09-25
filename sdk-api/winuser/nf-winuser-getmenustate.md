# GetMenuState function

## Description

Retrieves the menu flags associated with the specified menu item. If the menu item opens a submenu, this function also returns the number of items in the submenu.

**Note** The **GetMenuState** function has been superseded by the [GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa). You can still use **GetMenuState**, however, if you do not need any of the extended features of **GetMenuItemInfo**.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu that contains the menu item whose flags are to be retrieved.

### `uId` [in]

Type: **UINT**

The menu item for which the menu flags are to be retrieved, as determined by the *uFlags* parameter.

### `uFlags` [in]

Type: **UINT**

Indicates how the *uId* parameter is interpreted. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that the *uId* parameter gives the identifier of the menu item. The **MF_BYCOMMAND** flag is the default if neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that the *uId* parameter gives the zero-based relative position of the menu item. |

## Return value

Type: **UINT**

If the specified item does not exist, the return value is -1.

If the menu item opens a submenu, the low-order byte of the return value contains the menu flags associated with the item, and the high-order byte contains the number of items in the submenu opened by the item.

Otherwise, the return value is a mask (Bitwise OR) of the menu flags. Following are the menu flags associated with the menu item.

| Return code/value | Description |
| --- | --- |
| **MF_CHECKED**<br><br>0x00000008L | A check mark is placed next to the item (for drop-down menus, submenus, and shortcut menus only). |
| **MF_DISABLED**<br><br>0x00000002L | The item is disabled. |
| **MF_GRAYED**<br><br>0x00000001L | The item is disabled and grayed. |
| **MF_HILITE**<br><br>0x00000080L | The item is highlighted. |
| **MF_MENUBARBREAK**<br><br>0x00000020L | This is the same as the **MF_MENUBREAK** flag, except for drop-down menus, submenus, and shortcut menus, where the new column is separated from the old column by a vertical line. |
| **MF_MENUBREAK**<br><br>0x00000040L | The item is placed on a new line (for menu bars) or in a new column (for drop-down menus, submenus, and shortcut menus) without separating columns. |
| **MF_OWNERDRAW**<br><br>0x00000100L | The item is owner-drawn. |
| **MF_POPUP**<br><br>0x00000010L | Menu item is a submenu. |
| **MF_SEPARATOR**<br><br>0x00000800L | There is a horizontal dividing line (for drop-down menus, submenus, and shortcut menus only). |

## Remarks

It is possible to test an item for a flag value of **MF_ENABLED**, **MF_STRING**, **MF_UNCHECKED**, or **MF_UNHILITE**. However, since these values equate to zero you must use an expression to test for them.

| Flag | Expression to test for the flag |
| --- | --- |
| **MF_ENABLED** | `! (Flag&(MF_DISABLED | MF_GRAYED))` |
| **MF_STRING** | `! (Flag&(MF_BITMAP | MF_OWNERDRAW))` |
| **MF_UNCHECKED** | `! (Flag&MF_CHECKED)` |
| **MF_UNHILITE** | `! (Flag&HILITE)` |

#### Examples

For an example, see [Simulating Check Boxes in a Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

**Conceptual**

[GetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenu)

[GetMenuItemCount](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemcount)

[GetMenuItemID](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemid)

[GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
# MENUITEMTEMPLATE structure

## Description

Defines a menu item in a menu template.

## Members

### `mtOption`

Type: **WORD**

One or more of the following predefined menu options that control the appearance of the menu item as shown in the following table.

| Value | Meaning |
| --- | --- |
| **MF_CHECKED**<br><br>0x00000008L | Indicates that the menu item has a check mark next to it. |
| **MF_GRAYED**<br><br>0x00000001L | Indicates that the menu item is initially inactive and drawn with a gray effect. |
| **MF_HELP**<br><br>0x00004000L | Indicates that the menu item has a vertical separator to its left. |
| **MF_MENUBARBREAK**<br><br>0x00000020L | Indicates that the menu item is placed in a new column. The old and new columns are separated by a bar. |
| **MF_MENUBREAK**<br><br>0x00000040L | Indicates that the menu item is placed in a new column. |
| **MF_OWNERDRAW**<br><br>0x00000100L | Indicates that the owner window of the menu is responsible for drawing all visual aspects of the menu item, including highlighted, selected, and inactive states. This option is not valid for an item in a menu bar. |
| **MF_POPUP**<br><br>0x00000010L | Indicates that the item is one that opens a drop-down menu or submenu. |

### `mtID`

Type: **WORD**

The menu item identifier of a command item; a command item sends a command message to its owner window. The **MENUITEMTEMPLATE** structure for an item that opens a drop-down menu or submenu does not contain the
**mtID** member.

### `mtString`

Type: **WCHAR[1]**

The menu item.

## See also

**Conceptual**

[LoadMenuIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuindirecta)

[MENUITEMTEMPLATEHEADER](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplateheader)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
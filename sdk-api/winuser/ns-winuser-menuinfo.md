# MENUINFO structure

## Description

Contains information about a menu.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. The caller must set this member to `sizeof(MENUINFO)`.

### `fMask`

Type: **DWORD**

Indicates the members to be retrieved or set (except for **MIM_APPLYTOSUBMENUS**). This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MIM_APPLYTOSUBMENUS**<br><br>0x80000000 | Settings apply to the menu and all of its submenus. [SetMenuInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuinfo) uses this flag and [GetMenuInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuinfo) ignores this flag |
| **MIM_BACKGROUND**<br><br>0x00000002 | Retrieves or sets the **hbrBack** member. |
| **MIM_HELPID**<br><br>0x00000004 | Retrieves or sets the **dwContextHelpID** member. |
| **MIM_MAXHEIGHT**<br><br>0x00000001 | Retrieves or sets the **cyMax** member. |
| **MIM_MENUDATA**<br><br>0x00000008 | Retrieves or sets the **dwMenuData** member. |
| **MIM_STYLE**<br><br>0x00000010 | Retrieves or sets the **dwStyle** member. |

### `dwStyle`

Type: **DWORD**

The menu style. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MNS_AUTODISMISS**<br><br>0x10000000 | Menu automatically ends when mouse is outside the menu for approximately 10 seconds. |
| **MNS_CHECKORBMP**<br><br>0x04000000 | The same space is reserved for the check mark and the bitmap. If the check mark is drawn, the bitmap is not. All checkmarks and bitmaps are aligned. Used for menus where some items use checkmarks and some use bitmaps. |
| **MNS_DRAGDROP**<br><br>0x20000000 | Menu items are OLE drop targets or drag sources. Menu owner receives [WM_MENUDRAG](https://learn.microsoft.com/windows/desktop/menurc/wm-menudrag) and [WM_MENUGETOBJECT](https://learn.microsoft.com/windows/desktop/menurc/wm-menugetobject) messages. |
| **MNS_MODELESS**<br><br>0x40000000 | Menu is modeless; that is, there is no menu modal message loop while the menu is active. |
| **MNS_NOCHECK**<br><br>0x80000000 | No space is reserved to the left of an item for a check mark. The item can still be selected, but the check mark will not appear next to the item. |
| **MNS_NOTIFYBYPOS**<br><br>0x08000000 | Menu owner receives a [WM_MENUCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-menucommand) message instead of a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message when the user makes a selection. **MNS_NOTIFYBYPOS** is a menu header style and has no effect when applied to individual sub menus. |

### `cyMax`

Type: **UINT**

The maximum height of the menu in pixels. When the menu items exceed the space available, scroll bars are automatically used. The default (0) is the screen height.

### `hbrBack`

Type: **HBRUSH**

A handle to the brush to be used for the menu's background.

### `dwContextHelpID`

Type: **DWORD**

The context help identifier. This is the same value used in
the [GetMenuContextHelpId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenucontexthelpid) and
[SetMenuContextHelpId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenucontexthelpid) functions.

### `dwMenuData`

Type: **ULONG_PTR**

An application-defined value.

## See also

[Menus Overview](https://learn.microsoft.com/windows/desktop/menurc/menus)
# EnableMenuItem function

## Description

Enables, disables, or grays the specified menu item.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu.

### `uIDEnableItem` [in]

Type: **UINT**

The menu item to be enabled, disabled, or grayed, as determined by the *uEnable* parameter. This parameter specifies an item in a menu bar, menu, or submenu.

### `uEnable` [in]

Type: **UINT**

Controls the interpretation of the *uIDEnableItem* parameter and indicate whether the menu item is enabled, disabled, or grayed. This parameter must be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that *uIDEnableItem* gives the identifier of the menu item. If neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified, the **MF_BYCOMMAND** flag is the default flag. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that *uIDEnableItem* gives the zero-based relative position of the menu item. |
| **MF_DISABLED**<br><br>0x00000002L | Indicates that the menu item is disabled, but not grayed, so it cannot be selected. |
| **MF_ENABLED**<br><br>0x00000000L | Indicates that the menu item is enabled and restored from a grayed state so that it can be selected. |
| **MF_GRAYED**<br><br>0x00000001L | Indicates that the menu item is disabled and grayed so that it cannot be selected. |

## Return value

Type: **BOOL**

The return value specifies the previous state of the menu item (it is either **MF_DISABLED**, **MF_ENABLED**, or **MF_GRAYED**). If the menu item does not exist, the return value is -1.

## Remarks

An application must use the **MF_BYPOSITION** flag to specify the correct menu handle. If the menu handle to the menu bar is specified, the top-level menu item (an item in the menu bar) is affected. To set the state of an item in a drop-down menu or submenu by position, an application must specify a handle to the drop-down menu or submenu.

When an application specifies the **MF_BYCOMMAND** flag, the system checks all items that open submenus in the menu identified by the specified menu handle. Therefore, unless duplicate menu items are present, specifying the menu handle to the menu bar is sufficient.

The [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua), [InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema), [LoadMenuIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuindirecta), [ModifyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-modifymenua), and [SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa) functions can also set the state (enabled, disabled, or grayed) of a menu item.

When you change a window menu, the menu bar is not immediately updated. To force the update, call [DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar).

## See also

**Conceptual**

[DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar)

[GetMenuItemID](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemid)

[InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[LoadMenuIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuindirecta)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

[ModifyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-modifymenua)

**Reference**

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)

[WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand)
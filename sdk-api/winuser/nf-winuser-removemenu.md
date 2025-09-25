# RemoveMenu function

## Description

Deletes a menu item or detaches a submenu from the specified menu. If the menu item opens a drop-down menu or submenu, **RemoveMenu** does not destroy the menu or its handle, allowing the menu to be reused. Before this function is called, the [GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu) function should retrieve a handle to the drop-down menu or submenu.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu to be changed.

### `uPosition` [in]

Type: **UINT**

The menu item to be deleted, as determined by the *uFlags* parameter.

### `uFlags` [in]

Type: **UINT**

Indicates how the *uPosition* parameter is interpreted. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that *uPosition* gives the identifier of the menu item. If neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified, the **MF_BYCOMMAND** flag is the default flag. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that *uPosition* gives the zero-based relative position of the menu item. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The application must call the [DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar) function whenever a menu changes, whether the menu is in a displayed window.

## See also

**Conceptual**

[CreatePopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createpopupmenu)

[DeleteMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deletemenu)

[DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar)

[GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
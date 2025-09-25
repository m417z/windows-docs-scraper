# DeleteMenu function

## Description

Deletes an item from the specified menu. If the menu item opens a menu or submenu, this function destroys the handle to the menu or submenu and frees the memory used by the menu or submenu.

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
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that *uPosition* gives the identifier of the menu item. The **MF_BYCOMMAND** flag is the default flag if neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that *uPosition* gives the zero-based relative position of the menu item. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The application must call the [DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar) function whenever a menu changes, whether the menu is in a displayed window.

#### Examples

For an example, see [Example of a Clipboard Viewer](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

**Conceptual**

[DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[RemoveMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removemenu)
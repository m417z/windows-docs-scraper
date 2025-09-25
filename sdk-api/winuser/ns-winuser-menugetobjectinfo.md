# MENUGETOBJECTINFO structure

## Description

Contains information about the menu that the mouse cursor is on.

## Members

### `dwFlags`

Type: **DWORD**

The position of the mouse cursor with respect to the item indicated by
**uPos**. It is a bitmask of the following values:

| Value | Meaning |
| --- | --- |
| **MNGOF_BOTTOMGAP**<br><br>0x00000002 | The mouse is on the bottom of the item indicated by **uPos**. |
| **MNGOF_TOPGAP**<br><br>0x00000001 | The mouse is on the top of the item indicated by **uPos**. |

If neither MNGOF_BOTTOMGAP nor MNGOF_TOPGAP is set, then the mouse is directly on the item indicated by **uPos**.

### `uPos`

Type: **UINT**

The position of the item the mouse cursor is on.

### `hmenu`

Type: **HMENU**

A handle to the menu the mouse cursor is on.

### `riid`

Type: **PVOID**

The identifier of the requested interface. Currently it can only be [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget).

### `pvObj`

Type: **PVOID**

A pointer to the interface corresponding to the
**riid** member. This pointer is to be returned by the application when processing the message.

## Remarks

The **MENUGETOBJECTINFO** structure is used only in drag-and-drop menus. When the
[WM_MENUGETOBJECT](https://learn.microsoft.com/windows/desktop/menurc/wm-menugetobject) message is sent,
*lParam* is a pointer to this structure.

To create a drag-and-drop menu, call [SetMenuInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuinfo) with **MNS_DRAGDROP** set.

## See also

**Conceptual**

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuinfo)
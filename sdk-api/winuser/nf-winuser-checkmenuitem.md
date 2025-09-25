# CheckMenuItem function

## Description

[**CheckMenuItem** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa).
]

Sets the state of the specified menu item's check-mark attribute to either selected or clear.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu of interest.

### `uIDCheckItem` [in]

Type: **UINT**

The menu item whose check-mark attribute is to be set, as determined by the *uCheck* parameter.

### `uCheck` [in]

Type: **UINT**

The flags that control the interpretation of the *uIDCheckItem* parameter and the state of the menu item's check-mark attribute. This parameter can be a combination of either **MF_BYCOMMAND**, or **MF_BYPOSITION** and **MF_CHECKED** or **MF_UNCHECKED**.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that the *uIDCheckItem* parameter gives the identifier of the menu item. The **MF_BYCOMMAND** flag is the default, if neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that the *uIDCheckItem* parameter gives the zero-based relative position of the menu item. |
| **MF_CHECKED**<br><br>0x00000008L | Sets the check-mark attribute to the selected state. |
| **MF_UNCHECKED**<br><br>0x00000000L | Sets the check-mark attribute to the clear state. |

## Return value

Type: **DWORD**

The return value specifies the previous state of the menu item (either **MF_CHECKED** or **MF_UNCHECKED**). If the menu item does not exist, the return value is –1.

## Remarks

An item in a menu bar cannot have a check mark.

The *uIDCheckItem* parameter identifies a item that opens a submenu or a command item. For a item that opens a submenu, the *uIDCheckItem* parameter must specify the position of the item. For a command item, the *uIDCheckItem* parameter can specify either the item's position or its identifier.

#### Examples

For an example, see [Simulating Check Boxes in a Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

**Conceptual**

[EnableMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablemenuitem)

[GetMenuItemID](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemid)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuItemBitmaps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuitembitmaps)

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)
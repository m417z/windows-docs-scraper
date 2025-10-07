# MENUEX\_TEMPLATE\_ITEM structure

Defines a menu item in an extended menu template. This structure definition is for explanation only; it is not present in any standard header file.

## Members

**dwType**

Type: **DWORD**

The menu item type. This member can be a combination of the type (beginning with MFT) values listed with the [**MENUITEMINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-menuiteminfoa) structure.

**dwState**

Type: **DWORD**

The menu item state. This member can be a combination of the state (beginning with MFS) values listed with the [**MENUITEMINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-menuiteminfoa) structure.

**uId**

Type: **UINT**

The menu item identifier. This is an application-defined value that identifies the menu item. In an extended menu resource, items that open drop-down menus or submenus as well as command items can have identifiers.

**wFlags**

Type: **WORD**

Specifies whether the menu item is the last item in the menu bar, drop-down menu, submenu, or shortcut menu and whether it is an item that opens a drop-down menu or submenu. This member can be zero or more of these values. For 32-bit applications, this member is a word; for 16-bit applications, it is a byte.

0x80

The structure defines the last menu item in the menu bar, drop-down menu, submenu, or shortcut menu.

0x01

The structure defines an item that opens a drop-down menu or submenu. Subsequent structures define menu items in the corresponding drop-down menu or submenu.

**szText**

Type: **WCHAR**

The menu item text. This member is a null-terminated Unicode string, aligned on a word boundary. The size of the menu item definition varies depending on the length of this string.

## Remarks

An extended menu template consists of a [**MENUEX\_TEMPLATE\_HEADER**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-header) structure followed by one or more contiguous **MENUEX\_TEMPLATE\_ITEM** structures. The **MENUEX\_TEMPLATE\_ITEM** structures, which are variable in length, are aligned on **DWORD** boundaries. To create a menu from an extended menu template in memory, use the [**LoadMenuIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-loadmenuindirecta) function.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**LoadMenuIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-loadmenuindirecta)

[**MENUEX\_TEMPLATE\_HEADER**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-header)

[**MENUITEMINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-menuiteminfoa)

**Conceptual**

[Menus](https://learn.microsoft.com/windows/win32/menurc/menus)


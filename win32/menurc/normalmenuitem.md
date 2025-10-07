# NORMALMENUITEM structure

Contains information about each item in a menu resource that does not open a menu or a submenu. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**resInfo**

Type: **WORD**

The type of menu item. This member can be one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
|

**MFR\_END**

0x80

| The menu item is the last in this submenu or menu resource; this flag is used internally by the system.<br> |
|

**MFR\_POPUP**

0x01

| The menu item opens a menu or a submenu; the flag is used internally by the system. <br> |

**menuText**

Type: **szOrOrd**

A null-terminated Unicode string that contains the text for this menu item. There is no fixed limit on the size of this string.

## Remarks

There is one **NORMALMENUITEM** structure for each menu item that does not open a menu or a submenu. Indicate the last menu item on a menu by setting the **resInfo** member to **MFR\_END**.

A menu separator is a special type of menu item that is inactive but appears as a dividing bar between two active menu items. Indicate a menu separator by leaving the **menuText** member empty.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**MENUHEADER**](https://learn.microsoft.com/windows/win32/menurc/menuheader)

[**MENUITEMINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-menuiteminfoa)

[**POPUPMENUITEM**](https://learn.microsoft.com/windows/win32/menurc/popupmenuitem)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)


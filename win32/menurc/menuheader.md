# MENUHEADER structure

Contains version information for the menu resource. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**wVersion**

Type: **WORD**

The version number of the menu template. This member must be equal to zero to indicate that this is an [**RT\_MENU**](https://learn.microsoft.com/windows/desktop/menurc/resource-types) created with a standard menu template.

**cbHeaderSize**

Type: **WORD**

The size of the menu template header. This value is zero for menus you create with a standard menu template.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**MENUEX\_TEMPLATE\_HEADER**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-header)

[**MENUEX\_TEMPLATE\_ITEM**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-item)

[**MENUITEMTEMPLATE**](https://learn.microsoft.com/windows/desktop/api/Winuser/ns-winuser-menuitemtemplate)

[**MENUITEMTEMPLATEHEADER**](https://learn.microsoft.com/windows/desktop/api/Winuser/ns-winuser-menuitemtemplateheader)

[**NORMALMENUITEM**](https://learn.microsoft.com/windows/win32/menurc/normalmenuitem)

[**POPUPMENUITEM**](https://learn.microsoft.com/windows/win32/menurc/popupmenuitem)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)


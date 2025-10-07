# MENUEX\_TEMPLATE\_HEADER structure

Defines the header for an extended menu template. This structure definition is for explanation only; it is not present in any standard header file.

## Members

**wVersion**

Type: **WORD**

The template version number. This member must be 1 for extended menu templates.

**wOffset**

Type: **WORD**

The offset to the first [**MENUEX\_TEMPLATE\_ITEM**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-item) structure, relative to the end of this structure member. If the first item definition immediately follows the **dwHelpId** member, this member should be 4.

**dwHelpId**

Type: **DWORD**

The help identifier of menu bar.

## Remarks

An extended menu template consists of a **MENUEX\_TEMPLATE\_HEADER** structure followed by one or more contiguous [**MENUEX\_TEMPLATE\_ITEM**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-item) structures. The **MENUEX\_TEMPLATE\_ITEM** structures, which are variable in length, are aligned on **DWORD** boundaries. To create a menu from an extended menu template in memory, use the [**LoadMenuIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-loadmenuindirecta) function.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**LoadMenuIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-loadmenuindirecta)

[**MENUEX\_TEMPLATE\_ITEM**](https://learn.microsoft.com/windows/win32/menurc/menuex-template-item)

**Conceptual**

[Menus](https://learn.microsoft.com/windows/win32/menurc/menus)


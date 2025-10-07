# MENUHELPID structure

Contains the final data written to the [**RT\_MENU**](https://learn.microsoft.com/windows/desktop/menurc/resource-types) resource for a menu or submenu if the **resInfo** member of the [**POPUPMENUITEM**](https://learn.microsoft.com/windows/win32/menurc/popupmenuitem) structure is set to **MFR\_POPUP**. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**helpID**

Type: **DWORD**

The identifier used to identify the menu during [**WM\_HELP**](https://learn.microsoft.com/windows/desktop/shell/wm-help) processing.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**MENUHEADER**](https://learn.microsoft.com/windows/win32/menurc/menuheader)

[**POPUPMENUITEM**](https://learn.microsoft.com/windows/win32/menurc/popupmenuitem)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)


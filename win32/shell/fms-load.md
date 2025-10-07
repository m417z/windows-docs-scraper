# FMS\_LOAD structure

Contains information that File Manager uses to add a custom menu provided by a File Manager extension DLL. The structure also provides a delta value that the extension DLL can use to manipulate the custom menu after File Manager has loaded the menu.

## Members

**dwSize**

Type: **DWORD**

The length, in bytes, of the structure.

**szMenuName**

Type: **TCHAR\[MENU\_TEXT\_LEN\]**

A null-terminated name for a menu item that appears on the menu bar in File Manager.

**hMenu**

Type: **HMENU**

The identifier of the pop-up menu added to the menu bar in File Manager.

**wMenuDelta**

Type: **UINT**

The menu item delta value. To avoid conflicts with its own menu items, File Manager renumbers the menu item identifiers in the pop-up menu identified by the **hMenu** member by adding this delta value to each identifier. An extension DLL that must modify a menu item must identify the item by adding the delta value to the menu item's identifier. The value of this member can vary from session to session.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

## See also

[**FMExtensionProc**](https://learn.microsoft.com/windows/win32/shell/fmextensionproc)


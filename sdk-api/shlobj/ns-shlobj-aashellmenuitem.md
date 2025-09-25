# AASHELLMENUITEM structure

## Description

Contains information about a menu item.

## Members

### `lpReserved1`

Type: **VOID**

Reserved. Applications should ignore this value.

### `iReserved`

Type: **int**

Reserved. Applications should ignore this value.

### `uiReserved`

Type: **UINT**

Reserved. Applications should ignore this value.

### `lpName`

Type: **LPAASHELLMENUFILENAME**

If the selected menu item represents a file, this member is a pointer to an [AASHELLMENUFILENAME](https://learn.microsoft.com/windows/win32/api/shlobj/ns-shlobj-aashellmenufilename) structure that contains the name of the file. Otherwise this member is **NULL**.

### `psz`

Type: **LPTSTR**

A pointer to the string that contains the text to use if there is no file.

## Remarks

**Important** This structure cannot be used with operating systems later than Windows 2000.

If the menu belongs to the Windows Explorer process and the menu item is MFT_OWNERDRAW and **dwItemData** is not **NULL**, then the **dwItemData** member can be probed to determine whether it is a Windows Explorer menu that shows owner-drawn file names.

The accessibility tool might treat the **dwItemData** member as a pointer to an **AASHELLMENUITEM** structure in the process that owns the menu. In this case the **lpName** and **psz** members might be examined to determine the identity of the menu item. If **lpName** is not **NULL**, then the menu item represents a file name, expressed as an [AASHELLMENUFILENAME](https://learn.microsoft.com/windows/win32/api/shlobj/ns-shlobj-aashellmenufilename) structure. If **lpName** is **NULL** but **psz** is not **NULL**, then the menu item represents a string that is pointed to by the **psz** member.

The **lpName** and **psz** members contain pointers into the process that owns the menu.

**Note** Not all owner-draw menus in the Windows Explorer process conform to this convention.

Applications that probe owner-draw menu data must validate all data read from the process.

## See also

[AASHELLMENUFILENAME](https://learn.microsoft.com/windows/win32/api/shlobj/ns-shlobj-aashellmenufilename)
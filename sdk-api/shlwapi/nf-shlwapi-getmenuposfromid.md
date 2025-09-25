# GetMenuPosFromID function

## Description

[**GetMenuPosFromID** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines the position of an item in a menu. Used in the case where the item's ID is known.

## Parameters

### `hmenu` [in]

Type: **HMENU**

The handle of the menu.

### `id`

Type: **UINT**

An application-defined 16-bit value that identifies the menu item.

## Return value

Type: **int**

The item's zero-based position in the menu.

## Remarks

Beginning with Windows Vista, this function is declared in Shlwapi.h.

**Windows XP:** This function is declared in Shlwapi.dll.
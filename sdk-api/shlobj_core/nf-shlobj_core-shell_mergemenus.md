# Shell_MergeMenus function

## Description

[**Shell_MergeMenus** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Merges two menus.

## Parameters

### `hmDst` [in]

Type: **HMENU**

The destination menu to which *hmSrc* is added.

### `hmSrc` [in]

Type: **HMENU**

The source menu which is added to *hmDst*.

### `uInsert`

Type: **UINT**

The point in *hmDst* after which the entries in *hmSrc* are inserted.

### `uIDAdjust`

Type: **UINT**

This number is added to each menu's ID to give an adjusted ID. Set to `0` for no adjustment. The value for *uIDAdjust* would typically be the number of items in *hmDst*. This number can be obtained using the [GetMenuItemCount](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuitemcount).

### `uIDAdjustMax`

Type: **UINT**

The maximum adjusted ID to add to the menu. Any adjusted ID greater than this value is not added. To allow all IDs, set this parameter to 0xFFFF.

### `uFlags`

Type: **ULONG**

One or more of the following flags.

#### MM_ADDSEPARATOR

Add a separator between the items from the two menus if one does not exist already. If you are inserting the entries from *hmSrc* into the middle of *hmDst*, a separator is added above and below the *hmSrc* material.

#### MM_DONTREMOVESEPS

Do not remove any existing separators in the two menus. Note that this could result in two separators in a row.

#### MM_SUBMENUSHAVEIDS

Set this flag if the submenus have IDs which should be adjusted.

## Return value

Type: **UINT**

Returns the next open ID at the end of the menu (the maximum adjusted ID + 1).
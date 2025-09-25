# CheckMenuRadioItem function

## Description

Checks a specified menu item and makes it a radio item. At the same time, the function clears all other menu items in the associated group and clears the radio-item type flag for those items.

## Parameters

### `hmenu` [in]

Type: **HMENU**

A handle to the menu that contains the group of menu items.

### `first` [in]

Type: **UINT**

The identifier or position of the first menu item in the group.

### `last` [in]

Type: **UINT**

The identifier or position of the last menu item in the group.

### `check` [in]

Type: **UINT**

The identifier or position of the menu item to check.

### `flags` [in]

Type: **UINT**

Indicates the meaning of *idFirst*, *idLast*, and *idCheck*. If this parameter is **MF_BYCOMMAND**, the other parameters specify menu item identifiers. If it is **MF_BYPOSITION**, the other parameters specify the menu item positions.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **CheckMenuRadioItem** function sets the **MFT_RADIOCHECK** type flag and the **MFS_CHECKED** state for the item specified by *idCheck* and, at the same time, clears both flags for all other items in the group. The selected item is displayed using a bullet bitmap instead of a check-mark bitmap.

For more information about menu item type and state flags, see the [MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa) structure.

#### Examples

For an example, see Example of [Example of Using Custom Checkmark Bitmaps](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

**Conceptual**

[MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
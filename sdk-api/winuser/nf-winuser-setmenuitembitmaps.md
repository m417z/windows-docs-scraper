# SetMenuItemBitmaps function

## Description

Associates the specified bitmap with a menu item. Whether the menu item is selected or clear, the system displays the appropriate bitmap next to the menu item.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu containing the item to receive new check-mark bitmaps.

### `uPosition` [in]

Type: **UINT**

The menu item to be changed, as determined by the *uFlags* parameter.

### `uFlags` [in]

Type: **UINT**

Specifies how the *uPosition* parameter is to be interpreted. The *uFlags* parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that *uPosition* gives the identifier of the menu item. If neither **MF_BYCOMMAND** nor **MF_BYPOSITION** is specified, **MF_BYCOMMAND** is the default flag. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that *uPosition* gives the zero-based relative position of the menu item. |

### `hBitmapUnchecked` [in, optional]

Type: **HBITMAP**

A handle to the bitmap displayed when the menu item is not selected.

### `hBitmapChecked` [in, optional]

Type: **HBITMAP**

A handle to the bitmap displayed when the menu item is selected.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If either the *hBitmapUnchecked* or
*hBitmapChecked* parameter is **NULL**, the system displays nothing next to the menu item for the corresponding check state. If both parameters are **NULL**, the system displays the default check-mark bitmap when the item is selected, and removes the bitmap when the item is not selected.

When the menu is destroyed, these bitmaps are not destroyed; it is up to the application to destroy them.

The selected and clear bitmaps should be monochrome. The system uses the Boolean AND operator to combine bitmaps with the menu so that the white part becomes transparent and the black part becomes the menu-item color. If you use color bitmaps, the results may be undesirable.

Use the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function with the **SM_CXMENUCHECK** and **SM_CYMENUCHECK** values to retrieve the bitmap dimensions.

#### Examples

For an example, see [Simulating Check Boxes in a Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)
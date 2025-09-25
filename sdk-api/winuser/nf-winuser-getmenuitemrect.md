# GetMenuItemRect function

## Description

Retrieves the bounding rectangle
for the specified menu item.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window containing the menu.

If this value is **NULL** and the *hMenu*
parameter represents a popup menu, the function will find the menu window.

### `hMenu` [in]

Type: **HMENU**

A handle to a menu.

### `uItem` [in]

Type: **UINT**

The zero-based position of the menu item.

### `lprcItem` [out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the
bounding rectangle of the specified menu item expressed in screen coordinates.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error
information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

In order for the returned rectangle to be meaningful, the menu must be popped
up if a popup menu or attached to a window if a menu bar. Menu item positions are not
determined until the menu is displayed.

## See also

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)
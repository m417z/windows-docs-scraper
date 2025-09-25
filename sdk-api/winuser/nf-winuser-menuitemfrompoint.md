# MenuItemFromPoint function

## Description

Determines which menu item, if any, is at the specified location.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window containing the menu. If this value is **NULL** and the *hMenu* parameter represents a popup menu, the function will find the menu window.

### `hMenu` [in]

Type: **HMENU**

A handle to the menu containing the menu items to hit test.

### `ptScreen` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A structure that specifies the location to test. If *hMenu* specifies a menu bar, this parameter is in window coordinates. Otherwise, it is in client coordinates.

## Return value

Type: **int**

Returns the zero-based position of the menu item at the specified location or -1 if no menu item is at the specified location.

## See also

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)
# InsertMenuItemA function

## Description

Inserts a new menu item at the specified position in a menu.

## Parameters

### `hmenu` [in]

Type: **HMENU**

A handle to the menu in which the new menu item is inserted.

### `item` [in]

Type: **UINT**

The identifier or position of the menu item before which to insert the new item. The meaning of this parameter depends on the value of *fByPosition*.

### `fByPosition` [in]

Type: **BOOL**

Controls the meaning of *item*. If this parameter is **FALSE**, *item* is a menu item identifier. Otherwise, it is a menu item position. See [Accessing Menu Items Programmatically](https://learn.microsoft.com/windows/desktop/menurc/about-menus) for more information.

### `lpmi` [in]

Type: **LPCMENUITEMINFO**

A pointer to a [MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa) structure that contains information about the new menu item.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The application must call the [DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar) function whenever a menu changes, whether the menu is in a displayed window.

In order for keyboard accelerators to work with bitmap or owner-drawn menu items, the owner of the menu must process the [WM_MENUCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-menuchar) message. See [Owner-Drawn Menus and the WM_MENUCHAR Message](https://learn.microsoft.com/windows/desktop/menurc/using-menus) for more information.

#### Examples

For an example, see [Example of Menu-Item Bitmaps](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

> [!NOTE]
> The winuser.h header defines InsertMenuItem as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar)

[MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
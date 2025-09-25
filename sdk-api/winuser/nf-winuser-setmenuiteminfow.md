# SetMenuItemInfoW function

## Description

Changes information about a menu item.

## Parameters

### `hmenu` [in]

Type: **HMENU**

A handle to the menu that contains the menu item.

### `item` [in]

Type: **UINT**

The identifier or position of the menu item to change. The meaning of this parameter depends on the value of *fByPositon*.

### `fByPositon` [in]

Type: **BOOL**

The meaning of *uItem*. If this parameter is **FALSE**, *uItem* is a menu item identifier. Otherwise, it is a menu item position. See [About Menus](https://learn.microsoft.com/windows/desktop/menurc/about-menus) for more information. (_Note: this parameter is misspelled in the header; it should be used as shown here._)

### `lpmii` [in]

Type: **LPMENUITEMINFO**

A pointer to a [MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa) structure that contains information about the menu item and specifies which menu item attributes to change.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The application must call the [DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar) function whenever a menu changes, whether the menu is in a displayed window.

In order for keyboard accelerators to work with bitmap or owner-drawn menu items, the owner of the menu must process the [WM_MENUCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-menuchar) message. See [Owner-Drawn Menus and the WM_MENUCHAR Message](https://learn.microsoft.com/windows/desktop/menurc/using-menus) for more information.

#### Examples

For an example, see [Example of Owner-Drawn Menu Items](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

> [!NOTE]
> The winuser.h header defines SetMenuItemInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar)

[GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa)

[MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**
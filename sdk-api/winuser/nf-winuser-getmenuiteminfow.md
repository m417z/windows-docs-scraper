# GetMenuItemInfoW function

## Description

Retrieves information about a menu item.

## Parameters

### `hmenu` [in]

Type: **HMENU**

A handle to the menu that contains the menu item.

### `item` [in]

Type: **UINT**

The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*.

### `fByPosition` [in]

Type: **BOOL**

The meaning of *uItem*. If this parameter is **FALSE**, *uItem* is a menu item identifier. Otherwise, it is a menu item position. See [Accessing Menu Items Programmatically](https://learn.microsoft.com/windows/desktop/menurc/about-menus) for more information.

### `lpmii` [in, out]

Type: **LPMENUITEMINFO**

A pointer to a [MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa) structure that specifies the information to retrieve and receives information about the menu item. Note that you must set the **cbSize** member to `sizeof(MENUITEMINFO)` before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

To retrieve a menu item of type **MFT_STRING**, first find the size of the string by setting the **dwTypeData** member of [MENUITEMINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuiteminfoa) to **NULL** and then calling **GetMenuItemInfo**. The value of **cch**+1 is the size needed. Then allocate a buffer of this size, place the pointer to the buffer in **dwTypeData**, increment **cch** by one, and then call **GetMenuItemInfo** once again to fill the buffer with the string.

If the retrieved menu item is of some other type, then **GetMenuItemInfo** sets the **dwTypeData** member to a value whose type is specified by the **fType****fType** member and sets **cch** to 0.

#### Examples

For an example, see [Example of Owner-Drawn Menu Items](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

> [!NOTE]
> The winuser.h header defines GetMenuItemInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)
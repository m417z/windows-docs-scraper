# DestroyMenu function

## Description

Destroys the specified menu and frees any memory that the menu occupies.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu to be destroyed.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before closing, an application must use the **DestroyMenu** function to destroy a menu not assigned to a window. A menu that is assigned to a window is automatically destroyed when the application closes.

**DestroyMenu** is recursive, that is, it will destroy the menu and all its submenus.

#### Examples

For an example, see [Displaying a Shortcut Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

**Conceptual**

[CreateMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createmenu)

[DeleteMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deletemenu)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[RemoveMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removemenu)

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)
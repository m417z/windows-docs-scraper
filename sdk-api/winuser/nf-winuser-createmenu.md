# CreateMenu function

## Description

Creates a menu. The menu is initially empty, but it can be filled with menu items by using the [InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema), [AppendMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-appendmenua), and [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua) functions.

## Return value

Type: **HMENU**

If the function succeeds, the return value is a handle to the newly created menu.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Resources associated with a menu that is assigned to a window are freed automatically. If the menu is not assigned to a window, an application must free system resources associated with the menu before closing. An application frees menu resources by calling the [DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu) function.

## See also

[AppendMenu](https://learn.microsoft.com/windows/desktop/menurc/u)

**Conceptual**

[CreatePopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createpopupmenu)

[DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu)

[InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenu)
# CreatePopupMenu function

## Description

Creates a drop-down menu, submenu, or shortcut menu. The menu is initially empty. You can insert or append menu items by using the [InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema) function. You can also use the [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua) function to insert menu items and the [AppendMenu](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-appendmenua) function to append menu items.

## Return value

Type: **HMENU**

If the function succeeds, the return value is a handle to the newly created menu.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The application can add the new menu to an existing menu, or it can display a shortcut menu by calling the [TrackPopupMenuEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex) or [TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) functions.

Resources associated with a menu that is assigned to a window are freed automatically. If the menu is not assigned to a window, an application must free system resources associated with the menu before closing. An application frees menu resources by calling the [DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu) function.

#### Examples

For an example, see [Adding Lines and Graphs to a Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

[AppendMenu](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-appendmenua)

**Conceptual**

[CreateMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createmenu)

[DestroyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroymenu)

[InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenu)

[TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu)

[TrackPopupMenuEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex)
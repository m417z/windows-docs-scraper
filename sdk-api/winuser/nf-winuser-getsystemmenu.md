# GetSystemMenu function

## Description

Enables the application to access the window menu (also known as the system menu or the control menu) for copying and modifying.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window that will own a copy of the window menu.

### `bRevert` [in]

Type: **BOOL**

The action to be taken. If this parameter is **FALSE**, **GetSystemMenu** returns a handle to the copy of the window menu currently in use. The copy is initially identical to the window menu, but it can be modified. If this parameter is **TRUE**, **GetSystemMenu** resets the window menu back to the default state. The previous window menu, if any, is destroyed.

## Return value

Type: **HMENU**

If the *bRevert* parameter is **FALSE**, the return value is a handle to a copy of the window menu. If the *bRevert* parameter is **TRUE**, the return value is **NULL**.

## Remarks

Any window that does not use the **GetSystemMenu** function to make its own copy of the window menu receives the standard window menu.

The window menu initially contains items with various identifier values, such as **SC_CLOSE**, **SC_MOVE**, and **SC_SIZE**.

Menu items on the window menu send [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) messages.

All predefined window menu items have identifier numbers greater than 0xF000. If an application adds commands to the window menu, it should use identifier numbers less than 0xF000.

The system automatically grays items on the standard window menu, depending on the situation. The application can perform its own checking or graying by responding to the [WM_INITMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenu) message that is sent before any menu is displayed.

## See also

**Conceptual**

[GetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenu)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)

[WM_INITMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenu)

[WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand)
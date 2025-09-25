# TrackPopupMenuEx function

## Description

Displays a shortcut menu at the specified location and tracks the selection of items on the shortcut menu. The shortcut menu can appear anywhere on the screen.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the shortcut menu to be displayed. This handle can be obtained by calling the [CreatePopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createpopupmenu) function to create a new shortcut menu or by calling the [GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu) function to retrieve a handle to a submenu associated with an existing menu item.

### `uFlags` [in]

Type: **UINT**

Specifies function options.

Use one of the following flags to specify how the function positions the shortcut menu horizontally.

| Value | Meaning |
| --- | --- |
| **TPM_CENTERALIGN**<br><br>0x0004L | Centers the shortcut menu horizontally relative to the coordinate specified by the *x* parameter. |
| **TPM_LEFTALIGN**<br><br>0x0000L | Positions the shortcut menu so that its left side is aligned with the coordinate specified by the *x* parameter. |
| **TPM_RIGHTALIGN**<br><br>0x0008L | Positions the shortcut menu so that its right side is aligned with the coordinate specified by the *x* parameter. |

Use one of the following flags to specify how the function positions the shortcut menu vertically.

| Value | Meaning |
| --- | --- |
| **TPM_BOTTOMALIGN**<br><br>0x0020L | Positions the shortcut menu so that its bottom side is aligned with the coordinate specified by the *y* parameter. |
| **TPM_TOPALIGN**<br><br>0x0000L | Positions the shortcut menu so that its top side is aligned with the coordinate specified by the *y* parameter. |
| **TPM_VCENTERALIGN**<br><br>0x0010L | Centers the shortcut menu vertically relative to the coordinate specified by the *y* parameter. |

Use the following flags to control discovery of the user selection without having to set up a parent window for the menu.

| Value | Meaning |
| --- | --- |
| **TPM_NONOTIFY**<br><br>0x0080L | The function does not send notification messages when the user clicks a menu item. |
| **TPM_RETURNCMD**<br><br>0x0100L | The function returns the menu item identifier of the user's selection in the return value. |

Use one of the following flags to specify which mouse button the shortcut menu tracks.

| Value | Meaning |
| --- | --- |
| **TPM_LEFTBUTTON**<br><br>0x0000L | The user can select menu items with only the left mouse button. |
| **TPM_RIGHTBUTTON**<br><br>0x0002L | The user can select menu items with both the left and right mouse buttons. |

Use any reasonable combination of the following flags to modify the animation of a menu. For example, by selecting a horizontal and a vertical flag, you can achieve diagonal animation.

| Value | Meaning |
| --- | --- |
| **TPM_HORNEGANIMATION**<br><br>0x0800L | Animates the menu from right to left. |
| **TPM_HORPOSANIMATION**<br><br>0x0400L | Animates the menu from left to right. |
| **TPM_NOANIMATION**<br><br>0x4000L | Displays menu without animation. |
| **TPM_VERNEGANIMATION**<br><br>0x2000L | Animates the menu from bottom to top. |
| **TPM_VERPOSANIMATION**<br><br>0x1000L | Animates the menu from top to bottom. |

For any animation to occur, the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function must set **SPI_SETMENUANIMATION**. Also, all the **TPM_*ANIMATION** flags, except **TPM_NOANIMATION**, are ignored if menu fade animation is on. For more information, see the **SPI_GETMENUFADE** flag in **SystemParametersInfo**.

 Use the **TPM_RECURSE** flag to display a menu when another menu is already displayed. This is intended to support context menus within a menu.

Use one of the following flags to specify whether to accommodate horizontal or vertical alignment.

| Value | Meaning |
| --- | --- |
| **TPM_HORIZONTAL**<br><br>0x0000L | If the menu cannot be shown at the specified location without overlapping the excluded rectangle, the system tries to accommodate the requested horizontal alignment before the requested vertical alignment. |
| **TPM_VERTICAL**<br><br>0x0040L | If the menu cannot be shown at the specified location without overlapping the excluded rectangle, the system tries to accommodate the requested vertical alignment before the requested horizontal alignment. |

The excluded rectangle is a portion of the screen that the menu should not overlap; it is specified by the *lptpm* parameter.

 For right-to-left text layout, use **TPM_LAYOUTRTL**. By default, the text layout is left-to-right.

### `x` [in]

Type: **int**

The horizontal location of the shortcut menu, in screen coordinates.

### `y` [in]

Type: **int**

The vertical location of the shortcut menu, in screen coordinates.

### `hwnd` [in]

Type: **HWND**

A handle to the window that owns the shortcut menu. This window receives all messages from the menu. The window does not receive a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message from the menu until the function returns. If you specify TPM_NONOTIFY in the *fuFlags* parameter, the function does not send messages to the window identified by *hwnd*. However, you must still pass a window handle in *hwnd*. It can be any window handle from your application.

### `lptpm` [in, optional]

Type: **LPTPMPARAMS**

A pointer to a [TPMPARAMS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-tpmparams) structure that specifies an area of the screen the menu should not overlap. This parameter can be **NULL**.

## Return value

Type: **BOOL**

If you specify **TPM_RETURNCMD** in the *fuFlags* parameter, the return value is the menu-item identifier of the item that the user selected. If the user cancels the menu without making a selection, or if an error occurs, the return value is zero.

If you do not specify **TPM_RETURNCMD** in the *fuFlags* parameter, the return value is nonzero if the function succeeds and zero if it fails. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) with **SM_MENUDROPALIGNMENT** to determine the correct horizontal alignment flag (**TPM_LEFTALIGN** or **TPM_RIGHTALIGN**) and/or horizontal animation direction flag (**TPM_HORPOSANIMATION** or **TPM_HORNEGANIMATION**) to pass to [TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) or **TrackPopupMenuEx**. This is essential for creating an optimal user experience, especially when developing Microsoft Tablet PC applications.

To display a context menu for a notification icon, the current window must be the foreground window before the application calls [TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) or **TrackPopupMenuEx**. Otherwise, the menu will not disappear when the user clicks outside of the menu or the window that created the menu (if it is visible). If the current window is a child window, you must set the (top-level) parent window as the foreground window.

## See also

**Conceptual**

[CreatePopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createpopupmenu)

[GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[TPMPARAMS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-tpmparams)

[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command)
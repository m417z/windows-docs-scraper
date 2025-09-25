# InsertMenuA function

## Description

Inserts a new menu item into a menu, moving other items down the menu.

**Note** The **InsertMenu** function has been superseded by the [InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema) function. You can still use **InsertMenu**, however, if you do not need any of the extended features of **InsertMenuItem**.

## Parameters

### `hMenu` [in]

Type: **HMENU**

A handle to the menu to be changed.

### `uPosition` [in]

Type: **UINT**

The menu item before which the new menu item is to be inserted, as determined by the *uFlags* parameter.

### `uFlags` [in]

Type: **UINT**

Controls the interpretation of the *uPosition* parameter and the content, appearance, and behavior of the new menu item. This parameter must include one of the following required values.

| Value | Meaning |
| --- | --- |
| **MF_BYCOMMAND**<br><br>0x00000000L | Indicates that the *uPosition* parameter gives the identifier of the menu item. The **MF_BYCOMMAND** flag is the default if neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified. |
| **MF_BYPOSITION**<br><br>0x00000400L | Indicates that the *uPosition* parameter gives the zero-based relative position of the new menu item. If *uPosition* is -1, the new menu item is appended to the end of the menu. |

The parameter must also include at least one of the following values.

| Value | Meaning |
| --- | --- |
| **MF_BITMAP**<br><br>0x00000004L | Uses a bitmap as the menu item. The *lpNewItem* parameter contains a handle to the bitmap. |
| **MF_CHECKED**<br><br>0x00000008L | Places a check mark next to the menu item. If the application provides check-mark bitmaps (see [SetMenuItemBitmaps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuitembitmaps)), this flag displays the check-mark bitmap next to the menu item. |
| **MF_DISABLED**<br><br>0x00000002L | Disables the menu item so that it cannot be selected, but does not gray it. |
| **MF_ENABLED**<br><br>0x00000000L | Enables the menu item so that it can be selected and restores it from its grayed state. |
| **MF_GRAYED**<br><br>0x00000001L | Disables the menu item and grays it so it cannot be selected. |
| **MF_MENUBARBREAK**<br><br>0x00000020L | Functions the same as the **MF_MENUBREAK** flag for a menu bar. For a drop-down menu, submenu, or shortcut menu, the new column is separated from the old column by a vertical line. |
| **MF_MENUBREAK**<br><br>0x00000040L | Places the item on a new line (for menu bars) or in a new column (for a drop-down menu, submenu, or shortcut menu) without separating columns. |
| **MF_OWNERDRAW**<br><br>0x00000100L | Specifies that the item is an owner-drawn item. Before the menu is displayed for the first time, the window that owns the menu receives a [WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem) message to retrieve the width and height of the menu item. The [WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem) message is then sent to the window procedure of the owner window whenever the appearance of the menu item must be updated. |
| **MF_POPUP**<br><br>0x00000010L | Specifies that the menu item opens a drop-down menu or submenu. The *uIDNewItem* parameter specifies a handle to the drop-down menu or submenu. This flag is used to add a menu name to a menu bar or a menu item that opens a submenu to a drop-down menu, submenu, or shortcut menu. |
| **MF_SEPARATOR**<br><br>0x00000800L | Draws a horizontal dividing line. This flag is used only in a drop-down menu, submenu, or shortcut menu. The line cannot be grayed, disabled, or highlighted. The *lpNewItem* and *uIDNewItem* parameters are ignored. |
| **MF_STRING**<br><br>0x00000000L | Specifies that the menu item is a text string; the *lpNewItem* parameter is a pointer to the string. |
| **MF_UNCHECKED**<br><br>0x00000000L | Does not place a check mark next to the menu item (default). If the application supplies check-mark bitmaps (see the [SetMenuItemBitmaps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuitembitmaps) function), this flag displays the clear bitmap next to the menu item. |

### `uIDNewItem` [in]

Type: **UINT_PTR**

The identifier of the new menu item or, if the *uFlags* parameter has the **MF_POPUP** flag set, a handle to the drop-down menu or submenu.

### `lpNewItem` [in, optional]

Type: **LPCTSTR**

The content of the new menu item. The interpretation of *lpNewItem* depends on whether the *uFlags* parameter includes the **MF_BITMAP**, **MF_OWNERDRAW**, or **MF_STRING** flag, as follows.

| Value | Meaning |
| --- | --- |
| **MF_BITMAP**<br><br>0x00000004L | Contains a bitmap handle. |
| **MF_OWNERDRAW**<br><br>0x00000100L | Contains an application-supplied value that can be used to maintain additional data related to the menu item. The value is in the **itemData** member of the structure pointed to by the *lParam* parameter of the [WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem) or [WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem) message sent when the menu item is created or its appearance is updated. |
| **MF_STRING**<br><br>0x00000000L | Contains a pointer to a null-terminated string (the default). |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The application must call the [DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar) function whenever a menu changes, whether the menu is in a displayed window.

The following groups of flags cannot be used together:

* **MF_BYCOMMAND** and **MF_BYPOSITION**
* **MF_DISABLED**, **MF_ENABLED**, and **MF_GRAYED**
* **MF_BITMAP**, **MF_STRING**, **MF_OWNERDRAW**, and **MF_SEPARATOR**
* **MF_MENUBARBREAK** and **MF_MENUBREAK**
* **MF_CHECKED** and **MF_UNCHECKED**

> [!NOTE]
> The winuser.h header defines InsertMenu as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AppendMenu](https://learn.microsoft.com/windows/desktop/menurc/u)

**Conceptual**

[DeleteMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deletemenu)

[DrawMenuBar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawmenubar)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

[ModifyMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-modifymenua)

**Other Resources**

**Reference**

[RemoveMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removemenu)

[SetMenuItemBitmaps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuitembitmaps)

[WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem)

[WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem)
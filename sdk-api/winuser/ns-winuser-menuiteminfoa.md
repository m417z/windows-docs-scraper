# MENUITEMINFOA structure

## Description

Contains information about a menu item.

## Members

### `cbSize`

Type: **UINT**

The size of the structure, in bytes. The caller must set this member to `sizeof(MENUITEMINFO)`.

### `fMask`

Type: **UINT**

Indicates the members to be retrieved or set. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MIIM_BITMAP**<br><br>0x00000080 | Retrieves or sets the **hbmpItem** member. |
| **MIIM_CHECKMARKS**<br><br>0x00000008 | Retrieves or sets the **hbmpChecked** and **hbmpUnchecked** members. |
| **MIIM_DATA**<br><br>0x00000020 | Retrieves or sets the **dwItemData** member. |
| **MIIM_FTYPE**<br><br>0x00000100 | Retrieves or sets the **fType** member. |
| **MIIM_ID**<br><br>0x00000002 | Retrieves or sets the **wID** member. |
| **MIIM_STATE**<br><br>0x00000001 | Retrieves or sets the **fState** member. |
| **MIIM_STRING**<br><br>0x00000040 | Retrieves or sets the **dwTypeData** member. |
| **MIIM_SUBMENU**<br><br>0x00000004 | Retrieves or sets the **hSubMenu** member. |
| **MIIM_TYPE**<br><br>0x00000010 | Retrieves or sets the **fType** and **dwTypeData** members.<br><br>**MIIM_TYPE** is replaced by **MIIM_BITMAP**, **MIIM_FTYPE**, and **MIIM_STRING**. |

### `fType`

Type: **UINT**

The menu item type. This member can be one or more of the following values.

The **MFT_BITMAP**, **MFT_SEPARATOR**, and **MFT_STRING** values cannot be combined with one another. Set
**fMask** to **MIIM_TYPE** to use
**fType**.

**fType** is used only if
**fMask** has a value of **MIIM_FTYPE**.

| Value | Meaning |
| --- | --- |
| **MFT_BITMAP**<br><br>0x00000004L | Displays the menu item using a bitmap. The low-order word of the **dwTypeData** member is the bitmap handle, and the **cch** member is ignored.<br><br>**MFT_BITMAP** is replaced by **MIIM_BITMAP** and **hbmpItem**. |
| **MFT_MENUBARBREAK**<br><br>0x00000020L | Places the menu item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or shortcut menu). For a drop-down menu, submenu, or shortcut menu, a vertical line separates the new column from the old. |
| **MFT_MENUBREAK**<br><br>0x00000040L | Places the menu item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or shortcut menu). For a drop-down menu, submenu, or shortcut menu, the columns are not separated by a vertical line. |
| **MFT_OWNERDRAW**<br><br>0x00000100L | Assigns responsibility for drawing the menu item to the window that owns the menu. The window receives a [WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem) message before the menu is displayed for the first time, and a [WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem) message whenever the appearance of the menu item must be updated. If this value is specified, the **dwTypeData** member contains an application-defined value. |
| **MFT_RADIOCHECK**<br><br>0x00000200L | Displays selected menu items using a radio-button mark instead of a check mark if the **hbmpChecked** member is **NULL**. |
| **MFT_RIGHTJUSTIFY**<br><br>0x00004000L | Right-justifies the menu item and any subsequent items. This value is valid only if the menu item is in a menu bar. |
| **MFT_RIGHTORDER**<br><br>0x00002000L | Specifies that menus cascade right-to-left (the default is left-to-right). This is used to support right-to-left languages, such as Arabic and Hebrew. |
| **MFT_SEPARATOR**<br><br>0x00000800L | Specifies that the menu item is a separator. A menu item separator appears as a horizontal dividing line. The **dwTypeData** and **cch** members are ignored. This value is valid only in a drop-down menu, submenu, or shortcut menu. |
| **MFT_STRING**<br><br>0x00000000L | Displays the menu item using a text string. The **dwTypeData** member is the pointer to a null-terminated string, and the **cch** member is the length of the string.<br><br>**MFT_STRING** is replaced by **MIIM_STRING**. |

### `fState`

Type: **UINT**

The menu item state. This member can be one or more of these values. Set
**fMask** to **MIIM_STATE** to use
**fState**.

| Value | Meaning |
| --- | --- |
| **MFS_CHECKED**<br><br>0x00000008L | Checks the menu item. For more information about selected menu items, see the **hbmpChecked** member. |
| **MFS_DEFAULT**<br><br>0x00001000L | Specifies that the menu item is the default. A menu can contain only one default menu item, which is displayed in bold. |
| **MFS_DISABLED**<br><br>0x00000003L | Disables the menu item and grays it so that it cannot be selected. This is equivalent to **MFS_GRAYED**. |
| **MFS_ENABLED**<br><br>0x00000000L | Enables the menu item so that it can be selected. This is the default state. |
| **MFS_GRAYED**<br><br>0x00000003L | Disables the menu item and grays it so that it cannot be selected. This is equivalent to **MFS_DISABLED**. |
| **MFS_HILITE**<br><br>0x00000080L | Highlights the menu item. |
| **MFS_UNCHECKED**<br><br>0x00000000L | Unchecks the menu item. For more information about clear menu items, see the **hbmpChecked** member. |
| **MFS_UNHILITE**<br><br>0x00000000L | Removes the highlight from the menu item. This is the default state. |

### `wID`

Type: **UINT**

An application-defined value that identifies the menu item. Set
**fMask** to **MIIM_ID** to use
**wID**.

### `hSubMenu`

Type: **HMENU**

A handle to the drop-down menu or submenu associated with the menu item. If the menu item is not an item that opens a drop-down menu or submenu, this member is **NULL**. Set
**fMask** to **MIIM_SUBMENU** to use
**hSubMenu**.

### `hbmpChecked`

Type: **HBITMAP**

A handle to the bitmap to display next to the item if it is selected. If this member is **NULL**, a default bitmap is used. If the **MFT_RADIOCHECK** type value is specified, the default bitmap is a bullet. Otherwise, it is a check mark. Set
**fMask** to **MIIM_CHECKMARKS** to use
**hbmpChecked**.

### `hbmpUnchecked`

Type: **HBITMAP**

A handle to the bitmap to display next to the item if it is not selected. If this member is **NULL**, no bitmap is used. Set
**fMask** to **MIIM_CHECKMARKS** to use
**hbmpUnchecked**.

### `dwItemData`

Type: **ULONG_PTR**

An application-defined value associated with the menu item. Set
**fMask** to **MIIM_DATA** to use
**dwItemData**.

### `dwTypeData`

Type: **LPTSTR**

The contents of the menu item. The meaning of this member depends on the value of
**fType** and is used only if the **MIIM_TYPE** flag is set in the
**fMask** member.

To retrieve a menu item of type **MFT_STRING**, first find the size of the string by setting the
**dwTypeData** member of **MENUITEMINFO** to **NULL** and then calling [GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa). The value of
**cch**+1 is the size needed. Then allocate a buffer of this size, place the pointer to the buffer in
**dwTypeData**, increment **cch**, and call **GetMenuItemInfo** once again to fill the buffer with the string. If the retrieved menu item is of some other type, then **GetMenuItemInfo** sets the
**dwTypeData** member to a value whose type is specified by the
**fType** member.

When using with the [SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa) function, this member should contain a value whose type is specified by the
**fType** member.

**dwTypeData** is used only if the **MIIM_STRING** flag is set in the
**fMask** member

### `cch`

Type: **UINT**

The length of the menu item text, in
characters, when information is received about a menu item of the **MFT_STRING** type. However, **cch** is used only if the **MIIM_TYPE** flag is set in the
**fMask** member and is zero otherwise. Also, **cch** is ignored when the content of a menu item is set by calling [SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa).

Note that, before calling [GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa), the application must set **cch** to the length of the buffer pointed to by the
**dwTypeData** member. If the retrieved menu item is of type **MFT_STRING** (as indicated by the
**fType** member), then **GetMenuItemInfo** changes
**cch** to the length of the menu item text. If the retrieved menu item is of some other type, **GetMenuItemInfo** sets the
**cch** field to zero.

The
**cch** member is used when the **MIIM_STRING** flag is set in the
**fMask** member.

### `hbmpItem`

Type: **HBITMAP**

A
handle to the bitmap to be displayed, or it can be one of the values in the following table. It is used when the **MIIM_BITMAP** flag is set in the
**fMask** member.

| Value | Meaning |
| --- | --- |
| **HBMMENU_CALLBACK**<br><br>((HBITMAP) -1) | A bitmap that is drawn by the window that owns the menu. The application must process the [WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem) and [WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem) messages. |
| **HBMMENU_MBAR_CLOSE**<br><br>((HBITMAP) 5) | Close button for the menu bar. |
| **HBMMENU_MBAR_CLOSE_D**<br><br>((HBITMAP) 6) | Disabled close button for the menu bar. |
| **HBMMENU_MBAR_MINIMIZE**<br><br>((HBITMAP) 3) | Minimize button for the menu bar. |
| **HBMMENU_MBAR_MINIMIZE_D**<br><br>((HBITMAP) 7) | Disabled minimize button for the menu bar. |
| **HBMMENU_MBAR_RESTORE**<br><br>((HBITMAP) 2) | Restore button for the menu bar. |
| **HBMMENU_POPUP_CLOSE**<br><br>((HBITMAP) 8) | Close button for the submenu. |
| **HBMMENU_POPUP_MAXIMIZE**<br><br>((HBITMAP) 10) | Maximize button for the submenu. |
| **HBMMENU_POPUP_MINIMIZE**<br><br>((HBITMAP) 11) | Minimize button for the submenu. |
| **HBMMENU_POPUP_RESTORE**<br><br>((HBITMAP) 9) | Restore button for the submenu. |
| **HBMMENU_SYSTEM**<br><br>((HBITMAP) 1) | Windows icon or the icon of the window specified in **dwItemData**. |

## Remarks

The **MENUITEMINFO** structure is used with the [GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa), [InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema), and [SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa) functions.

The menu can display items using text, bitmaps, or both.

> [!NOTE]
> The winuser.h header defines MENUITEMINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa)

[InsertMenuItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenuitema)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuItemInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa)

[WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem)

[WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem)
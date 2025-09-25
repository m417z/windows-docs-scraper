# HELPINFO structure

## Description

Contains information about an item for which context-sensitive help has been requested.

## Members

### `cbSize`

Type: **UINT**

The structure size, in bytes.

### `iContextType`

Type: **int**

The type of context for which help is requested. This member can be one of the following values.

- **HELPINFO_MENUITEM**: Help requested for a menu item.

- **HELPINFO_WINDOW**: Help requested for a control or window.

### `iCtrlId`

Type: **int**

The identifier of the window or control if **iContextType** is **HELPINFO_WINDOW**, or identifier of the menu item if **iContextType** is **HELPINFO_MENUITEM**.

### `hItemHandle`

Type: **HANDLE**

The identifier of the child window or control if **iContextType** is **HELPINFO_WINDOW**, or identifier of the associated menu if **iContextType** is **HELPINFO_MENUITEM**.

### `dwContextId`

Type: **DWORD**

The help context identifier of the window or control.

### `MousePos`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the screen coordinates of the mouse cursor. This is useful for providing help based on the position of the mouse cursor.
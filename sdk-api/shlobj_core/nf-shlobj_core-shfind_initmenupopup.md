# SHFind_InitMenuPopup function

## Description

[**SHFind_InitMenuPopup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves the [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) instance for the submenu of options displayed for the **Search** entry in the Classic style Start menu.

## Parameters

### `hmenu` [in]

Type: **HMENU**

The handle of the popup menu.

### `hwndOwner` [in, optional]

Type: **HWND**

The handle of the popup menu's owner window. This value can be **NULL**.

### `idCmdFirst`

Type: **UINT**

The ID of the first menu item.

### `idCmdLast`

Type: **UINT**

The ID of the last menu item.

## Return value

Type: **[IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu)***

If successful, returns an [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) pointer. On failure, returns **NULL**.
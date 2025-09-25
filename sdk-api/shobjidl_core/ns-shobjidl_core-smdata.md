# SMDATA structure

## Description

Contains information from a menu band.

## Members

### `dwMask`

Type: **DWORD**

A mask that is always set to SMDM_HMENU.

### `dwFlags`

Type: **DWORD**

### `hmenu`

Type: **HMENU**

The static menu portion of the menu band.

### `hwnd`

Type: **HWND**

The HWND value of the owner window.

### `uId`

Type: **UINT**

The identifier of the menu item. This value is -1 for the menu itself.

### `uIdParent`

Type: **UINT**

The identifier of the parent menu.

### `uIdAncestor`

Type: **UINT**

### `punk`

Type: **IUnknown***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the [MenuBand](https://learn.microsoft.com/windows/desktop/shell/profiles-directory) object.

### `pidlFolder`

Type: **PIDLIST_ABSOLUTE**

The [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) of the shell folder portion of the menu.

### `pidlItem`

Type: **PUITEMID_CHILD**

The [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) of the selected item in the shell folder portion of the menu.

### `psf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface for the folder associated with the shell folder portion of the menu.

### `pvUserData`

Type: **void***

A pointer to a user-defined data structure.
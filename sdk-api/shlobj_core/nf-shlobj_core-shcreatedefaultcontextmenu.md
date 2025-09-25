# SHCreateDefaultContextMenu function

## Description

Creates an object that represents the Shell's default context menu implementation.

## Parameters

### `pdcm` [in]

Type: **const [DEFCONTEXTMENU](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-defcontextmenu)***

A pointer to a constant [DEFCONTEXTMENU](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-defcontextmenu) structure.

### `riid`

Type: **REFIID**

Reference to the interface ID of the interface on which to base the object. This is typically the IID of [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu), [IContextMenu2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu2), or [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3).

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is typically used in the implementation of [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof). **GetUIObjectOf** creates a context menu that merges [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) handlers specified by the [DEFCONTEXTMENU](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-defcontextmenu) structure, and can optionally provide default context menu verb implementations such as open, explore, delete, and copy.

The operation of this function is controlled by the input specified in the [DEFCONTEXTMENU](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-defcontextmenu) structure.The API[CDefFolderMenu_Create2](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-cdeffoldermenu_create2) is another way to construct the default context menu implementation. It is less expressive than **SHCreateDefaultContextMenu** but it exists in platforms prior to Windows Vista.
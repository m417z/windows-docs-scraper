# INameSpaceTreeControlEvents::OnBeforeContextMenu

## Description

Called before a context menu is displayed; allows client to add additional menu entries.

## Parameters

### `psi` [in, optional]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) from which the context menu is generated. This value can be **NULL**.

### `riid` [in]

Type: **REFIID**

Reference to the IID of the context menu.

### `ppv` [out]

Type: **void****

When this methods returns, contains the address of a pointer to the interface specified by *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControlEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolevents)
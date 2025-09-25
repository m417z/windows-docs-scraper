# IShellItemResources::CreateResource

## Description

Creates a specified resource.

## Parameters

### `pcsir` [in]

Type: **const [SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource)***

A pointer to an [SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource) resource.

### `riid` [in]

Type: **REFIID**

A reference to a desired IID.

### `ppv` [out]

Type: **void****

The address of a pointer to the resource.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
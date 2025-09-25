# IShellItemResources::GetResourceDescription

## Description

Gets a resource description.

## Parameters

### `pcsir`

Type: **const [SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource)***

A pointer to a [SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource) resource.

### `ppszDescription` [out]

Type: **LPWSTR***

A pointer to a resource description as a Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
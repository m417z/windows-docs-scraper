# IEnumResources::Next

## Description

Gets the next [SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource) structure.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of resources requested. Currently, must be 1.

### `psir` [out]

Type: **[SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource)***

Receives a pointer to a [SHELL_ITEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shell_item_resource) structure.

### `pceltFetched` [out]

Type: **ULONG***

A pointer to the number of resources retrieved. Currently, not used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
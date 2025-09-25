# INameSpaceTreeControl::GetItemCustomState

## Description

Gets the state of the checkbox associated with a given Shell item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the Shell item for which checkbox state is being retrieved.

### `piStateNumber` [out]

Type: **int***

A pointer to the state of the checkbox for the Shell item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
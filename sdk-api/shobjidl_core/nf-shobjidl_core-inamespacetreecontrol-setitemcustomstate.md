# INameSpaceTreeControl::SetItemCustomState

## Description

Sets the state of the checkbox associated with the Shell item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the Shell item for which checkbox state
is being set.

### `iStateNumber` [in]

Type: **int**

The desired state of the checkbox for the Shell item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
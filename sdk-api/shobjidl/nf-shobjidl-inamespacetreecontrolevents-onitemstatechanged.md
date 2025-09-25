# INameSpaceTreeControlEvents::OnItemStateChanged

## Description

Not implemented.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the shell item for which the state has changed.

### `nstcisMask` [in]

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)**

One or more values from the [NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate) enumeration that indicates what pieces of information the caller wants to set.

### `nstcisState` [in]

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)**

One or more values from the [NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate) enumeration that indicates the values that are to be set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
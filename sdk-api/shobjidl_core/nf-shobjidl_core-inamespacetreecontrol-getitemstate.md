# INameSpaceTreeControl::GetItemState

## Description

Gets state information about a Shell item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the Shell item from which to retrieve the state.

### `nstcisMask` [in]

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)**

Specifies which information is being requested, in the form of a bitmap. One or more of the [NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate) constants.

### `pnstcisFlags` [out]

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)***

When this method returns, points to a bitmap that contains the values requested in *nstcisMask*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *nstcisMask* value specifies which bits in the value pointed to by *pnstcisFlags* are requested. As a simple example, if *nstcisMask*=NSTCIS_SELECTED, then only the first bit in the value pointed to by *pnstcisFlags* is valid when this method returns. If the first bit in the value pointed to by *pnstcisFlags* is 1, then the NSTCIS_SELECTED flag is set. If the first bit in the value pointed to by *pnstcisFlags* is 0, then the NSTCIS_SELECTED flag is not set.
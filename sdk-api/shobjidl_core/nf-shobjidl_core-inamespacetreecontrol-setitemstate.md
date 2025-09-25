# INameSpaceTreeControl::SetItemState

## Description

Sets state information for a Shell item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the Shell item for which to set the state.

### `nstcisMask` [in]

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)**

Specifies which information is being set, in the form of a bitmap. One or more of the [NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate) constants.

### `nstcisFlags` [in]

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)**

A bitmap that contains the values to set for the flags specified in *nstcisMask*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *nstcisMask* value specifies which bits in the value pointed to by *pnstcisFlags* are to be set. Other bits are ignored. As a simple example, if *nstcisMask*=NSTCIS_SELECTED, then the first bit in the *nstcisFlags* value determines whether that flag is set (1) or removed (0).
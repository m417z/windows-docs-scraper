# INameSpaceTreeControl2::GetControlStyle2

## Description

Gets the extended display styles set for the namespace object's treeview controls.

## Parameters

### `nstcsMask` [in]

Type: **[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)**

One or more of the [NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2) constants that specify the values for which the method should retrieve the current settings.

### `pnstcsStyle` [out]

Type: **[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)***

Pointer to a value that, when this method returns successfully, receives the values requested in *nstcsMask*. If the bit that represents the individual [NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2) value is 0, that value is not set. If the value is 1, it is the current setting. Bit values in positions not specifically requested in *nstcsMask* do not necessarily reflect the current settings and should not be used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControl2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrol2)

[INameSpaceTreeControl2::GetControlStyle](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-getcontrolstyle)

[INameSpaceTreeControl2::SetControlStyle2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-setcontrolstyle2)

[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)
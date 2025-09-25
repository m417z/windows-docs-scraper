# INameSpaceTreeControl2::GetControlStyle

## Description

Gets the display styles set for the namespace object's treeview controls.

## Parameters

### `nstcsMask` [in]

Type: **[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)**

One or more of the [NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle) constants that specify the values for which the method should retrieve the current settings.

### `pnstcsStyle` [out]

Type: **[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)***

Pointer to a value that, when this method returns successfully, receives the values requested in *nstcsMask*. If the bit that represents the individual [NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle) value is 0, that value is not set. If the value is 1, it is the current setting. Bit values in positions not specifically requested in *nstcsMask* do not necessarily reflect the current settings and should not be used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControl2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrol2)

[INameSpaceTreeControl2::GetControlStyle2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-getcontrolstyle2)

[INameSpaceTreeControl2::SetControlStyle](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-setcontrolstyle)

[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)
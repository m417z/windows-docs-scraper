# INameSpaceTreeControl2::SetControlStyle

## Description

Sets the display styles for the namespace object's treeview controls.

## Parameters

### `nstcsMask` [in]

Type: **[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)**

One or more of the [NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle) constants that specify the styles for which the method should set new values.

### `nstcsStyle` [in]

Type: **[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)**

A bitmap that contains the new values for the styles specified in *nstcsMask*. If the bit that represents the individual [NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle) value is 0, that style is not used. If the value is 1, the style is applied to the treeview. Styles in positions not specified in *nstcsMask* are left at their current setting regardless of their bit's value in this bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControl2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrol2)

[INameSpaceTreeControl2::GetControlStyle](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-getcontrolstyle)

[INameSpaceTreeControl2::SetControlStyle2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-setcontrolstyle2)

[NSTCSTYLE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcstyle)
# INameSpaceTreeControl2::SetControlStyle2

## Description

Sets the extended display styles for the namespace object's treeview controls.

## Parameters

### `nstcsMask` [in]

Type: **[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)**

One or more of the [NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2) constants that specify the styles for which the method should set new values.

### `nstcsStyle` [in]

Type: **[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)**

A bitmap that contains the new values for the styles specified in *nstcsMask*. If the bit that represents the individual [NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2) value is 0, that style is not used. If the value is 1, the style is applied to the treeview. Styles in positions not specified in *nstcsMask* are left at their current setting regardless of their bit's value in this bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[INameSpaceTreeControl2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrol2)

[INameSpaceTreeControl2::GetControlStyle2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-getcontrolstyle2)

[INameSpaceTreeControl2::SetControlStyle](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-setcontrolstyle)

[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)
# INameSpaceTreeControlEvents::OnGetToolTip

## Description

Enables you to provide a tooltip.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that contains the tooltip.

### `pszTip` [out]

Type: **LPWSTR**

When this method returns, contains the text of the tooltip.

### `cchTip` [in]

Type: **int**

The size of the tooltip in characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method returns S_OK, the client provides its own tooltip. Otherwise the [INameSpaceTreeControl](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacetreecontrol) will extract one.

## See also

[INameSpaceTreeControlEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolevents)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)
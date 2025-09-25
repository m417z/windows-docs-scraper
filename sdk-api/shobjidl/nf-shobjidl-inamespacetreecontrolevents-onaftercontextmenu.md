# INameSpaceTreeControlEvents::OnAfterContextMenu

## Description

Called after a context menu is displayed.

## Parameters

### `psi` [in, optional]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) from which the context menu is generated. This value can be **NULL** only if the [NSTCS2_SHOWNULLSPACEMENU](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2) flag is set.

### `pcmIn` [in]

Type: **[IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu)***

A pointer to the context menu.

### `riid` [in]

Type: **REFIID**

Reference to the IID of the context menu.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the interface specified in *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method allows client to completely replace the context menu. This method will allow the client to use the context menu returned by *ppv* and not necessarily the one specified in *pcmIn*.

## See also

[INameSpaceTreeControlEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolevents)

[NSTCSTYLE2](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-nstcstyle2)
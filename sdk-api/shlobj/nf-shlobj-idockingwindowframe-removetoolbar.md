# IDockingWindowFrame::RemoveToolbar

## Description

Removes the specified [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) from the toolbar frame.

## Parameters

### `punkSrc` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object to be removed. The [IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe) implementation calls the [IDockingWindow::CloseDW](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idockingwindow-closedw) and [IDockingWindow::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) methods.

### `dwRemoveFlags`

Type: **DWORD**

Option flags for removing the docking window object. This parameter can be one or more of the following values:

#### DWFRF_NORMAL (0x0000)

The default delete processing is performed.

#### DWFRF_DELETECONFIGDATA (0x0001)

In addition to deleting the toolbar, any configuration data is removed as well.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)
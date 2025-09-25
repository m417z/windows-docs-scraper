# IDockingWindowSite::GetBorderDW

## Description

Gets the border space allocated for the specified [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object.

## Parameters

### `punkObj` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object for which the border space is being requested.

### `prcBorder` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a structure that, when this method returns successfully, receives the entire available border space for the browser. The docking window object should use this information to determine where to place itself. See the [IDockingWindow::ResizeBorderDW](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idockingwindow-resizeborderdw) method for more information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)
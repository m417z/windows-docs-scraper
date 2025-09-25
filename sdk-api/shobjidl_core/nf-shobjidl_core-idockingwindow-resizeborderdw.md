# IDockingWindow::ResizeBorderDW

## Description

Notifies the docking window object that the frame's border space has changed. In response to this method, the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) implementation must call [SetBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-setborderspacedw), even if no border space is required or a change is not necessary.

## Parameters

### `prcBorder`

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the frame's available border space.

### `punkToolbarSite`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the site's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The docking window object should call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method for this interface, requesting IID_IDockingWindowSite. The docking window object then uses that interface to negotiate its border space. It is the docking window object's responsibility to release this interface when it is no longer needed.

### `fReserved`

Type: **BOOL**

Reserved. This parameter should always be zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *prcBorder* parameter contains the frame's entire available border space. The docking window object should negotiate its border space and then use this information to position itself.

For example, if the docking window object requires 25 pixels at the top of the border space, it should negotiate for this through the following steps:

1. Allocate a [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure and set its **top** member to 25.
2. Call [RequestBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-requestborderspacedw) to request the space.
3. If the request is approved by [RequestBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-requestborderspacedw), call [SetBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-setborderspacedw) to allocate the space.

The docking window object can then position its window at prcBorder->left and prcBorder->top. The width of the docking window object's window is determined by subtracting prcBorder->left from prcBorder->right. Its height is contained in the **top** member of the [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure.

## See also

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)

[IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow)

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)
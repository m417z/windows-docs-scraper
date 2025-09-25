# IDockingWindowSite::SetBorderSpaceDW

## Description

Allocates and reserves border space for an [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object.

## Parameters

### `punkObj` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object for which the border space is being set.

### `pbw` [in]

Type: **LPCBORDERWIDTHS**

A pointer to a [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure that contains the coordinates of the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object's border space. The border space should be approved through a successful call to the [IDockingWindowSite::RequestBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-requestborderspacedw) method before **SetBorderSpaceDW** is called with these coordinates.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)
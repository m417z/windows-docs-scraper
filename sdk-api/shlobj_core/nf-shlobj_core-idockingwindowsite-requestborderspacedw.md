# IDockingWindowSite::RequestBorderSpaceDW

## Description

Approves, modifies, or refuses a request for an [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object's border space. The border space is not allocated until the [SetBorderSpaceDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-setborderspacedw) method is called.

## Parameters

### `punkObj` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) object for which the border space is being requested.

### `pbw` [in]

Type: **LPCBORDERWIDTHS**

A pointer to a [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure. Before calling this method, the structure must be filled with the desired border space. After the method returns successfully, the structure contains the approved border space. The [IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite) object may change these values. If border space is critical, it is the caller's responsibility to determine if the returned border space is sufficient.

## Return value

Type: **HRESULT**

Returns S_OK if the border space request is approved or modified, or an error value otherwise.

## See also

[IDockingWindowFrame](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-idockingwindowframe)

[IDockingWindowSite](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-idockingwindowsite)
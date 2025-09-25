# IUnknown_SetSite function

## Description

Sets the specified object's site by calling its [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) method.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the IUnknown interface of the object whose site is to be changed.

### `punkSite` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the IUnknown interface of the new site.

## Return value

Type: **HRESULT**

Returns S_OK if the site was successfully set, or a COM error code otherwise.

## Remarks

This function calls the specified object's IUnknown::QueryInterface method to obtain a pointer to the object's [IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) interface. If successful, the function calls [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite) to set or change the site.
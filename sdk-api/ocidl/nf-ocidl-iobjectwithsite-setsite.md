# IObjectWithSite::SetSite

## Description

Enables a container to pass an object a pointer to the interface for its site.

## Parameters

### `pUnkSite` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer of the site managing this object. If **NULL**, the object should call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on any existing site at which point the object no longer knows its site.

## Return value

This method returns S_OK on success.

## Remarks

The object should hold onto this pointer, calling [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) in doing so. If the object already has a site, it should call that existing site's [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), save the new site pointer, and call the new site's **IUnknown::AddRef**.

E_NOTIMPL is not allowed. Without implementation of the **SetSite** method, the [IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) interface is unnecessary.

## See also

[IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite)
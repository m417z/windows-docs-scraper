# IUnknown_GetSite function

## Description

Calls the specified object's [IObjectWithSite::GetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-getsite) method.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the COM object whose [IObjectWithSite::GetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-getsite) method is to be called.

### `riid` [in]

Type: **REFIID**

The IID of the interface pointer that should be returned in *ppvSite*.

### `ppv` [out]

Type: **VOID****

The address of the pointer to receive the requested interface pointer. If the function call is successful, *ppvSite* will contain the requested interface pointer. If no site is available or the requested interface is not supported, *ppvSite* is set to **NULL** and the function returns a COM error code.

## Return value

Type: **HRESULT**

Returns **S_OK** if the site was successfully retrieved or a COM error code otherwise.

## Remarks

This function calls the specified object's [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to obtain the [IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) interface. If successful, the function calls the interface's [IObjectWithSite::GetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-getsite) method to obtain the site.
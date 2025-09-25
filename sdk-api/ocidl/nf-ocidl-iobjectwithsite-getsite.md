# IObjectWithSite::GetSite

## Description

Retrieves the latest site passed using [SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite).

## Parameters

### `riid` [in]

The IID of the interface pointer that should be returned in *ppvSite*.

### `ppvSite` [out]

Address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvSite* contains the requested interface pointer to the site last seen in [SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite). The specific interface returned depends on the *riid* argument. In essence, the two arguments act identically to those in [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). If the appropriate interface pointer is available, the object must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on that pointer before returning successfully. If no site is available, or the requested interface is not supported, this method must **ppvSite* to **NULL** and return a failure code.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | There is no site, in which case **ppvSite* contains **NULL** on return. |
| **E_NOINTERFACE** | There is a site, but it does not support the interface requested by *riid*. |

## Remarks

E_NOTIMPL is not allowed. Any object implementing this interface must be able to return the last site seen in [IObjectWithSite::SetSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite).

## See also

[IObjectWithSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite)
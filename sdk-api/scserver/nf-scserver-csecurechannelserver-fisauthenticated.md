# CSecureChannelServer::fIsAuthenticated

## Description

The **fIsAuthenticated** method verifies that a [Secure Authenticated Channel](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels) has been successfully established.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is used to ensure that a secure authenticated channel has been established between components before allowing certain operations. This includes calls by devices and storages prior to accessing and transferring data streams. You should confirm that this method returns **TRUE** before calling other top-level methods on the component.

Applications do not need to call the **fIsAuthenticated** method, but service providers do. They should call this method for all exposed APIs and return WMDM_E_NOTCERTIFIED if it returns **FALSE**.

#### Examples

The following code shows a service provider's implementation of [IMDSPDevice::GetVersion](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-getversion). This method verifies that a secure authenticated channel has been established before returning the version.

```cpp

HRESULT CMyDevice::GetVersion(DWORD * pdwVersion)
{
    HRESULT hr
 = S_OK;

    if(g_pAppSCServer == NULL)
        return E_FAIL;

    if (!(g_pAppSCServer->fIsAuthenticated()))
    {
        return WMDM_E_NOTCERTIFIED;
    }
    *pdwVersion = 1;
    return hr;
}

```

## See also

[CSecureChannelClient::fIsAuthenticated](https://learn.microsoft.com/previous-versions/ms868497(v=msdn.10))

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)
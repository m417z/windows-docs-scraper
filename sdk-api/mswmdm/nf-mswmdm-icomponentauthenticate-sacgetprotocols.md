# IComponentAuthenticate::SACGetProtocols

## Description

The **SACGetProtocols** method is used by a component to discover the authentication protocols supported by another component.

## Parameters

### `ppdwProtocols` [out]

Pointer to an array of supported protocols. For this version of Windows Media Device Manager, it is a single-element **DWORD** array containing the value SAC_PROTOCOL_V1.

### `pdwProtocolCount` [out]

Pointer to a **DWORD** containing the number of protocols returned in *ppdwProtocols*. The number is always 1 for this version.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is implemented by a service provider, and never called by an application.

#### Examples

The following method demonstrates a service provider's implementation of the **SACGetProtocols** method. It does this by calling [CSecureChannelServer::SACGetProtocols](https://learn.microsoft.com/previous-versions/ms868517(v=msdn.10)) on its private [CSecureChannelServer](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class) member.

```cpp

STDMETHODIMP CMyServiceProvider::SACGetProtocols(
    DWORD **ppdwProtocols,
    DWORD  *pdwProtocolCount)
{
    HRESULT hr = E_FAIL;

    // Verify that the global CSecureChannelServer member is valid.
    if(g_pAppSCServer == NULL)
       return hr;

    hr = g_pAppSCServer->SACGetProtocols(
        ppdwProtocols,
        pdwProtocolCount
    );

    return hr;
}

```

## See also

[Authenticating the Service Provider](https://learn.microsoft.com/windows/desktop/WMDM/authenticating-the-service-provider)

[CSecureChannelServer::SACGetProtocols](https://learn.microsoft.com/previous-versions/ms868517(v=msdn.10))

[IComponentAuthenticate Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-icomponentauthenticate)
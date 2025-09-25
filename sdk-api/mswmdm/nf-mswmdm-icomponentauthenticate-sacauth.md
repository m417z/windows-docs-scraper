# IComponentAuthenticate::SACAuth

## Description

The **SACAuth** method establishes a secure authenticated channel between components.

## Parameters

### `dwProtocolID` [in]

**DWORD** containing the protocol identifier. For this version of Windows Media Device Manager, always set this parameter to SAC_PROTOCOL_V1.

### `dwPass` [in]

**DWORD** containing the number of the current communication pass. A pass consists of two messages, one in each direction. SAC_PROTOCOL_V1 is a two-pass protocol, and the passes are numbered 0 and 1.

### `pbDataIn` [in]

Pointer to the input data.

### `dwDataInLen` [in]

**DWORD** containing the length of the data to which *pbDataIn* points.

### `ppbDataOut` [out]

Pointer to a pointer to the output data.

### `pdwDataOutLen` [out]

Pointer to a **DWORD** containing the length of the data to which *ppbDataOut* points.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is called only by service providers. It is called one or more times as dictated by the protocol identifier.

The structure of the data in *pbDataIn* and *ppbDataOut* is determined by the values of *dwProtocolID* and *dwPass*.

#### Examples

The following C++ code demonstrates a service provider's implementation of **SACAuth**. It calls [CSecureChannelServer::SACAuth](https://learn.microsoft.com/previous-versions/ms868516(v=msdn.10)) on a previously created private [CSecureChannelServer](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class) member.

```cpp

HRESULT CMyServiceProvider::SACAuth(
    DWORD   dwProtocolID,
    DWORD   dwPass,
    BYTE   *pbDataIn,
    DWORD   dwDataInLen,
    BYTE  **ppbDataOut,
    DWORD  *pdwDataOutLen)
{
    HRESULT hr = S_OK;

    // Verify that the global CSecureChannelServer member is valid.
    if(g_pAppSCServer == NULL)
        return E_FAIL;

    hr = g_pAppSCServer->SACAuth(
        dwProtocolID,
        dwPass,
        pbDataIn, dwDataInLen,
        ppbDataOut, pdwDataOutLen
    );
    return hr;
}

```

## See also

[Authenticating the Service Provider](https://learn.microsoft.com/windows/desktop/WMDM/authenticating-the-service-provider)

[CSecureChannelServer::SACAuth](https://learn.microsoft.com/previous-versions/ms868516(v=msdn.10))

[IComponentAuthenticate Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-icomponentauthenticate)
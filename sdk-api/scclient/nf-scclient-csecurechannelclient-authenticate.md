# CSecureChannelClient::Authenticate

## Description

The **Authenticate** method authenticates communication between components to establish trust. In applications, it is used to establish trust between the application and Windows Media Device Manager. Messages are exchanged and trust established if both the client and server certificates are validated.

## Parameters

### `dwProtocolID` [in]

**DWORD** specifying the protocol identifier. Currently, the only value accepted is SAC_PROTOCOL_V1, defined in the SDK in ...\inc\sac.h.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| S_OK | The method succeeded. |
| E_INVALIDARG | The dwProtocol parameter is invalid. |
| E_FAIL | An unspecified error occurred. |

## Remarks

This method specifies which protocol method is to be used. That method is then called. In this version of Windows Media Device Manager, SAC_PROTOCOL_V1 must be used.

[CSecureChannelClient::SetCertificate](https://learn.microsoft.com/previous-versions/ms868504(v=msdn.10)) and [CSecureChannelClient::SetInterface](https://learn.microsoft.com/previous-versions/bb231595(v=vs.85)) must be called before **Authenticate**.

#### Examples

The following C++ code authenticates the Windows Media Device Manager session and acquires an [IWMDeviceManager](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager) interface.

```cpp

// Authenticates the WMDM, and acquires an interface to the top-level object.
HRESULT MyClass::Authenticate()
{
    HRESULT hr;
    CComPtr<IComponentAuthenticate> pAuth;

    // Create the WMDM object and acquire
    // its authentication interface.
    hr = CoCreateInstance(
        __uuidof(MediaDevMgr),
        NULL,
        CLSCTX_INPROC_SERVER,
        __uuidof(IComponentAuthenticate),
        (void**)&pAuth);

    if (hr != S_OK)
        return hr;

    // Create the secure channel client class needed to authenticate the application.
    // We'll use a global member variable to hold the secure channel client
    // in case we need to handle encryption, decryption, or MAC verification
    // during this session.
    m_pSAC = new CSecureChannelClient;
    if (m_pSAC == NULL)
        return E_FAIL;

    // Send the application's transfer certificate and the associated
    // private key to the secure channel client.
    hr = m_pSAC->SetCertificate(
        SAC_CERT_V1,
        (BYTE *)abCert, sizeof(abCert),
        (BYTE *)abPVK,  sizeof(abPVK));
    if (hr != S_OK)
        return hr;

    // Send the authentication interface we created to the secure channel
    // client and try authenticating the application with the V1 protocol.
    m_pSAC->SetInterface(pAuth);
    hr = m_pSAC->Authenticate(SAC_PROTOCOL_V1);
    if (hr != S_OK)
        return hr;

    // Authenticated succeeded, so we can use the WMDM.
    // Acquire an interface to the top-level WMDM interface
    // and store it in a global variable.
    hr = pAuth->QueryInterface(__uuidof(IWMDeviceManager), (void**)&m_IWMDeviceMgr);

    return hr;
}

```

## See also

[Authenticating the Application](https://learn.microsoft.com/windows/desktop/WMDM/authenticating-the-application)

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)
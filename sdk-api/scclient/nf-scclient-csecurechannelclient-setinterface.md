# CSecureChannelClient::SetInterface

## Description

The **SetInterface** method is used by applications to set the **IComponentAuthenticate** interface to use for Secure Authenticated Channel (SAC) operations.

## Parameters

### `pComponentAuth` [in]

Pointer to an [IComponentAuthenticate](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-icomponentauthenticate) interface. The caller is responsible for calling **Release** on the retrieved interface.

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
| E_INVALIDARG | The pComponentAuth parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

The SAC interface is the **IComponentAuthenticate** interface. Applications use the **IComponentAuthenticate** interface provided in Windows Media Device Manager. Service providers and secure content providers must implement their own **IComponentAuthenticate** interface.

**CoCreateInstance** must be called first to acquire the **IComponentAuthenticate** interface.

#### Examples

The following C++ code authenticates the Windows Media Device Manager session and acquires the root object.

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
    // Acquire an interface to the top-level WMDM interface.
    hr = pAuth->QueryInterface(__uuidof(IWMDeviceManager), (void**)&m_IWMDeviceMgr);

    return hr;
}

```

## See also

[Authenticating the Application](https://learn.microsoft.com/windows/desktop/WMDM/authenticating-the-application)

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)

[IComponentAuthenticate Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-icomponentauthenticate)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)
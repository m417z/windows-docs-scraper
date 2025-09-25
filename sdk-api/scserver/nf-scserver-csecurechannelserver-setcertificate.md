# CSecureChannelServer::SetCertificate

## Description

The **SetCertificate** method specifies the certificate and private key of the secure authenticated channel (SAC) server. Information about where to get this certificate is given in [Tools for Development](https://learn.microsoft.com/windows/desktop/WMDM/tools-for-development).

## Parameters

### `dwFlags` [in]

Specifies the type of certificate being passed to this method. Must be set to SAC_CERT_V1.

### `pbAppCert` [in]

Pointer to the first byte of the certificate of the SAC client.

### `dwCertLen` [in]

**DWORD** specifying the length of the certificate to which *pbAppCert* points.

### `pbAppPVK` [in]

Pointer to the first byte of the private key of the SAC client.

### `dwPVKLen` [in]

**DWORD** specifying the length of the private key to which *pbAppPVK* points.

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
| E_INVALIDARG | A parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

This method sends the component's authentication certificate to **CSecureChannelClient**. **SetCertificate** should be called immediately after creating the **CSecureChannelServer** object. If *pbAppCert* and/or *pbAppPVK* are **NULL** (or both zero) a default certificate and private key pair is used which will allow for basic functionality.

#### Examples

The following code demonstrates creating a CSecureChannelServer object and setting its certificate. In this code, the variables *pbAppCert* and *pbAppPVK* are a matching certificate/key pair.

```cpp

extern CSecureChannelServer *g_pSCWMDM;
g_pSCWMDM = new CSecureChannelServer();

// Select the certificate and the associated private key into the SAC.
if (g_pSCWMDM)
{
    g_pSCWMDM->SetCertificate( SAC_CERT_V1,
                               (BYTE*)g_abAppCert,
                               sizeof(g_abAppCert),
                               (BYTE*)g_abPriv,
                               sizeof(g_abPriv) );
}

```

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)
# ISCPSecureQuery2::MakeDecision2

## Description

The **MakeDecision2** method determines whether the secure content provider is responsible for the content by examining data that Windows Media Device Manager passes to this method. This method provides two output parameters for error handling, a default location for updating revoked components, and a bit flag indicating which components have been revoked.

## Parameters

### `fuFlags` [in]

Flags describing the data offered to the secure content provider for making decisions. This parameter must be included in the input message authentication code. One or more of the following flags can be combined using a bitwise **OR**.

| Flag | Description |
| --- | --- |
| WMDM_SCP_DECIDE_DATA | The *pData* parameter points to the data to be examined. |
| WMDM_MODE_TRANSFER_PROTECTED | The output object data from the [ISCPSecureExchange](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange) interface must be protected. If Windows Media Device Manager sets neither or both mode flags, Windows Media Digital Rights Manager decides whether the output object data from the **ISCPSecureExchange** interface must be protected or unprotected. |
| WMDM_MODE_TRANSFER_UNPROTECTED | The output object data from the **ISCPSecureExchange** interface must be unprotected. If Windows Media Device Manager sets neither or both mode flags, Windows Media Digital Rights Manager decides whether the output object data from the **ISCPSecureExchange** interface must be protected or unprotected. |

### `pData` [in]

Pointer to a data object containing the data to be examined. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSize` [in]

**DWORD** containing the size of the file data.

### `dwAppSec` [in]

**DWORD** that contains the length, in bytes, of the **dwAppSec** member of the [WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights) structure of the service provider and secure content provider to be examined. This parameter must be included in the input message authentication code.

### `pbSPSessionKey` [in]

Pointer to an array of bytes containing the session key for securing communication with the service provider to which *pStgGlobals* points. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSessionKeyLen` [in]

**DWORD** containing the session key length.

### `pStorageGlobals` [in]

Pointer to the [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface on the root storage of the media or device to or from which the file is being transferred. This parameter must be included in the input message authentication code.

### `pAppCertApp` [in]

Pointer to an application certificate of the application object.

### `dwAppCertAppLen` [in]

**DWORD** containing the length, in bytes, of the application certificate.

### `pAppCertSP` [in]

Pointer to the application certificate of the service provider object.

### `dwAppCertSPLen` [in]

**DWORD** containing the length, in bytes, of the application certificate.

### `pszRevocationURL` [in, out]

Pointer to a buffer to hold the revocation URL.

### `pdwRevocationURLLen` [in, out]

Pointer to a **DWORD** containing the size of the *rpszRevocationURL* buffer in bytes.

### `pdwRevocationBitFlag` [out]

Pointer to a **DWORD** containing the revocation bit flag. The flag value will be either zero, or one or more of the following flag names combined by using a bitwise **OR**.

| Value | Description |
| --- | --- |
| WMDM_WMDM_REVOKED | Windows Media Device Manager itself has been revoked. |
| WMDM_APP_REVOKED | The application has been revoked and needs to be updated before any DRM-protected content can be transferred. |
| WMDM_SP_REVOKED | The service provider has been revoked and needs to be updated before any DRM-protected content can be transferred to it. |
| WMDM_SCP_REVOKED | The secure content provider has been revoked and needs to be updated before any DRM-protected content can be transferred. |

### `pqwFileSize` [in, out]

Pointer to a **QWORD** containing the file size. The secure content provider is responsible for updating this value or setting it to zero if the size of the destination file cannot be determined at this point.

### `pUnknown` [in]

Pointer to an unknown interface from the application.

### `ppExchange` [out]

Pointer to an exchange object that receives the exchange interface.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_REVOKED** | The application certificate that the secure content provider uses to talk to the DRM client has been revoked. |

## See also

[ISCPSecureQuery Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery)

[ISCPSecureQuery2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery2)

[ISCPSecureQuery::MakeDecision](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-makedecision)
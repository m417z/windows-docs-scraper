# ISCPSecureQuery3::MakeDecisionOnClearChannel

## Description

The **MakeDecisionOnClearChannel** method determines whether access to the content is allowed on a clear channel. If access is allowed, this method returns the interface used to access the content.

## Parameters

### `fuFlags` [in]

Flags describing the data offered to the content provider for making decisions. The following flags can be present.

| Flag | Description |
| --- | --- |
| WMDM_SCP_DECIDE_DATA | The *pData* parameter points to data to be examined. |
| WMDM_MODE_TRANSFER_PROTECTED | The output object data from the [ISCPSecureExchange](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange) interface must be protected. If Windows Media Device Manager sets neither or both mode flags, digital rights management (DRM) decides whether the output object data from the **ISCPSecureExchange** interface must be protected or unprotected. |
| WMDM_MODE_TRANSFER_UNPROTECTED | The output object data from the **ISCPSecureExchange** interface must be unprotected. If Windows Media Device Manager sets neither or both mode flags, digital rights management (DRM) decides whether the output object data from the **ISCPSecureExchange** interface must be protected or unprotected. |

### `pData` [in]

Pointer to a data object containing the data to be examined.

### `dwSize` [in]

**DWORD** that contains the length, in bytes, of the data to be examined.

### `dwAppSec` [in]

**DWORD** that indicates the current level of security of Windows Media Device Manager. This is the smaller of the current security levels of the application and the target service provider.

### `pbSPSessionKey` [in]

Pointer to an array of bytes containing the session key for securing communication with the service provider to which *pStgGlobals* points.

### `dwSessionKeyLen` [in]

Length of the byte array to which *pbSPSessionKey* points.

### `pStorageGlobals` [in]

Pointer to the [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface on the root storage of the media or device to or from which the file is being transferred.

### `pProgressCallback` [in]

Pointer to a progress callback object.

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

Pointer to a **DWORD** containing the revocation bit flag. The flag value will be either zero or one or more of the following flag names combined by using a bitwise **OR**.

| Value | Description |
| --- | --- |
| WMDM_WMDM_REVOKED | Windows Media Device Manager itself has been revoked. |
| WMDM_APP_REVOKED | The application has been revoked and needs to be updated before any DRM-protected content can be transferred. |
| WMDM_SP_REVOKED | The service provider has been revoked and needs to be updated before any DRM-protected content can be transferred to it. |
| WMDM_SCP_REVOKED | The content provider has been revoked and needs to be updated before any DRM-protected content can be transferred. |

### `pqwFileSize` [in, out]

Pointer to a **QWORD** containing the file size. The content provider is responsible for updating this value or setting it to zero if the size of the destination file cannot be determined at this point.

### `pUnknown` [in]

Pointer to an unknown interface from the application.

### `ppExchange` [out]

Pointer to an exchange object that receives the exchange interface.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | This method was called out of sequence. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **WMDM_E_MOREDATA** | Windows Media Device Manager must call this method again with another packet of data. The size of the packet is determined by the *pdwMinDecisionData* parameter in the [ISCPSecureQuery::GetDataDemands](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getdatademands) method. |
| **S_FALSE** | The caller does not have the rights required to perform the requested transfer. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is identical to [ISCPSecureQuery2::MakeDecision2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery2-makedecision2) except that the parameters passed to this method are not encrypted. Consequently this method is more efficient.

## See also

[ISCPSecureQuery2::MakeDecision2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery2-makedecision2)

[ISCPSecureQuery3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery3)
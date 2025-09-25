# ISCPSecureQuery::MakeDecision

## Description

The **MakeDecision** method determines whether access to the content is allowed. If access is allowed, this method returns the interface that will be used to access the content.

## Parameters

### `fuFlags` [in]

Flags describing the data offered to the secure content provider for making decisions. This parameter must be included in the input message authentication code. The following flags can be present.

| Flag | Description |
| --- | --- |
| WMDM_SCP_DECIDE_DATA | The *pData* parameter points to data to be examined. |
| WMDM_MODE_TRANSFER_PROTECTED | The output object data from the [ISCPSecureExchange](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange) interface must be protected. If Windows Media Device Manager sets neither or both mode flags, DRM decides whether the output object data from the **ISCPSecureExchange** interface must be protected or unprotected. |
| WMDM_MODE_TRANSFER_UNPROTECTED | The output object data from the **ISCPSecureExchange** interface must be unprotected. If Windows Media Device Manager sets neither or both mode flags, DRM decides whether the output object data from the **ISCPSecureExchange** interface must be protected or unprotected. |

### `pData` [in]

Pointer to a data object containing the data to be examined. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSize` [in]

**DWORD** that contains the length, in bytes, of the data to be examined. This parameter must be included in the input message authentication code.

### `dwAppSec` [in]

**DWORD** that indicates the current level of security of Windows Media Device Manager. This is the smaller of the current security levels of the application and the target service provider. This parameter must be included in the input message authentication code.

### `pbSPSessionKey` [in]

Pointer to an array of bytes containing the session key for securing communication with the service provider to which *pStgGlobals* points. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSessionKeyLen` [in]

Length of the byte array to which *pbSPSessionKey* points. This parameter must be included in the input message authentication code.

### `pStorageGlobals` [in]

Pointer to the [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface on the root storage of the media or device to or from which the file is being transferred. This parameter must be included in the input message authentication code.

### `ppExchange` [out]

Pointer to an exchange object that receives the exchange interface.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | This method was called out of sequence. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **WMDM_E_MOREDATA** | Windows Media Device Manager must call this method again with another packet of data. The size of the packet is determined by the *pdwMinDecisionData* parameter in the [ISCPSecureQuery::GetDataDemands](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getdatademands) method. |
| **S_FALSE** | The caller does not have the rights required to perform the requested transfer. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is called after the [ISCPSecureQuery::ExamineData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-examinedata) method, and makes the final decision whether access to the content is allowed.

## See also

[ISCPSecureExchange Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureexchange)

[ISCPSecureQuery Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery)

[ISCPSecureQuery2::MakeDecision2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery2-makedecision2)

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)
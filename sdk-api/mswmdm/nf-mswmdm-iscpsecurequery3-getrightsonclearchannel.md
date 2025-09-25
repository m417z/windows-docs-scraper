# ISCPSecureQuery3::GetRightsOnClearChannel

## Description

The **GetRightsOnClearChannel** method retrieves rights information for the current piece of content on a clear channel.

## Parameters

### `pData` [in]

Pointer to data object.

### `dwSize` [in]

Number of bytes of data in the *pData* buffer.

### `pbSPSessionKey` [in]

Pointer to an array of bytes containing the session key for securing communication with the service provider to which *pStgGlobals* points.

### `dwSessionKeyLen` [in]

Length of the byte array to which *pbSPSessionKey* points.

### `pStgGlobals` [in]

Pointer to an [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface on the root storage of the media or device to or from which the file is being transferred.

### `pProgressCallback` [in]

Pointer to an [IWMDMProgress3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3) interface.

### `ppRights` [out]

Pointer to an array of [WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights) structures containing the rights information for this object. The array is allocated by this method and must be freed using **CoTaskMemFree**.

### `pnRightsCount` [out]

Number of **WMDMRIGHTS** structures in the *ppRights* array.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | This method was called out of sequence. [ISCPSecureQuery::GetDataDemands](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getdatademands) and then [ISCPSecureQuery::ExamineData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-examinedata) must be called, in that order. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is identical to **ISCPSecureQuery::GetRights** except that the parameters passed to this method are not encrypted. Consequently this method is more efficient.

## See also

[ISCPSecureQuery3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery3)

[ISCPSecureQuery::GetRights](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getrights)

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)

[WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights)
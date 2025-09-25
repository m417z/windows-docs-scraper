# ISCPSecureQuery::GetRights

## Description

The **GetRights** method retrieves rights information for the current piece of content. Rights are file-specific.

## Parameters

### `pData` [in]

Pointer to data requested by [GetDataDemands](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getdatademands). This parameter must be included in the input message authentication code and must be encrypted.

### `dwSize` [in]

Number of bytes of data in the *pData* buffer. This parameter must be included in the input message authentication code.

### `pbSPSessionKey` [in]

Pointer to an array of bytes containing the session key for securing communication with the service provider to which *pStgGlobals* points. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSessionKeyLen` [in]

Length of the byte array to which *pbSPSessionKey* points. This parameter must be included in the input message authentication code.

### `pStgGlobals` [in]

Pointer to an [IWMDMStorageGlobals](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals) interface on the root storage of the media or device to or from which the file is being transferred.

### `ppRights` [out]

Pointer to an array of [WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights) structures containing the rights information for this object. The array is allocated by this method and must be freed using **CoTaskMemFree**. This parameter is included in the output message authentication code.

### `pnRightsCount` [out]

Number of **WMDMRIGHTS** structures in the *ppRights* array. This parameter is included in the output message authentication code.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | This method was called out of sequence. **GetDataDemands** and then [ExamineData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-examinedata) must be called first, in that order. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **WMDM_E_NORIGHTS** | The caller does not have the rights required to perform the requested operation. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method must not be called until **GetDataDemands** and then **ExamineData** have been called, in that order.

## See also

[ISCPSecureQuery Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery)

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)

[WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights)
# ISCPSecureQuery::ExamineData

## Description

The **ExamineData** method determines rights and responsibility for the content by examining data that Windows Media Device Manager passes to this method.

## Parameters

### `fuFlags` [in]

Flags describing the data offered to the secure content provider to make decisions. The following flags can be present.

| Flag | Description |
| --- | --- |
| WMDM_SCP_EXAMINE_DATA | The *pData* parameter points to data to be examined. |

### `pwszExtension` [in]

Pointer to the file name extension to be examined if the secure content provider asks for an extension in the [GetDataDemands](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getdatademands) call.

### `pData` [in]

Pointer to the data at the beginning of the file to be examined. This parameter must be included in the input message authentication code and must be encrypted.

### `dwSize` [in]

**DWORD** that contains the length, in bytes, of the data to be examined. This parameter must be included in the input message authentication code.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. The secure content provider is responsible for this content. |
| **WMDM_E_CALL_OUT_OF_SEQUENCE** | This method was called out of sequence. **GetDataDemands** must be called first. |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **WMDM_E_MOREDATA** | Windows Media Device Manager must call this method again with another packet of data. The size of the packet is determined by the *pdwMinExamineData* parameter in the **GetDataDemands** method. |
| **S_FALSE** | The secure content provider is not responsible for this content. Terminate interaction with the secure content provider. |
| **E_INVALIDARG** | A parameter is invalid or is a **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method is called after the **GetDataDemands** method. The secure content provider uses the information passed in this method to determine whether it is responsible for the content. The *fuFlags* parameter is consulted to determine which data has been presented for examination. The *pData* parameter points to the beginning of the rights and responsibility data. The *dwSize* parameter contains the length, in bytes, of the rights and responsibility data.

If the WMDM_SCP_EXAMINE_DATA flag is set, then the *pDataBuffer* parameter contains *dwDataLength* of bytes for the secure content provider to examine.

If this method does not return S_OK or WMDM_E_MOREDATA, then Windows Media Device Manager does not make any further calls to this secure content provider.

## See also

[ISCPSecureQuery Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery)
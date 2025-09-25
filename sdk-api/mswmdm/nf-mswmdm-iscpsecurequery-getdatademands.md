# ISCPSecureQuery::GetDataDemands

## Description

The **GetDataDemands** method reports which data the secure content provider needs to determine the rights and responsibility for a specified piece of content.

## Parameters

### `pfuFlags` [out]

Flags describing the data required by the secure content provider to make decisions. This parameter is included in the output message authentication code. At least one of the following flags must be used.

| Flag | Description |
| --- | --- |
| WMDM_SCP_RIGHTS_DATA | The secure content provider needs data to determine rights for the content. |
| WMDM_SCP_EXAMINE_DATA | The secure content provider needs data to determine whether it is responsible for the content. |
| WMDM_SCP_DECIDE_DATA | The secure content provider needs data to determine whether to allow the content to be downloaded. |
| WMDM_SCP_EXAMINE_EXTENSION | The secure content provider needs to examine the file name extension to determine whether to allow the content to be downloaded. |
| WMDM_SCP_PROTECTED_OUTPUT | The secure content provider needs protected output. |
| WMDM_SCP_UNPROTECTED_OUTPUT | The secure content provider needs unprotected output. |

### `pdwMinRightsData` [out]

Pointer to a **DWORD** specifying the minimum amount of data needed to determine rights for this content. This parameter is included in the output message authentication code.

### `pdwMinExamineData` [out]

Pointer to a **DWORD** containing the minimum number of bytes of data that the secure content provider needs to determine whether it is responsible for the content. This parameter is included in the output message authentication code.

### `pdwMinDecideData` [out]

Pointer to a **DWORD** containing the minimum number of bytes of data that the secure content provider needs to determine whether to allow the content to be downloaded. This parameter is included in the output message authentication code.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **WMDM_E_MAC_CHECK_FAILED** | The message authentication code is not valid. |
| **E_INVALIDARG** | A parameter is an invalid or **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method must be called before any of the other methods of **ISCPSecureQuery** are called.

This method is called after any certificate exchanges have been successfully finished. The secure content provider fills in the parameters with the flags and data that describe its requirements for making decisions about the content.

If the secure content provider sets the WMDM_SCP_RIGHTS_DATA flag, then Windows Media Device Manager sends the amount of data specified in *pdwMinRightsData* by calling [ISCPSecureQuery::GetRights](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-getrights).

If the secure content provider sets the WMDM_SCP_EXAMINE_DATA flag, then Windows Media Device Manager sends the amount of data specified in *pdwMinExamineData* by calling [ISCPSecureQuery::ExamineData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-examinedata).

If the secure content provider sets the WMDM_SCP_DECIDE_DATA flag, then Windows Media Device Manager sends the amount of data specified in *pdwMinDecideData* by calling [ISCPSecureQuery::MakeDecision](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-makedecision).

If no examine flags are set, Windows Media Device Manager does not make any more calls. If no decide flags are set, Windows Media Device Manager still calls [ISCPSecureQuery::ExamineData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iscpsecurequery-examinedata).

If this method does not return S_OK, then Windows Media Device Manager does not make any further calls to this secure content provider.

## See also

[ISCPSecureQuery Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery)
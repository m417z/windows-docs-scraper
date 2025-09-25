# CryptSIPCreateIndirectData function

## Description

The [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure, the digest algorithm, and an encoding attribute. The hash can be used as an indirect reference to the data.

## Parameters

### `pSubjectInfo` [in]

A pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that contains the subject to which the indirect data reference will point.

### `pcbIndirectData` [in, out]

A pointer to a [SIP_INDIRECT_DATA](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_indirect_data) structure.

### `pIndirectData` [out]

A pointer to a [SIP_INDIRECT_DATA](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_indirect_data) structure to receive the catalog item.

## Return value

The return value is **TRUE** if the function succeeds; otherwise, **FALSE**.

If this function returns **FALSE**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_FORMAT** | The file or data format is not correct for the specified [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) type. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |
| **NTE_BAD_ALGID** | The specified algorithm is not supported by the SIP. |
| **TRUST_E_SUBJECT_FORM_UNKNOWN** | The subject type is not recognized. |

## Remarks

If *pcbIndirectData* points to a **DWORD** and *pIndirectData* points to **NULL**, the size of the data will be returned
in *pcbIndirectData*.
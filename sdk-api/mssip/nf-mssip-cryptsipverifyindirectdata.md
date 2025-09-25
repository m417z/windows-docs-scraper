# CryptSIPVerifyIndirectData function

## Description

The **CryptSIPVerifyIndirectData** function validates the indirect hashed data against the supplied subject.

## Parameters

### `pSubjectInfo` [in]

A pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that contains information about the message subject.

### `pIndirectData` [in]

A pointer to a [SIP_INDIRECT_DATA](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_indirect_data) structure that contains information about the hashed subject information.

## Return value

The return value is **TRUE** if the function succeeds; otherwise, **FALSE**.

If this function returns **FALSE**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |
| **TRUST_E_SUBJECT_FORM_UNKNOWN** | The subject type is an unknown type. |

## Remarks

Subjects include, but are not limited to, portable executable images (.exe), cabinet (.cab) images, flat files, and catalog files. Each subject type uses a different subset of its data for hash calculation and requires a different procedure for storage and retrieval. Therefore each subject type has a unique subject interface package specification.
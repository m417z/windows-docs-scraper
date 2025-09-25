# CryptSIPPutSignedDataMsg function

## Description

The **CryptSIPPutSignedDataMsg** function stores an [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) signature in the target file.

## Parameters

### `pSubjectInfo` [in]

Pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that contains information about the message subject.

### `dwEncodingType` [in]

The encoding type of the message. This can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PKCS_7_ASN_ENCODING**<br><br>65536 (0x10000) | Specifies [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) message encoding. |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `pdwIndex` [out]

Pointer to the message index.

### `cbSignedDataMsg` [in]

Length, in bytes, of the buffer pointed to by the *pbSignedDataMsg* parameter.

### `pbSignedDataMsg` [in]

Pointer to the buffer that contains the message.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_FORMAT** | The specified data or file format of the [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) is not valid. |
| **ERROR_INVALID_PARAMETER** | This code can be returned for the following reasons:<br><br>* The *pSubjectInfo* is **NULL**.<br>* The *pdwIndex* is **NULL**.<br>* The *pbSignedDataMsg* is **NULL**.<br>* The value of the *cbSignedDataMsg* parameter is less than one. [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure. [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure. |
| **TRUST_E_SUBJECT_FORM_UNKNOWN** | The specified subject type is not valid. |

## Remarks

Each subject type uses a different subset of its data for hash calculation and requires a different procedure for storage and retrieval. Therefore, each subject type has a unique SIP specification.

## See also

[CryptSIPGetSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipgetsigneddatamsg)

[CryptSIPRemoveSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremovesigneddatamsg)
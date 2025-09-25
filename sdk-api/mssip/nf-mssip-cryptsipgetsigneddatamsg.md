# CryptSIPGetSignedDataMsg function

## Description

The **CryptSIPGetSignedDataMsg** function retrieves an [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) signature from the file.

## Parameters

### `pSubjectInfo` [in]

A pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that contains information about the message subject.

### `pdwEncodingType` [out]

The encoding type of the Authenticode signature.

This parameter can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PKCS_7_ASN_ENCODING**<br><br>65536 (0x10000) | Specifies [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) message encoding. |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `dwIndex` [in]

This parameter is reserved and should be set to zero.

### `pcbSignedDataMsg` [in, out]

The length, in bytes, of the buffer pointed to by the *pbSignedDataMsg* parameter.

### `pbSignedDataMsg` [out]

A pointer to a buffer to receive the returned Authenticode signature.

To determine the size of the buffer needed, set the *pbSignedDataMsg* parameter to **NULL** and call the **CryptSIPGetSignedDataMsg** function. This function will place the required size of the buffer, in bytes, in the value pointed to by *pcbSignedDataMsg*. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NO_MATCH** | The signature specified by the index could not be found. |
| **ERROR_BAD_FORMAT** | The specified data or file format of the [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) is not valid. |
| **ERROR_INVALID_PARAMETER** | The [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure is a null pointer. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the message buffer was insufficient to hold the retrieved data, the *pcbSignedDataMsg* parameter has been set to indicate the required buffer size. |
| **TRUST_E_SUBJECT_FORM_UNKNOWN** | The specified subject type is not valid. |

## Remarks

Subjects include, but are not limited to, portable executable images (.exe), cabinet (.cab) images, flat files, and catalog files. Each subject type uses a different subset of its data for hash calculation and requires a different procedure for storage and retrieval. Therefore, each subject type has a unique SIP specification.

## See also

[CryptSIPPutSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipputsigneddatamsg)

[CryptSIPRemoveSignedDataMsg](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipremovesigneddatamsg)
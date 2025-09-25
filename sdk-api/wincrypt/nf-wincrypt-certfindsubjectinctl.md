# CertFindSubjectInCTL function

## Description

The **CertFindSubjectInCTL** function attempts to find the specified subject in a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL). A subject can be identified either by the certificate's whole context or by any unique identifier of the certificate's subject such as the SHA1 [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the certificate's issuer and serial number.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type used. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. For either current encoding type, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `dwSubjectType` [in]

Specifies the type of subject to be searched for in the CTL. May be **NULL** for a default search.

| Value | Meaning |
| --- | --- |
| **CTL_CERT_SUBJECT_TYPE** | *pvSubject* data type: Pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.<br><br>The CTL's **SubjectAlgorithm** is examined to determine the representation of the subject's identity. Initially, only SHA1 and MD5 hashes are supported as values for **SubjectAlgorithm**. The appropriate hash property is obtained from the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. |
| **CTL_ANY_SUBJECT_TYPE** | *pvSubject* data type: Pointer to a [CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info) structure.<br><br>The **SubjectAlgorithm** member of this structure must match the algorithm type of the CTL, and the **SubjectIdentifier** member must match one of the CTL entries. |

The certificate's [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) or the **SubjectIdentifier** member of the [CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info) structure is used as the key in searching the subject entries. A binary memory comparison is done between the key and the entry's SubjectIdentifier.

If *dwSubjectType* is set to either preceding value, *dwEncodingType* is not used.

### `pvSubject` [in]

Pointer used in conjunction with the *dwSubjectType* parameter.

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure being searched.

### `dwFlags` [in]

Reserved for future use and must be zero.

## Return value

If the function succeeds, the return value is the entry, if it is found.

If the function fails, the return value is **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | The subject was not found in the CTL. |
| **E_INVALIDARG** | The *dwSubjectType* parameter was not either CTL_CERT_SUBJECT_TYPE or CTL_ANY_SUBJECT_TYPE. |
| **NTE_BAD_ALGID** | The CTL's **SubjectAlgorithm** member did not map to either SHA1 or MD5. |

## Remarks

The certificate's hash or the **SubjectIdentifier** member of the
[CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info) structure is used as the key in searching the subject entries. A binary memory comparison is done between the key and the entry's **SubjectIdentifier**.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info)

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)

[Certificate and Certificate Store Maintenance Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
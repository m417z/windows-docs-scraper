# CertVerifyRevocation function

## Description

The **CertVerifyRevocation** function checks the revocation status of the certificates contained in the *rgpvContext* array. If a certificate in the list is found to be revoked, no further checking is done. This array can be a chain of certificates propagating upward from an end entity to the [root authority](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), but this nature of the list of certificates is not required or assumed.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type used. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. For either current encoding type, use X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `dwRevType` [in]

Indicates the type of the context structure passed in *rgpvContext*. Currently only CERT_CONTEXT_REVOCATION_TYPE, the revocation of certificates, is defined.

### `cContext` [in]

Count of elements in the *rgpvContext* array.

### `rgpvContext` [in]

When the *dwRevType* is CERT_CONTEXT_REVOCATION_TYPE, *rgpvContext* is an array of pointers to
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structures. These contexts must contain sufficient information to allow the installable or registered revocation DLLs to find the revocation server. This information would normally be conveyed in an extension such as the CRLDistributionsPoints extension defined by the Internet Engineering Task Force (IETF) in PKIX Part 1.

For efficiency, the more contexts that are passed in at one time, the better.

### `dwFlags` [in]

Indicates any special processing needs. This parameter can be one of the following flags.

| Value | Meaning |
| --- | --- |
| **CERT_VERIFY_REV_CHAIN_FLAG** | Verification of the chain of certificates is done assuming each certificate except the first certificate is the issuer of the certificate that precedes it. If *dwRevType* is not CERT_CONTEXT_REVOCATION_TYPE, no assumptions are made about the order of the contexts. |
| **CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION** | Prevents the revocation handler from accessing any network-based resources for revocation checking. |
| **CERT_VERIFY_REV_ACCUMULATIVE_TIMEOUT_FLAG** | When set, **dwUrlRetrievalTimeout** is the cumulative time-out across all URL wire retrievals. |
| **CERT_VERIFY_REV_SERVER_OCSP_FLAG** | When set, this function only uses [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) for revocation checking. If the certificate does not have any OCSP AIA URLs, the **dwError** member of the *pRevStatus* parameter is set to CRYPT_E_NOT_IN_REVOCATION_DATABASE. |

### `pRevPara` [in, optional]

Optionally set to assist in finding the issuer. For details, see the
[CERT_REVOCATION_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_para) structure.

### `pRevStatus` [in, out]

Only the **cbSize** member of the
[CERT_REVOCATION_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_status) pointed to by *pRevStatus* needs to be set before **CertVerifyRevocation** is called.

If the function returns **FALSE**, this structure's members will contain error status information. For more information, see
[CERT_REVOCATION_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_status). For a description of how *pRevStatus* is updated when a revocation verification problem is encountered, see Remarks.

## Return value

If the function successfully checks all of the contexts and none were revoked, the function returns **TRUE**. If the function fails, it returns **FALSE** and updates the [CERT_REVOCATION_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_status) structure pointed to by *pRevStatus* as described in
**CERT_REVOCATION_STATUS**.

When the revocation handler for any of the contexts returns **FALSE** due to an error, the **dwError** member in the structure pointed to by *pRevStatus* will be set by the handler to specify which error was encountered.
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns an error code equal to the error specified in the **dwError** member of the [CERT_REVOCATION_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_status) structure. **GetLastError** can be one of the following values.

| Value | Description |
| --- | --- |
| **CRYPT_E_NO_REVOCATION_CHECK** | An installed or registered revocation function was not able to do a revocation check on the context. |
| **CRYPT_E_NO_REVOCATION_DLL** | No installed or registered DLL was found that was able to verify revocation. |
| **CRYPT_E_NOT_IN_REVOCATION_DATABASE** | The context to be checked was not found in the revocation server's database. |
| **CRYPT_E_REVOCATION_OFFLINE** | It was not possible to connect to the revocation server. |
| **CRYPT_E_REVOKED** | The context was revoked. **dwReason** in *pRevStatus* contains the reason for revocation. |
| **ERROR_SUCCESS** | The context was good. |
| **E_INVALIDARG** | **cbSize** in *pRevStatus* is less than sizeof([CERT_REVOCATION_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_status)). Note that **dwError** in *pRevStatus* is not updated for this error. |

## Remarks

The following example shows how *pRevStatus* is updated when a revocation verification problem is encountered:

Consider the case where *cContext* is four:

If **CertVerifyRevocation** can verify that *rgpvContext*[0] and *rgpvContext*[1] are not revoked, but cannot check *rgpvContext*[2], the *pRevStatus* member **dwIndex** is set to two, indicating that the context at index two has the problem, the **dwError** member of *pRevStatus* is set to CRYPT_E_NO_REVOCATION_CHECK, and **FALSE** is returned.

If *rgpvContext*[2] is found to be revoked, the **dwIndex** member of *pRevStatus* is set to two, and the **dwError** member of *pRevStatus* is set to CRYPT_E_REVOKED, **dwReason** is updated, and **FALSE** is returned.

 In either case, both *rgpvContext*[0] and *rgpvContext*[1] are verified not to be revoked, *rgpvContext*[2] is the last array index checked, and *rgpvContext*[3] has not been checked at all.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CERT_REVOCATION_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_para)

[CERT_REVOCATION_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_status)

[CertVerifyCRLTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycrltimevalidity)

[CertVerifyTimeValidity](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifytimevalidity)

[CertVerifyValidityNesting](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyvaliditynesting)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
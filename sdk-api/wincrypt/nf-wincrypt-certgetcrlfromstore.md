# CertGetCRLFromStore function

## Description

The **CertGetCRLFromStore** function gets the first or next [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for the specified issuer. The function also performs the enabled verification checks on the CRL. The new
[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) are recommended instead of this function.

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `pIssuerContext` [in, optional]

A pointer to an issuer
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context). The *pIssuerContext* pointer can come from this store or another store, or could have been created by the calling
[CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext). If **NULL** is passed for this parameter, all the CRLs in the store are found.

### `pPrevCrlContext` [in]

A pointer to a
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context). An issuer can have multiple CRLs. For example, it can generate delta CRLs by using an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) version 3 extension. This parameter must be **NULL** on the first call to get the CRL. To get the next CRL for the issuer, the parameter is set to the **CRL_CONTEXT** returned by a previous call. A non-**NULL***pPrevCrlContext* is always freed by this function by calling [CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext), even for an error.

### `pdwFlags` [in, out]

The following flag values are defined to enable verification checks on the returned CRL. These flags can be combined using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_SIGNATURE_FLAG** | Uses the public key in the issuer's certificate to verify the signature on the returned CRL. |
| **CERT_STORE_TIME_VALIDITY_FLAG** | Gets the current time and verifies that it is within the time between the CRL's ThisUpdate and NextUpdate. |
| **CERT_STORE_BASE_CRL_FLAG** | Gets a base CRL. |
| **CERT_STORE_DELTA_CRL_FLAG** | Gets a delta CRL. |

If an enabled verification check succeeds, its flag is set to zero.

If an enabled verification check fails, its flag remains set upon return. If *pIssuerContext* is **NULL**, then an enabled CERT_STORE_SIGNATURE_FLAG always fails and the CERT_STORE_NO_ISSUER_FLAG is also set. For more details, see Remarks.

If only one of CERT_STORE_BASE_CRL_FLAG or CERT_STORE_DELTA_CRL_FLAG is set, this function returns either a base or delta CRL and the appropriate base or delta flag will be cleared on return. If both flags are set, only one of the flags will be cleared.

For a verification check failure, a pointer to the first or next
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) is still returned and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is not updated.

## Return value

If the function succeeds, the return value is a pointer to a read-only [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context).

If the function fails and the first or next CRL is not found, the return value is **NULL**.

The returned [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) must be freed by calling
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext). However, when the returned **CRL_CONTEXT** is supplied for *pPrevCrlContext* on a subsequent call, the function frees it.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Value | Description |
| --- | --- |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the CRL context pointed to by the *pPrevCrlContext* parameter, or an unsupported flag was set in *pdwFlags*. |
| **CRYPT_E_NOT_FOUND** | Either no CRLs existed in the store for the issuer, or the function reached the end of the store's list. |

## Remarks

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext) can be called to make a duplicate CRL.

The hexadecimal values of the flags can be combined using a bitwise-**OR** operation to enable both verifications. For example, to enable both verifications, the **DWORD** value pointed to by *pdwFlags* is set to value CERT_STORE_SIGNATURE_FLAG | CERT_STORE_TIME_VALIDITY_FLAG. If the CERT_STORE_SIGNATURE_FLAG verification succeeded, but CERT_STORE_TIME_VALIDITY_FLAG verification failed, the **DWORD** value pointed to by *pdwFlags* is set to CERT_STORE_TIME_VALIDITY_FLAG when the function returns.

## See also

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext)

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
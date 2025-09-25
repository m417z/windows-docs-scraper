# CertEnumCRLsInStore function

## Description

The **CertEnumCRLsInStore** function retrieves the first or next [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Used in a loop, this function can retrieve in sequence all CRL contexts in a certificate store.

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `pPrevCrlContext` [in]

A pointer to the previous
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure found. The *pPrevCrlContext* parameter must be **NULL** to get the first CRL in the store. Successive CRLs are enumerated by setting *pPrevCrlContext* to the pointer returned by a previous call to the function. This function frees the **CRL_CONTEXT** referenced by non-**NULL** values of this parameter. The enumeration skips any CRLs previously deleted by
[CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore).

## Return value

If the function succeeds, the return value is a pointer to the next
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) in the store.

**NULL** is returned if the function fails. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the certificate context pointed to by *pPrevCrlContext*. |
| **CRYPT_E_NOT_FOUND** | No CRL was found. This happens if the store is empty or the end of the store's list is reached. |

## Remarks

The returned pointer is freed when it is passed as the *pPrevCrlContext* on a subsequent call to the function. Otherwise, the pointer must explicitly be freed by calling
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext). A *pPrevCrlContext* that is not **NULL** is always freed when passed to this function through a call to **CertFreeCRLContext**, even if the function itself returns an error.

A duplicate of the CRL [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by this function can be made by calling
[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext).

## See also

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore)

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext)

[CertFindCRLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcrlinstore)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
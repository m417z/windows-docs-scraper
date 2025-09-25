# CertEnumCTLsInStore function

## Description

The **CertEnumCTLsInStore** function retrieves the first or next [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Used in a loop, this function can retrieve in sequence all CTL contexts in a certificate store.

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `pPrevCtlContext` [in]

A pointer to the previous
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure found. It must be **NULL** to get the first CTL in the store. Successive CTLs are enumerated by setting *pPrevCtlContext* to the pointer returned by a previous call. This function frees the **CTL_CONTEXT** referenced by non-**NULL** values of this parameter. The enumeration skips any CTLs previously deleted by
[CertDeleteCTLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletectlfromstore).

## Return value

If the function succeeds, the return value is a pointer to a read-only
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context).

If the function fails and a CTL is not found, the return value is **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | Either no CTLs exist in the store, or the function reached the end of the store's list. |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the CTL context pointed to by the *pPrevCtlContext* parameter. |

## Remarks

The returned pointer is freed when passed as the *pPrevCtlContext* on a subsequent call. Otherwise, the pointer must be explicitly freed by calling
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext). A *pPrevCtlContext* that is not **NULL** is always freed by this function (through a call to **CertFreeCTLContext**), even for an error.

A duplicate can be made by calling
[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext).

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertDeleteCTLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletectlfromstore)

[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertDeleteCRLFromStore function

## Description

The **CertDeleteCRLFromStore** function deletes the specified [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context from the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure to be deleted.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The store was opened read-only, and a delete operation is not allowed. |

## Remarks

All subsequent get or find operations for the CRL in this store fail. However, memory allocated for the CRL is not freed until all duplicated contexts have also been freed.

The *pCrlContext* parameter is always freed by this function by using
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext), even for an error.

## See also

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertDeleteCTLFromStore function

## Description

The **CertDeleteCTLFromStore** function deletes the specified [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context from a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure to be deleted.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The store was opened read-only, and a delete operation is not allowed. |

## Remarks

All subsequent get or find operations for the CTL in this store fail. However, memory allocated for the CTL is not freed until all duplicated contexts have also been freed.

The *pCtlContext* parameter is always freed by this function by using
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext), even for an error.

## See also

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
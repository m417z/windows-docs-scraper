# CertCloseStore function

## Description

The **CertCloseStore** function closes a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) handle and reduces the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on the store. There needs to be a corresponding call to **CertCloseStore** for each successful call to the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) or
[CertDuplicateStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatestore) functions.

## Parameters

### `hCertStore` [in]

Handle of the certificate store to be closed.

### `dwFlags` [in]

Typically, this parameter uses the default value zero. The default is to close the store with memory remaining allocated for contexts that have not been freed. In this case, no check is made to determine whether memory for contexts remains allocated.

Set flags can force the freeing of memory for all of a store's [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL), and [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) contexts when the store is closed. Flags can also be set that check whether all of the store's certificate, CRL, and CTL contexts have been freed. The following values are defined.

| Value | Meaning |
| --- | --- |
| **CERT_CLOSE_STORE_CHECK_FLAG** | Checks for nonfreed certificate, CRL, and CTL contexts. A returned error code indicates that one or more store elements is still in use. This flag should only be used as a diagnostic tool in the development of applications. |
| **CERT_CLOSE_STORE_FORCE_FLAG** | Forces the freeing of memory for all contexts associated with the store. This flag can be safely used only when the store is opened in a function and neither the store handle nor any of its contexts are passed to any called functions. For details, see Remarks. |

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If CERT_CLOSE_STORE_CHECK_FLAG is not set or if it is set and all contexts associated with the store have been freed, the return value is **TRUE**.

If CERT_CLOSE_STORE_CHECK_FLAG is set and memory for one or more contexts associated with the store remains allocated, the return value is **FALSE**. The store is always closed even when the function returns **FALSE**. For details, see Remarks.

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is set to CRYPT_E_PENDING_CLOSE if memory for contexts associated with the store remains allocated. Any existing value returned by **GetLastError** is preserved unless CERT_CLOSE_STORE_CHECK_FLAG is set.

## Remarks

While a certificate store is open, [contexts](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from that store can be retrieved or duplicated. When a *context* is retrieved or duplicated, its reference count is incremented. When a context is freed by passing it to a search or enumeration function as a previous context or by using
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext),
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext), or
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext), its reference count is decremented. When a context's reference count reaches zero, memory allocated for that context is automatically freed. When the memory allocated for a context has been freed, any pointers to that context become not valid.

By default, memory used to store contexts with reference count greater than zero is not freed when a certificate store is closed. References to those contexts remain valid; however, this can cause memory leaks. Also, any changes made to the properties of a context after the store has been closed are not persisted.

To force the freeing of memory for all contexts associated with a store, set CERT_CLOSE_STORE_FORCE_FLAG. With this flag set, memory for all contexts associated with the store is freed and all pointers to certificate, CRL, or CTL contexts associated with the store become not valid. This flag should only be set when the store is opened in a function and neither the store handle nor any of its contexts were ever passed to any called functions.

The status of reference counts on contexts associated with a store can be checked when the store is closed by using CERT_CLOSE_STORE_CHECK_FLAG. When this flag is set, and all certificate, CRL, or CTL contexts have not been released, the function returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns CRYPT_E_PENDING_CLOSE. Note that the store is still closed when **FALSE** is returned and the memory for any active contexts is not freed.

If CERT_STORE_NO_CRYPT_RELEASE_FLAG was not set when the store was opened, closing a store releases its CSP handle.

## See also

[CertDuplicateStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatestore)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext)
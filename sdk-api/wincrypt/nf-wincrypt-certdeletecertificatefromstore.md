# CertDeleteCertificateFromStore function

## Description

The **CertDeleteCertificateFromStore** function deletes the specified certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure to be deleted.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Indicates the store was opened as read-only and a delete operation is not allowed. |

## Remarks

After a certificate is deleted from a [store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), all subsequent attempts to get or find that certificate in that store will fail. However, memory allocated for the certificate is not freed until all duplicated contexts have also been freed.

The **CertDeleteCertificateFromStore** function always frees *pCertContext* by calling the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function, even if an error is encountered. Freeing the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) reduces the context's [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) by one. If the reference count reaches zero, memory allocated for the certificate is freed.

#### Examples

For an example that uses this function, see [Example C Program: Deleting Certificates from a Certificate Store](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-deleting-certificates-from-a-certificate-store).

## See also

[CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
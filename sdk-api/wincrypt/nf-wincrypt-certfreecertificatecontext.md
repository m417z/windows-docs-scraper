# CertFreeCertificateContext function

## Description

The **CertFreeCertificateContext** function frees a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) by decrementing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). When the reference count goes to zero, **CertFreeCertificateContext** frees the memory used by a certificate context.

To free a context obtained by a get, duplicate, or create function, call the appropriate free function. To free a context obtained by a find or enumerate function, either pass it in as the previous context parameter to a subsequent invocation of the function, or call the appropriate free function. For more information, see the reference topic for the function that obtains the context.

## Parameters

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) to be freed.

## Return value

The function always returns nonzero.

## See also

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
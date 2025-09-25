# CertFreeCRLContext function

## Description

The **CertFreeCRLContext** function frees a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context by decrementing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). When the reference count goes to zero, **CertFreeCRLContext** frees the memory used by a CRL [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

To free a context obtained by a get, duplicate, or create function, call the appropriate free function. To free a context obtained by a find or enumerate function, either pass it in as the previous context parameter to a subsequent invocation of the function, or call the appropriate free function. For more information, see the reference topic for the function that obtains the context.

## Parameters

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) to be freed.

## Return value

The function always returns **TRUE**.

## See also

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
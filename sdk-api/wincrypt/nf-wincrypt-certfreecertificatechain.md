# CertFreeCertificateChain function

## Description

The **CertFreeCertificateChain** function frees a certificate chain by reducing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). If the reference count becomes zero, memory allocated for the chain is released.

To free a context obtained by a get, duplicate, or create function, call the appropriate free function. To free a context obtained by a find or enumerate function, either pass it in as the previous context parameter to a subsequent invocation of the function, or call the appropriate free function. For more information, see the reference topic for the function that obtains the context.

## Parameters

### `pChainContext` [in]

A pointer to a
[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) certificate chain context to be freed. If the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on the context reaches zero, the storage allocated for the context is freed.

## See also

[CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)

[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
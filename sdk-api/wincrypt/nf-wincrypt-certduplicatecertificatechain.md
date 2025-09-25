# CertDuplicateCertificateChain function

## Description

The **CertDuplicateCertificateChain** function duplicates a pointer to a certificate chain by incrementing the chain's [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `pChainContext` [in]

A pointer to a
[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) chain context to be duplicated.

## Return value

If the function succeeds, a pointer is returned to the chain context. This pointer has the same value as the *pChainContext* passed into the function. When you have finished using the chain context, release the chain context by calling the [CertFreeCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechain) function.

If the function fails, **NULL** is returned.

## See also

[CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)

[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
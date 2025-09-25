# CertCreateCertificateChainEngine function

## Description

The **CertCreateCertificateChainEngine** function creates a new, nondefault chain engine for an application. A chain engine restricts the certificates in the root store that can be used for verification, restricts the certificate stores to be searched for certificates and [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs), sets a time-out limit for searches that involve URLs, and limits the number of certificates checked between checking for a certificate cycle.

## Parameters

### `pConfig` [in]

A pointer to a
[CERT_CHAIN_ENGINE_CONFIG](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_engine_config) data structure that specifies the parameters for the chain engine.

### `phChainEngine` [out]

A pointer to the handle of the chain engine created. When you have finished using the chain engine, release the chain engine by calling the [CertFreeCertificateChainEngine](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechainengine) function.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The *phChainEngine* parameter returns the chain engine handle.

## See also

[CERT_CHAIN_ENGINE_CONFIG](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_engine_config)

[CertFreeCertificateChainEngine](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechainengine)

[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
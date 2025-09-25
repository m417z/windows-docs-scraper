# CertFreeCertificateChainList function

## Description

The **CertFreeCertificateChainList** function frees the array of pointers to chain contexts.

## Parameters

### `prgpSelection` [in]

A pointer to a [PCCERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure returned by the [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains) function.

## Remarks

 Before calling the **CertFreeCertificateChainList** function, you must call the [CertFreeCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechain) function on each chain context within the array pointed to by the *prgpSelection* parameter.
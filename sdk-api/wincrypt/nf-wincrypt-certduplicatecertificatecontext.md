# CertDuplicateCertificateContext function

## Description

The **CertDuplicateCertificateContext** function duplicates a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) by incrementing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure for which the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is incremented.

## Return value

Currently, a copy is not made of the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), and the returned pointer to a context has the same value as the pointer to a context that was input. If the pointer passed into this function is **NULL**, **NULL** is returned. When you have finished using the duplicate context, decrease its reference count by calling the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

## See also

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
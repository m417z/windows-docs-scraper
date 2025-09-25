# CertDuplicateCRLContext function

## Description

The **CertDuplicateCRLContext** function duplicates a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context by incrementing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure for which the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is being incremented.

## Return value

Currently, a copy is not made of the context, and the returned context is the same as the context that was input. If the pointer passed into this function is **NULL**, **NULL** is returned.

## See also

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
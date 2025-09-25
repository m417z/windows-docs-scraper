# CertDuplicateCTLContext function

## Description

The **CertDuplicateCTLContext** function duplicates a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context by incrementing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure for which the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is being incremented.

## Return value

Currently, a copy is not made of the context, and the returned pointer to [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) is the same as pointer input. If the pointer passed into this function is **NULL**, **NULL** is returned.

## See also

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertDuplicateStore function

## Description

The **CertDuplicateStore** function duplicates a store handle by incrementing the store's [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `hCertStore` [in]

A handle of the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for which the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is being incremented.

## Return value

Currently, a copy is not made of the handle, and the returned handle is the same as the handle that was input. If **NULL** is passed in, the called function will raise an access violation exception.

## See also

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
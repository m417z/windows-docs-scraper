# PFN_CERT_STORE_PROV_READ_CTL callback function

## Description

The **CertStoreProvReadCTL** callback function is called to read the provider's copy of the [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) context and, if it exists, to create a new CTL context. Currently, this callback function is not called directly by the store APIs but it can be exported to support other providers based on it.

## Parameters

### `hStoreProv` [in]

**HCERTSTOREPROV** handle to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `pStoreCtlContext` [in]

A pointer to a
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure.

### `dwFlags` [in]

Any needed flag values.

### `ppProvCtlContext` [out]

A pointer to a pointer to a [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure to be returned by the function. The context will be freed by calling [CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).

## Return value

Returns **TRUE** if the function succeeds or **FALSE** if it fails.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)
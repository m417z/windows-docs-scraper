# PFN_CERT_STORE_PROV_WRITE_CTL callback function

## Description

The **CertStoreProvWriteCTL** callback function can be called by
[CertAddEncodedCTLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedctltostore),
[CertAddCTLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctlcontexttostore) or
[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore) before a CTL is added to the store.

## Parameters

### `hStoreProv` [in]

**HCERTSTOREPROV** handle to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `pCtlContext` [in]

A pointer to a
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure.

### `dwFlags` [in]

Any needed flag values.

## Return value

Returns **TRUE** if elements can be added to the store.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertAddCTLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctlcontexttostore)

[CertAddEncodedCTLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedctltostore)

[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore)
# PFN_CERT_STORE_PROV_CLOSE callback function

## Description

An application-defined callback function that is called by
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) when the store's [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) is decremented to zero.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `dwFlags` [in]

Copy of the *dwFlags* passed as a parameter to
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore).

## See also

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
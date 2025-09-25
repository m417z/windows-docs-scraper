# PFN_CERT_STORE_PROV_READ_CRL callback function

## Description

An application-defined callback function that reads the provider's copy of the [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) context. If one exists, a new CRL context is created.

Currently not called directly by the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) functions. However, might be exported to support other providers.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pStoreCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) of the CRL to be read.

### `dwFlags` [in]

Reserved for future use and is set to zero.

### `ppProvCrlContext` [out]

A pointer to a pointer to provider's copy of the CRL context. The context will be freed by calling
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext).

## Return value

Returns TRUE if the CRL was successfully read.

## See also

[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info)

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)
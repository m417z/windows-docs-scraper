# PFN_CERT_STORE_PROV_READ_CERT callback function

## Description

An application-defined callback function that reads the provider's copy of the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). If one exists, a new certificate context is created. Currently not called directly by the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) functions. However, it might be exported to support other providers.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pStoreCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the certificate to be read.

### `dwFlags` [in]

Reserved for future use and is set to zero.

### `ppProvCertContext` [out]

A pointer to a pointer to provider's copy of the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The context will be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).

## Return value

Returns **TRUE** if the certificate was successfully read.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info)

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)
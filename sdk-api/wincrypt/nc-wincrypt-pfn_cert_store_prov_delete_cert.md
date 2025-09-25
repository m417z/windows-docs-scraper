# PFN_CERT_STORE_PROV_DELETE_CERT callback function

## Description

An application-defined callback function that is called by
[CertDeleteCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecertificatefromstore) before deleting a certificate from the store.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pCertContext` [in]

A pointer to the certificate context to be deleted.

### `dwFlags` [in]

Reserved for future use and is set to zero.

## Return value

Returns **TRUE** if it is okay to delete the certificate from the store. Otherwise, returns **FALSE**.

## See also

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
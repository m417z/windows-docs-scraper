# PFN_CERT_STORE_PROV_DELETE_CRL callback function

## Description

An application-defined callback function that is called by
[CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore) before deleting the CRL from the store.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pCrlContext` [in]

A pointer to the CRL context to be deleted.

### `dwFlags` [in]

Reserved for future use and is set to zero.

## Return value

Returns **TRUE** if it is okay to delete from the store. Otherwise, returns **FALSE**.

## See also

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
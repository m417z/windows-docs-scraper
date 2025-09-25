# PFN_CERT_STORE_PROV_WRITE_CRL callback function

## Description

An application-defined callback function that is called by
[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore),
[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore) and
[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore) before adding to the store. In addition to the encoded [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), the added *pCrlContext* might also have properties.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pCrlContext` [in]

See
[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore).

### `dwFlags` [in]

CERT_STORE_PROV_WRITE_ADD_FLAG is used to specify when this function is called by the following functions that add a [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to the store:

[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore)

[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore)

[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore)

## Return value

Returns **TRUE** if it is okay to update the store.

## See also

[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info)

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore)

[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore)

[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore)

[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func)
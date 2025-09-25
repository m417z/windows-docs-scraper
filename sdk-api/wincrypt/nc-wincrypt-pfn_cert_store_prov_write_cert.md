# PFN_CERT_STORE_PROV_WRITE_CERT callback function

## Description

An application-defined callback function that is called by
[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore),
[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore) and
[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore) before adding to the store. In addition to the encoded certificate, the added *pCertContext* might also have properties.

## Parameters

### `hStoreProv` [in]

Provider specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pCertContext` [in]

See
[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore).

### `dwFlags` [in]

CERT_STORE_PROV_WRITE_ADD_FLAG is set when this function is called by the following functions that add a certificate to the [store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly):

[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore)

[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore)

[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore)

## Return value

Returns **TRUE** if it is okay to update the store.

## See also

[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info)

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore)

[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore)

[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore)

[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func)
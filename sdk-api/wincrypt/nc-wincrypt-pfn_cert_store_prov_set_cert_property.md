# PFN_CERT_STORE_PROV_SET_CERT_PROPERTY callback function

## Description

An application-defined callback function that is called by
[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty) before setting the certificate's property. It is also called by
[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) when getting a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) property that needs to be created and then persisted through the set.

Upon input, the property has not been set for the *pCertContext* parameter.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pCertContext` [in]

See
[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty).

### `dwPropId` [in]

See [CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty).

### `dwFlags` [in]

Copy of the *dwFlags* passed as a parameter to [CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty).

### `pvData` [in]

See [CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty).

## Return value

Returns **TRUE** if it is okay to set the property.

## See also

[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info)

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)
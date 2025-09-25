# PFN_CERT_STORE_PROV_SET_CRL_PROPERTY callback function

## Description

An application-defined callback function that is called by
[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty) before setting the CRL's property. It is also called by
[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty) when getting a hash property that needs to be created and then persisted through the set.

Upon input, the property has not been set for the *pCrlContext* parameter.

## Parameters

### `hStoreProv` [in]

Provider-specific value returned in
[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info) by
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func).

### `pCrlContext` [in]

See
[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty).

### `dwPropId` [in]

See [CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty).

### `dwFlags` [in]

Copy of the *dwFlags* passed as a parameter to [CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty).

### `pvData` [in]

See [CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty).

## Return value

Returns **TRUE** if it is okay to set the property.

## See also

[CERT_STORE_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_store_prov_info)

[Callback Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func)

[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty)

[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty)
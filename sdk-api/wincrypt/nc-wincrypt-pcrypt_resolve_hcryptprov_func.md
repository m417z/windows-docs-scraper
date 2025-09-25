# PCRYPT_RESOLVE_HCRYPTPROV_FUNC callback function

## Description

[The **PCRYPT_RESOLVE_HCRYPTPROV_FUNC** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **PCRYPT_RESOLVE_HCRYPTPROV_FUNC** function returns a handle to a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) by using the *phCryptProv* parameter to receive the key being imported. It is a callback function called from the context of the [CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8) function. The function must be implemented by the developer to suit each application.

## Parameters

### `pPrivateKeyInfo` [in]

A pointer to a [CRYPT_PRIVATE_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_private_key_info) structure that describes the key being imported.

### `phCryptProv` [out]

A pointer to the [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) to receive the CSP.

### `pVoidResolveFunc` [in]

The **pVoidResolveFunc** member passed in by the caller in the [CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params) structure.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## See also

[CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params)

[CRYPT_PRIVATE_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_private_key_info)

[CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8)

[HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov)
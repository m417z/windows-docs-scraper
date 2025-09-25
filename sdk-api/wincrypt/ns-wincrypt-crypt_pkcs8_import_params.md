# CRYPT_PKCS8_IMPORT_PARAMS structure

## Description

[The **CRYPT_PKCS8_IMPORT_PARAMS** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PKCS8_IMPORT_PARAMS** structure contains a PKCS #8 [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and pointers to callback
functions. **CRYPT_PKCS8_IMPORT_PARAMS** is used by the [CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8) function. The first callback supplies the algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) needed to specify the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) into which the key will be imported. If the private key in PKCS #8 is encrypted, the **CRYPT_PKCS8_IMPORT_PARAMS** structure contains the encrypted private key, and the second callback is used to decrypt this private key.

## Members

### `PrivateKey`

A [CRYPT_DIGEST_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the PKCS #8 data.

### `pResolvehCryptProvFunc`

A [PCRYPT_RESOLVE_HCRYPTPROV_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_resolve_hcryptprov_func) pointer that points to data used by a user-defined function that retrieves a handle to a CSP.

### `pVoidResolveFunc`

An **LPVOID** value that identifies the function used to retrieve the CSP provider handle.

### `pDecryptPrivateKeyFunc`

A [PCRYPT_DECRYPT_PRIVATE_KEY_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_decrypt_private_key_func) pointer that points to a callback function used to decrypt the private key.

### `pVoidDecryptFunc`

An **LPVOID** value that provides data used for encryption, such as key, initialization vector, and password.

## See also

[CryptExportPKCS8Ex](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8ex)

[CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8)

[PCRYPT_DECRYPT_PRIVATE_KEY_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_decrypt_private_key_func)

[PCRYPT_RESOLVE_HCRYPTPROV_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_resolve_hcryptprov_func)
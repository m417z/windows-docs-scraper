# PCRYPT_DECRYPT_PRIVATE_KEY_FUNC callback function

## Description

[The **PCRYPT_DECRYPT_PRIVATE_KEY_FUNC** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **PCRYPT_DECRYPT_PRIVATE_KEY_FUNC** function decrypts
the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and returns the decrypted key in the *pbClearTextKey* parameter. **PCRYPT_DECRYPT_PRIVATE_KEY_FUNC** is a callback function specified in a [CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params) structure. It is used when a [CRYPT_ENCRYPTED_PRIVATE_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encrypted_private_key_info) structure contains a private key that needs to be decrypted. The [CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8) function uses this function. The function must be implemented by the developer to suit each application.

## Parameters

### `Algorithm` [in]

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that identifies the algorithm used to encrypt the PrivateKeyInfo ASN.1 type found in the PKCS #8 standard.

### `EncryptedPrivateKey` [in]

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) value that identifies the encrypted private key [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

### `pbClearTextKey` [out]

A pointer to a **BYTE** buffer to receive the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This parameter can be **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbClearTextKey` [in, out]

A pointer to a **DWORD** value that identifies the size, in bytes, of the *pbClearTextKey* buffer. If the size is zero, then *pcbClearTextKey* should be filled with the size, in bytes, required to decrypt the
key, and *pbClearTextKey* should be ignored.

### `pVoidDecryptFunc` [in]

An **LPVOID** value that provides data used in decryption, such as key, initialization vector, and password.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## See also

[CRYPT_ENCRYPTED_PRIVATE_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encrypted_private_key_info)

[CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params)

[CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8)
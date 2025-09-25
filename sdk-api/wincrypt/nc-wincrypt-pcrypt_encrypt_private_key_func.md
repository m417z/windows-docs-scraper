# PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC callback function

## Description

[The **PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC** function encrypts the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and returns
the encrypted contents in the *pbEncryptedKey* parameter. It is a callback function identified in a [CRYPT_PKCS8_EXPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_export_params) structure that creates a PKCS #8 [CRYPT_ENCRYPTED_PRIVATE_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encrypted_private_key_info) structure. The function must be implemented by the developer to suit each application.

## Parameters

### `pAlgorithm` [out]

A pointer to a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure to receive the algorithm used to encrypt the PrivateKeyInfo ASN.1 type found in the PKCS #8 standard.

### `pClearTextPrivateKey` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) private key to be encrypted.

### `pbEncryptedKey` [out]

A pointer to a **BYTE** buffer to receive the encrypted [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). If this parameter is **NULL**, *pcbEncryptedKey* will return the size, in bytes, of memory needed to contain the encrypted key on a subsequent call to this function.

### `pcbEncryptedKey` [in, out]

A pointer to a **DWORD** variable that contains the size, in bytes, of the *pbEncryptedKey* buffer. If pbEncryptedKey is **NULL**, then *pcbEncryptedKey* is
set to the size, in bytes, required to encrypt the
key. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pVoidEncryptFunc` [in]

An **LPVOID** variable that contains data used for encryption, such as key, initialization vector, and password.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## See also

[CRYPT_PKCS8_EXPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_export_params)

[PCRYPT_DECRYPT_PRIVATE_KEY_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_decrypt_private_key_func)
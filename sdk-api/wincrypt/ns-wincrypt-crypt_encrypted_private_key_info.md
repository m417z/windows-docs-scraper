# CRYPT_ENCRYPTED_PRIVATE_KEY_INFO structure

## Description

[The **CRYPT_ENCRYPTED_PRIVATE_KEY_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_ENCRYPTED_PRIVATE_KEY_INFO** structure contains the information in a PKCS #8
EncryptedPrivateKeyInfo ASN.1 type found in the PKCS #8 standard.

## Members

### `EncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that indicates the algorithm used for encryption.

### `EncryptedPrivateKey`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encrypted private key data.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CryptExportPKCS8Ex](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8ex)

[PCRYPT_DECRYPT_PRIVATE_KEY_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_decrypt_private_key_func)

[PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_encrypt_private_key_func)
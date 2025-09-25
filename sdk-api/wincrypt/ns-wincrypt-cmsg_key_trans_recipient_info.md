# CMSG_KEY_TRANS_RECIPIENT_INFO structure

## Description

The **CMSG_KEY_TRANS_RECIPIENT_INFO** structure contains information used in key transport algorithms.

## Members

### `dwVersion`

Indicates the version of the structure. If **RecipientId** uses the ISSUER_SERIAL_NUMBER to identify the recipient, **dwVersion** is set to zero. If **RecipientId** uses KEYID, **dwVersion** is set to two.

### `RecipientId`

A [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) that identifies the recipient. Currently, only ISSUER_SERIAL_NUMBER or KEYID choices in the **CERT_ID** are valid.

### `KeyEncryptionAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) that identifies the key-encryption algorithm and any associated parameters used to encrypt the content encryption key.

### `EncryptedKey`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the bytes of the encrypted session key.
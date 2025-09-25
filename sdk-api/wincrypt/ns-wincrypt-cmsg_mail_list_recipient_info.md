# CMSG_MAIL_LIST_RECIPIENT_INFO structure

## Description

The **CMSG_MAIL_LIST_RECIPIENT_INFO** structure contains information used for previously distributed [symmetric](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) key-encryption keys (KEK).

## Members

### `dwVersion`

Indicates the version of the structure. This member is always four.

### `KeyId`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that identifies a [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)-encryption key previously distributed to the sender and one or more recipients.

### `KeyEncryptionAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) that identifies the key-encryption algorithm and any associated parameters used to encrypt the content encryption key.

### `EncryptedKey`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encrypted content encryption key.

### `Date`

Optional. When present, this member specifies a single key-encryption key from a previously distributed set.

### `pOtherAttr`

Optional pointer to a
[CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value) structure containing additional information.
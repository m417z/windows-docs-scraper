# CMSG_KEY_AGREE_RECIPIENT_INFO structure

## Description

The **CMSG_KEY_AGREE_RECIPIENT_INFO** structure contains information used for key agreement algorithms.

## Members

### `dwVersion`

A **DWORD** that indicates the version of the structure. Always set to three.

### `dwOriginatorChoice`

A **DWORD** that indicates the key identifier to use.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_AGREE_ORIGINATOR_CERT** | OriginatorCertId |
| **CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY** | OriginatorPublicKeyInfo |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.OriginatorCertId`

A [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) that identifies the public key of the message originator.

### `DUMMYUNIONNAME.OriginatorPublicKeyInfo`

A [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the public key of the message originator.

### `UserKeyingMaterial`

 A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that indicates that a different key is generated each time the same two parties generate a pair of keys. The sender provides the bits of this [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) with some key agreement algorithms. This member can be **NULL**.

### `KeyEncryptionAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) that identifies the key-encryption algorithm and any associated parameters used to encrypt the content encryption key.

### `cRecipientEncryptedKeys`

The number of elements in the **rgpRecipientEncryptedKeys** array.

### `rgpRecipientEncryptedKeys`

The address of an array of [CMSG_RECIPIENT_ENCRYPTED_KEY_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_recipient_encrypted_key_info) structures that contains information about the key recipients. The **cRecipientEncryptedKeys** member contains the number of elements in this array.
# CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO structure

## Description

The **CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO** structure contains information about a message recipient that is using key agreement key management.This structure is used with the [CMSG_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_recipient_encode_info) structure.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `KeyEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used for encryption.

For ECC recipients, the **pszObjId** member of the [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure should be set to szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF with the **dwKeyChoice** member of this **CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO** structure set to CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE.

### `pvKeyEncryptionAuxInfo`

This member is not currently used. It must be set to **NULL**.

### `KeyWrapAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used for key wrapping.

### `pvKeyWrapAuxInfo`

A pointer to a [CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info) structure that specifies the key wrapping bit length. This member is only used if the **KeyWrapAlgorithm** member specifies an RC2 algorithm. If **KeyWrapAlgorithm** specifies an algorithm other than an RC2 algorithm, this member is not used and must be **NULL**.

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) obtained by using the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function. This member is optional and can be **NULL**.This member's data type is **HCRYPTPROV**.

### `dwKeySpec`

This member is not currently used.

### `dwKeyChoice`

Indicates the type of key agreement. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE** | Create a temporary [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to encrypt the content encryption key. |
| **CMSG_KEY_AGREE_STATIC_KEY_CHOICE** | This value is not currently used. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pEphemeralAlgorithm`

A pointer to a
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the ephemeral public key algorithm and parameters. This member is used when the **dwKeyChoice** member contains **CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE**.

### `DUMMYUNIONNAME.pSenderId`

A pointer to a [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure. This member is used when the **dwKeyChoice** member contains **CMSG_KEY_AGREE_STATIC_KEY_CHOICE**. This member is not currently used.

### `UserKeyingMaterial`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains user keying material (UKM) provided by the sender to ensure that a different key is generated each time the same two parties generate a pair-wise key. This member is optional and all members should be set to zero if not used.

### `cRecipientEncryptedKeys`

The number of elements in the **rgpRecipientEncryptedKeys** array.

### `rgpRecipientEncryptedKeys`

An array of [CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_recipient_encrypted_key_encode_info) structures, one for each recipient to receive this key agreement key. The **cRecipientEncryptedKeys** member contains the number of elements in this structure.

## See also

[CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id)

[CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info)

[CMSG_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_recipient_encode_info)

[CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_recipient_encrypted_key_encode_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)
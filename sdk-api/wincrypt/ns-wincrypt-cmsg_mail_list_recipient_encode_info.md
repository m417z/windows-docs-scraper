# CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO structure

## Description

The **CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO** structure is used with previously distributed [symmetric keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for decrypting the content key encryption key (KEK).

## Members

### `cbSize`

The size, in bytes, of this data structure.

### `KeyEncryptionAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that indicates the encryption algorithm used.

### `pvKeyEncryptionAuxInfo`

A pointer to a structure that contains any additional encryption information.

### `hCryptProv`

The provider used to do the recipient key encryption and export. If **NULL**, the provider specified in [CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info) is used.

### `dwKeyChoice`

Indicates which member of the following union will be used. Currently only CMSG_MAIL_LIST_HANDLE_KEY_CHOICE can be used.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hKeyEncryptionKey`

An **HCRYPTKEY** value used with the CMSG_MAIL_LIST_HANDLE_KEY_CHOICE value of the *dwKeyChoice* parameter.

### `DUMMYUNIONNAME.pvKeyEncryptionKey`

A pointer to a void. Reserved for a future potential pointer choice.

### `KeyId`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) key identifier of the key-encryption key that was previously distributed to the message sender and one or more recipients.

### `Date`

Optional **FILETIME** value. When present, specifies a single key encryption key (KEK) from a set that was previously distributed.

### `pOtherAttr`

Optional pointer to a
[CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value) structure that contains encryption attributes.
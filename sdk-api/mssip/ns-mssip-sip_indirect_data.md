# SIP_INDIRECT_DATA structure

## Description

The **SIP_INDIRECT_DATA** structure contains the digest of the hashed subject information.

## Members

### `Data`

A [CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value) structure used to encode the attribute.

### `DigestAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the digest algorithm to use to create the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly).

### `Digest`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the hash of the subject. For information about **CRYPT_HASH_BLOB**, see **CRYPT_INTEGER_BLOB**.
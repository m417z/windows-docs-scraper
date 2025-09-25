# CERT_HASHED_URL structure

## Description

The **CERT_HASHED_URL** structure contains a hashed URL.

## Members

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the hash algorithm used to create the URL hash.

### `Hash`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the hash value.

### `pwszUrl`

The address of a null-terminated Unicode string that contains the URL. This member is optional for biometric data and may be **NULL**.

## See also

[CERT_BIOMETRIC_DATA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_biometric_data)

[CERT_LOGOTYPE_DETAILS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_details)

[CERT_LOGOTYPE_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_reference)
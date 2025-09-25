# CRYPT_PRIVATE_KEY_INFO structure

## Description

[The **CRYPT_PRIVATE_KEY_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PRIVATE_KEY_INFO** structure contains a clear-text [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in the PrivateKey field (DER
encoded). **CRYPT_PRIVATE_KEY_INFO** contains the information in a PKCS #8 PrivateKeyInfo ASN.1 type found in the PKCS #8 standard.

## Members

### `Version`

A **DWORD** value that identifies the PKCS #8 version.

### `Algorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that indicates the algorithm in which the private key (RSA or DSA) is to be used.

### `PrivateKey`

A [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the key data.

### `pAttributes`

A [CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure that identifies the PKCS #8 attributes.

## See also

[CryptExportPKCS8Ex](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8ex)

[PCRYPT_RESOLVE_HCRYPTPROV_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_resolve_hcryptprov_func)
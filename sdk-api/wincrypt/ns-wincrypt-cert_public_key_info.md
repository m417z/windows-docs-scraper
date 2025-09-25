# CERT_PUBLIC_KEY_INFO structure

## Description

The **CERT_PUBLIC_KEY_INFO** structure contains a public key and its algorithm.

## Members

### `Algorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the public key algorithm type and associated additional parameters.

### `PublicKey`

BLOB containing an encoded public key.

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[CertComparePublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcomparepublickeyinfo)

[CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore)

[CryptImportPublicKeyInfoEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex)
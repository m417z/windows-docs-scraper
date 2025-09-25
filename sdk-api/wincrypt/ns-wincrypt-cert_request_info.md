# CERT_REQUEST_INFO structure

## Description

The **CERT_REQUEST_INFO** structure contains information for a [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The subject, subject [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), and [attribute BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) are encoded.

## Members

### `dwVersion`

The certificate's version number. Defined version number is shown in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_V1** | version 1 |

### `Subject`

A [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the certificate subject's encoded name.

### `SubjectPublicKeyInfo`

[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure containing the encoded public key and its algorithm.

### `cAttribute`

Number of elements in the **rgAttribute** array.

### `rgAttribute`

A pointer to an array of [CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures, each holding attribute information about the certificate.

## See also

[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info)

[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CryptSignAndEncodeCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencodecertificate)
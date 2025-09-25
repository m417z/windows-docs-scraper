# CERT_ID structure

## Description

The **CERT_ID** structure is used as a flexible means of uniquely identifying a certificate.

## Members

### `dwIdChoice`

A **DWORD** value that indicates which member of the union is being used. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_ID_ISSUER_SERIAL_NUMBER** | IssuerSerialNumber |
| **CERT_ID_KEY_IDENTIFIER** | KeyId |
| **CERT_ID_SHA1_HASH** | HashId |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.IssuerSerialNumber`

A
[CERT_ISSUER_SERIAL_NUMBER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_issuer_serial_number) structure that uniquely identifies a certificate.

### `DUMMYUNIONNAME.KeyId`

A
[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a certificate key identifier.

### `DUMMYUNIONNAME.HashId`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains a SHA1 [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the certificate to be used as a unique identifier of the certificate.
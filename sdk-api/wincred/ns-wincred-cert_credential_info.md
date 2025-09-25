# CERT_CREDENTIAL_INFO structure

## Description

The **CERT_CREDENTIAL_INFO** structure contains a
reference to a certificate.

## Members

### `cbSize`

Size of the structure in bytes. This member should be set to
`sizeof(CERT_CREDENTIAL_INFO)`. This structure might be a larger value in
the future, indicating a newer version of the structure.

### `rgbHashOfCert`

SHA-1 hash of the certificate referenced.

## Remarks

**CERT_HASH_LENGTH** is defined as 20 in WinCred.h.
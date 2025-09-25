# CERT_KEYGEN_REQUEST_INFO structure

## Description

The **CERT_KEYGEN_REQUEST_INFO** structure contains information stored in the Netscape key generation request. The subject and subject [public key BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) are encoded.

## Members

### `dwVersion`

The version number of the certificate. **CERT_KEYGEN_REQUEST_V1** (0) is the only defined version number.

### `SubjectPublicKeyInfo`

A [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the encoded [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `pwszChallengeString`

A random printable string. This string is used by the server to ensure that the key that it is certifying matches the client on the page.

## See also

[CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info)
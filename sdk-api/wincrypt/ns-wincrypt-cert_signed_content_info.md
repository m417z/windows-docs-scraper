# CERT_SIGNED_CONTENT_INFO structure

## Description

The **CERT_SIGNED_CONTENT_INFO** structure contains encoded content to be signed and a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) to hold the signature. The **ToBeSigned** member is an encoded
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info),
[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info),
[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) or
[CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info).

## Members

### `ToBeSigned`

A BLOB that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) and that is to be signed.

### `SignatureAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the signature algorithm type and any associated additional parameters.

### `Signature`

BLOB containing a signed [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the encoded data.

## See also

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))
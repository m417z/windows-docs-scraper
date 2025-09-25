# OCSP_SIGNATURE_INFO structure

## Description

The **OCSP_SIGNATURE_INFO** structure contains a signature for an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) request or response. The [OCSP_SIGNED_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_signed_request_info) and [OCSP_BASIC_SIGNED_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_signed_response_info) structures use this structure.

## Members

### `SignatureAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used to create the **Signature**.

### `Signature`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains a signed hash of an [OCSP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_info) or [OCSP_BASIC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_info) structure.

### `cCertEncoded`

The number of elements in the **rgCertEncoded** array.

### `rgCertEncoded`

An array of pointers to [CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures, each of which contains an encoded signature certificate.

## See also

[CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[OCSP_BASIC_SIGNED_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_signed_response_info)

[OCSP_SIGNED_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_signed_request_info)

[RFC 2560 Online Certificate Status Protocol](https://www.ietf.org/rfc/rfc2560.txt)
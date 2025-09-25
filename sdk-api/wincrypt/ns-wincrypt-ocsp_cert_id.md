# OCSP_CERT_ID structure

## Description

The **OCSP_CERT_ID** structure contains information to identify a certificate in an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) request or response. This structure is used in the [OCSP_REQUEST_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_entry) and [OCSP_BASIC_RESPONSE_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_entry) structures.

## Members

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the algorithm used to create *IssuerNameHash* and *IssuerKeyHash*.

### `IssuerNameHash`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains a hash of the certificate issuer subject name.

### `IssuerKeyHash`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains a hash of the certificate issuer public key.

### `SerialNumber`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains the serial number of the certificate. For more information, see the **SerialNumber** member description for [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info).

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[OCSP_BASIC_RESPONSE_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_entry)

[OCSP_REQUEST_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_entry)
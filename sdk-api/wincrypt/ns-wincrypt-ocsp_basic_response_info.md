# OCSP_BASIC_RESPONSE_INFO structure

## Description

 The **OCSP_BASIC_RESPONSE_INFO** structure contains a basic [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) response as specified by [RFC 2560](https://www.ietf.org/rfc/rfc2560.txt). The RFC specifies that a single response can contain a sequence of certificates for which statuses are provided. The **rgResponseEntry** member of this structure contains an [OCSP_BASIC_RESPONSE_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_entry) structure for each certificate in a sequence.

## Members

### `dwVersion`

A value that indicates the protocol version of the response.

#### OCSP_BASIC_RESPONSE_V1 (0)

### `dwResponderIdChoice`

A value that indicates the type of ID the responder used in this response.

#### OCSP_BASIC_BY_NAME_RESPONDER_ID (1)

#### OCSP_BASIC_BY_KEY_RESPONDER_ID (2)

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ByNameResponderId`

A [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the subject name of the responder signing [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `DUMMYUNIONNAME.ByKeyResponderId`

A [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains a hash of the responder signing certificate [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `ProducedAt`

The date and time at which the response was signed.

### `cResponseEntry`

The number of elements in the *rgResponseEntry* array.

### `rgResponseEntry`

An array of pointers to [OCSP_BASIC_RESPONSE_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_entry) structures, each of which contains a certificate status.

### `cExtension`

The number of elements in the **rgExtension** array.

### `rgExtension`

An array of pointers to [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each of which contains additional information about the response.

## Remarks

OCSP responder applications encode this structure and store it in an [OCSP_BASIC_SIGNED_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_signed_response_info) **ToBeSigned** member. Conversely, OCSP client applications decode the **OCSP_BASIC_SIGNED_RESPONSE_INFO** structure to obtain this structure.

OCSP applications can encode or decode this structure by using **X509_ASN_ENCODING** or **PKCS_7_ASN_ENCODING**.

## See also

[RFC 2560 Online Certificate Status Protocol](https://www.ietf.org/rfc/rfc2560.txt)
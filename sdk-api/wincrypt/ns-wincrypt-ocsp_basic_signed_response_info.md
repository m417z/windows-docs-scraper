# OCSP_BASIC_SIGNED_RESPONSE_INFO structure

## Description

 The **OCSP_BASIC_SIGNED_RESPONSE_INFO** structure contains a basic [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) response with a signature.

## Members

### `ToBeSigned`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) and that contains an encoded [OCSP_BASIC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_info) structure.

### `SignatureInfo`

A pointer to signature information for the **ToBeSigned** data.

## Remarks

In an OCSP responder service, this structure receives an encoded [OCSP_BASIC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_info) structure as its **ToBeSigned** member. The signature of the **ToBeSigned** member is stored in the **SignatureInfo** member. The encoded **OCSP_BASIC_SIGNED_RESPONSE_INFO** structure is stored in an [OCSP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_response_info) structure.

On the receiving end, an OCSP client application must decode the [OCSP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_response_info) **Value** member to obtain this structure and subsequently decode the **OCSP_BASIC_SIGNED_RESPONSE_INFO** **ToBeSigned** member to obtain an [OCSP_BASIC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_info) structure.

OCSP applications can encode or decode this structure by using **X509_ASN_ENCODING** or **PKCS_7_ASN_ENCODING**.

## See also

[CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[OCSP_SIGNATURE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_signature_info)
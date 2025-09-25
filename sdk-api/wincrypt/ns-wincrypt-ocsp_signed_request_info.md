# OCSP_SIGNED_REQUEST_INFO structure

## Description

The **OCSP_SIGNED_REQUEST_INFO** structure contains information for an [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) request with optional signature information.

## Members

### `ToBeSigned`

A BLOB that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) and that contains the OCSP request information.

### `pOptionalSignatureInfo`

A pointer to an [OCSP_SIGNATURE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_signature_info) structure that contains optional signature information.

## Remarks

In an OCSP client application, this structure receives an encoded [OCSP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_info) structure as its **ToBeSigned** member. Optionally, a signature of the **ToBeSigned** member is stored in the **pOptionalSignatureInfo** member.

On the receiving end, an OCSP responder application decodes the incoming request to populate an **OCSP_SIGNED_REQUEST_INFO** structure and subsequently decodes the **ToBeSigned** member to obtain an [OCSP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_request_info) structure.

OCSP applications can encode or decode this structure by using **X509_ASN_ENCODING** or **PKCS_7_ASN_ENCODING**.

## See also

[Constants for CryptEncodeObject and CryptDecodeObject](https://learn.microsoft.com/windows/desktop/SecCrypto/constants-for-cryptencodeobject-and-cryptdecodeobject)

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex)

[CryptSignAndEncodeCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencodecertificate)

[OCSP_SIGNATURE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_signature_info)
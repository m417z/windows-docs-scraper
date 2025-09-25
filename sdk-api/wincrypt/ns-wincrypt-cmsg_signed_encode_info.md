# CMSG_SIGNED_ENCODE_INFO structure

## Description

The **CMSG_SIGNED_ENCODE_INFO** structure contains information to be passed to
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) if *dwMsgType* is CMSG_SIGNED.

## Members

### `cbSize`

Size of this structure in bytes.

### `cSigners`

Number of elements in the **rgSigners** array.

### `rgSigners`

Array of pointers to
[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures each holding signer information.

### `cCertEncoded`

Number of elements in the **rgCertEncoded** array.

### `rgCertEncoded`

Array of pointers to
[CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))
structures, each containing an encoded certificate.

### `cCrlEncoded`

Number of elements in the **rgCrlEncoded** array.

### `rgCrlEncoded`

Array of pointers to
[CRL_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures, each containing an encoded CRL.

### `cAttrCertEncoded`

Number of elements in the **rgAttrCertEncoded** array.
Used only if CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS is defined.

### `rgAttrCertEncoded`

Array of encoded attribute certificates.
Used only if CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS is defined. This array of encoded attribute certificates can be used with CMS for PKCS #7 processing.

## See also

[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))
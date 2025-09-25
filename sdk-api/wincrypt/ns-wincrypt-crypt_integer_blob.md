# CRYPT_INTEGER_BLOB structure

## Description

The CryptoAPI [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure is used for an arbitrary array of bytes. It is declared in Wincrypt.h and provides flexibility for objects that can contain various data types.

## Members

### `cbData`

The count of bytes in the buffer pointed to by *pbData*.

### `pbData`

A pointer to a block of data bytes.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CERT_POLICY_QUALIFIER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_qualifier_info)

[CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info)

[CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_ctrl_add_signer_unauth_attr_para)

[CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info)

[CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value)

[CRYPT_TIME_STAMP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_time_stamp_request_info)

[CertCompareIntegerBlob](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcompareintegerblob)

[CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra)
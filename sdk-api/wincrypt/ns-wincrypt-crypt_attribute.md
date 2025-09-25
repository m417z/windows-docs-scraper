# CRYPT_ATTRIBUTE structure

## Description

The **CRYPT_ATTRIBUTE** structure specifies an attribute that has one or more values.

## Members

### `pszObjId`

An [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that specifies the type of data contained in the **rgValue** array.

### `cValue`

A **DWORD** value that indicates the number of elements in the **rgValue** array.

### `rgValue`

Pointer to an array of [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures. The **cbData** member of the **CRYPT_INTEGER_BLOB** structure indicates the length of the **pbData** member. The **pbData** member contains the attribute information.

## See also

[CERT_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_request_info)

[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info)

[CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_sign_message_para)

[CRYPT_TIME_STAMP_REQUEST_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_time_stamp_request_info)

[CertFindAttribute](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindattribute)
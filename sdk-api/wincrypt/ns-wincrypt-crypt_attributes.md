# CRYPT_ATTRIBUTES structure

## Description

[The **CRYPT_ATTRIBUTES** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_ATTRIBUTES** structure contains an array of attributes.

## Members

### `cAttr`

Number of elements in the **rgAttr** array.

### `rgAttr`

Array of
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures.

## See also

[CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info)

[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute)

[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam)
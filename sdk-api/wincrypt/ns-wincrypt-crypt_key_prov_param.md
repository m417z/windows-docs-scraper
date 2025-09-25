# CRYPT_KEY_PROV_PARAM structure

## Description

The **CRYPT_KEY_PROV_PARAM** structure contains information about a [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) parameter. This structure is used with the
[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure.

## Members

### `dwParam`

Identifies the parameter. For possible values, see the *dwParam* parameter of the
[CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam) function.

### `pbData`

The address of a buffer that contains the parameter data. For more information, see the *pbData* parameter of the
[CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam) function.

### `cbData`

The size, in bytes, of the **pbData** buffer.

### `dwFlags`

This member is reserved for future use and is zero.

## See also

[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)

[CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam)
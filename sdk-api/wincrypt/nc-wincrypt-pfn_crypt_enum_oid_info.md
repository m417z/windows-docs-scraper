# PFN_CRYPT_ENUM_OID_INFO callback function

## Description

The **CRYPT_ENUM_OID_INFO** callback function is used with the [CryptEnumOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidinfo) function.

## Parameters

### `pInfo` [in]

A pointer to the OID information.

### `pvArg` [in]

A pointer to arguments passed through to the callback function.

## Return value

Returns **TRUE** to continue the enumeration and **FALSE** to stop the enumeration.
If **FALSE** is returned, the [CryptEnumOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidinfo) enumeration is stopped.

## See also

[CryptEnumOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidinfo)
# CRYPT_OID_FUNC_ENTRY structure

## Description

The **CRYPT_OID_FUNC_ENTRY** structure contains an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a pointer to its related function. It is used with
[CryptInstallOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalloidfunctionaddress).

## Members

### `pszOID`

If the high-order word of the OID is nonzero, **pszOID** is a pointer to either an OID string, such as "2.5.29.1" or an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string, such as "file". If the high-order word of the OID is zero, the low-order word specifies the numeric identifier to be used as the object identifier.

### `pvFuncAddr`

The starting address of the function that the OID identifies.

## See also

[CryptInstallOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalloidfunctionaddress)
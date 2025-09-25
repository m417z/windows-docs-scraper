# BCRYPT_KEY_BLOB structure

## Description

The **BCRYPT_KEY_BLOB** structure is the base structure for all CNG key BLOBs. All CNG key BLOBs are based on this structure. For example, the [BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob) structure is based on this structure.

## Members

### `Magic`

Specifies the type of key this BLOB represents. The possible values for this member depend on the type of BLOB this structure represents.

## See also

[BCRYPT_ECCKEY_BLOB](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_ecckey_blob)

[BCRYPT_RSAKEY_BLOB](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_rsakey_blob)
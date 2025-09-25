# BCRYPT_OID structure

## Description

The **BCRYPT_OID** structure contains information about a [DER](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly)-encoded [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). CNG uses hash OIDs in functions that sign or verify data in [PKCS #1](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) format.

## Members

### `cbOID`

The size, in bytes, of the **pbOID** buffer.

### `pbOID`

The address of a buffer that contains the OID.

## See also

[BCRYPT_HASH_OID_LIST](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers)

[BCRYPT_OID_LIST](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oid_list)
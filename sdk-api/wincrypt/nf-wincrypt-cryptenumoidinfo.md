# CryptEnumOIDInfo function

## Description

The **CryptEnumOIDInfo** function enumerates predefined and registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID)
[CRYPT_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_oid_info) structures. This function enumerates either all of the predefined and registered structures or only structures identified by a selected OID group. For each OID information structure enumerated, an application provided callback function, *pfnEnumOIDInfo*, is called.

## Parameters

### `dwGroupId` [in]

Indicates which OID groups to be matched. Setting *dwGroupId* to zero matches all groups. If *dwGroupId* is greater than zero, only the OID entries in the specified group are enumerated.

The currently defined OID group IDs are:

* CRYPT_HASH_ALG_OID_GROUP_ID
* CRYPT_ENCRYPT_ALG_OID_GROUP_ID
* CRYPT_PUBKEY_ALG_OID_GROUP_ID
* CRYPT_SIGN_ALG_OID_GROUP_ID
* CRYPT_RDN_ATTR_OID_GROUP_ID
* CRYPT_EXT_OR_ATTR_OID_GROUP_ID
* CRYPT_ENHKEY_USAGE_OID_GROUP_ID
* CRYPT_POLICY_OID_GROUP_ID
* CRYPT_TEMPLATE_OID_GROUP_ID
* CRYPT_KDF_OID_GROUP_ID **Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** The CRYPT_KDF_OID_GROUP_ID value is not supported.
* CRYPT_LAST_OID_GROUP_ID
* CRYPT_FIRST_ALG_OID_GROUP_ID
* CRYPT_LAST_ALG_OID_GROUP_ID

### `dwFlags` [in]

This parameter is reserved for future use. It must be zero.

### `pvArg` [in]

A pointer to arguments to be passed through to the callback function.

### `pfnEnumOIDInfo` [in]

A pointer to the callback function that is executed for each OID information entry enumerated. For information about the callback parameters, see [CRYPT_ENUM_OID_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_enum_oid_info).

## Return value

If the callback function completes the enumeration, this function returns **TRUE**.

If the callback function has stopped the enumeration, this function returns **FALSE**.

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
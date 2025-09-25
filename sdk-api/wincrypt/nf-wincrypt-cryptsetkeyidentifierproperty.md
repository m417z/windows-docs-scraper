# CryptSetKeyIdentifierProperty function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptSetKeyIdentifierProperty** function sets the property of a specified key identifier. This function can set the property on the computer identified in *pwszComputerName*.

## Parameters

### `pKeyIdentifier` [in]

A pointer to a
[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) containing the key identifier.

### `dwPropId` [in]

Identifies the property to be set. The value of *dwPropId* determines the type and content of the *pvData* parameter. Any certificate property ID can be used. CERT_KEY_PROV_INFO_PROP_ID is the property of most interest.

### `dwFlags` [in]

The following flags can be set. They can be combined with a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CRYPT_KEYID_MACHINE_FLAG** | Sets the property of the LocalMachine (if *pwszComputerName* is **NULL**) or remote computer (if *pwszComputerName* is not **NULL**). For more information, see *pwszComputerName*. |
| **CRYPT_KEYID_DELETE_FLAG** | The key identifier and all of its properties are deleted. |
| **CRYPT_KEYID_SET_NEW_FLAG** | Sets a new key identifier property. If the property already exists, the attempt fails, and **FALSE** is returned with the last error code set to CRYPT_E_EXISTS. |

### `pwszComputerName` [in]

A pointer to a **null**-terminated string that contains the name of a remote computer that has the key identifier where the properties are set. If CRYPT_KEYID_MACHINE_FLAG flag is set, searches the remote computer for a list of key identifiers. If the local computer is to be set and not a remote computer, set *pwszComputerName* to **NULL**.

### `pvReserved` [in]

Reserved for future use and must be **NULL**.

### `pvData` [out]

If *dwPropId* is CERT_KEY_PROV_INFO_PROP_ID, *pvData* points to a
[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure containing the property of the key identifier.

If *dwPropId* is not CERT_KEY_PROV_INFO_PROP_ID, *pvData* points to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure containing the property of the key identifier.

Setting *pvData* to **NULL** deletes the property.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** If CRYPT_KEYID_SET_NEW_FLAG is set and the property already exists, **FALSE** is returned with the last error code set to CRYPT_E_EXISTS.

## See also

[CryptEnumKeyIdentifierProperties](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumkeyidentifierproperties)

[CryptGetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyidentifierproperty)

[Key Identifier Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
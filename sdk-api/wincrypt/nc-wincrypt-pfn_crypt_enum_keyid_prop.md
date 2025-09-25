# PFN_CRYPT_ENUM_KEYID_PROP callback function

## Description

The **CRYPT_ENUM_KEYID_PROP** callback function is used with the [CryptEnumKeyIdentifierProperties](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumkeyidentifierproperties) function.

## Parameters

### `pKeyIdentifier` [in]

A pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the key identifier.

### `dwFlags` [in]

Reserved for future use and must be zero.

### `pvReserved` [in]

Reserved for future use. Must be **NULL**.

### `pvArg` [in, out]

A pointer to an argument that is passed back from the callback function.

### `cProp` [in]

Count of elements in the array of *rgdwPropId*

### `rgdwPropId` [in]

A pointer to an array of property identifiers. Each entry in the array will be one of the value types listed for in the table for *dwPropId* in the [CryptSetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyidentifierproperty) function.

#### - **rgpvData [in]

A pointer to an array that contains pointers to *pvData* elements corresponding the *rgdwPropId* array elements.

For CERT_KEY_PROV_INFO_PROP_ID the *rgpvData* element points to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure. For all other properties, the *rgpvData* element points to an array of bytes.

### `rgcbData` [in]

Array of **DWORD**s that specify the size, in bytes, of corresponding elements in the *rgpvData* array.

### `rgpvData` [in]

A pointer to an array that contains pointers to *pvData* elements corresponding the *rgdwPropId* array elements.

For CERT_KEY_PROV_INFO_PROP_ID the *rgpvData* element points to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure. For all other properties, the *rgpvData* element points to an array of bytes.

## Return value

Returns **TRUE** if the function succeeds, **FALSE** if it fails.

## See also

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)

[CryptEnumKeyIdentifierProperties](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumkeyidentifierproperties)

[CryptSetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyidentifierproperty)
# CryptEnumKeyIdentifierProperties function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptEnumKeyIdentifierProperties** function enumerates key identifiers and their properties. This function is not called in a loop. Rather, it loops internally until the last key identifier property is enumerated or the callback function returns **FALSE**. If *dwPropId* is zero or if the properties of the key identifier match the *dwPropId*, the callback function is called.

## Parameters

### `pKeyIdentifier` [in, optional]

A pointer to a
[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the key identifier.

If *pKeyIdentifier* is **NULL**, the function enumerates all key identifiers.

If *pKeyIdentifier* is not **NULL**, the callback function *pfnEnum* is only called for the specified key identifier.

### `dwPropId` [in]

Indicates the property identifier to be listed.

If *dwPropId* is set to zero, this function calls the callback function with all the properties.

If *dwPropId* is not zero and *pKeyIdentifier* is **NULL**, the callback function is called only for those key identifiers that have the specified property (sets the *cProp* parameter of *pfnEnum* to one). All key identifiers that do not have the property are skipped.

Any certificate property identifier can be used.

### `dwFlags` [in]

By default, the list of key identifiers for the CurrentUser is searched. If CRYPT_KEYID_MACHINE_FLAG is set, the list of key identifiers of the LocalMachine (if *pwszComputerName* is **NULL**) or of a remote computer (if *pwszComputerName* is not **NULL**) is searched. For more information, see *pwszComputerName*.

### `pwszComputerName` [in, optional]

A pointer to the name of a remote computer to be searched. If CRYPT_KEYID_MACHINE_FLAG is set in *dwFlags*, the remote computer is searched for a list of key identifiers. If the local computer is to be searched and not a remote computer, *pwszComputerName* is set to **NULL**.

### `pvReserved` [in]

Reserved for future use and must be **NULL**.

### `pvArg` [in, optional]

A pointer to data to be passed to the callback function. The type is a void that allows the application to declare, define, and initialize a structure or argument to hold any information.

### `pfnEnum` [in]

A pointer to an application-defined callback function that is executed for each key identifier entry that matches the input parameters. For details about the callback functions parameters, see [CRYPT_ENUM_KEYID_PROP](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_enum_keyid_prop).

## Return value

The **CryptEnumKeyIdentifierProperties** function repeatedly calls the [CRYPT_ENUM_KEYID_PROP](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_enum_keyid_prop) callback function until the last key identifier is enumerated or the callback function returns **FALSE**.

If the main function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

To continue enumeration, the function returns **TRUE**.

To stop enumeration, the function returns **FALSE** and sets the last error code.

## Remarks

A key identifier can have the same properties as a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

#### Examples

For an example that uses this function, see
[Example C Program: Working with Key Identifiers](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-working-with-key-identifiers).

## See also

[Base Cryptography Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CryptGetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyidentifierproperty)

[CryptSetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyidentifierproperty)
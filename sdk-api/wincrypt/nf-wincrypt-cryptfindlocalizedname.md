# CryptFindLocalizedName function

## Description

The **CryptFindLocalizedName** function finds the localized name for the specified name, such as the localize name of the "Root" system store. This function can be used before displaying any UI that included a name that might have a localized form.

## Parameters

### `pwszCryptName` [in]

A pointer to a specified name. An internal table is searched to compare a predefined localized name to the specified name. The search matches the localized name by using a case insensitive string comparison.

**Note** Localized names for the predefined system stores ("Root", "My") and predefined physical stores (".Default", ".LocalMachine") are preinstalled as resource strings in Crypt32.dll.

## Return value

If the specified name is found, a pointer to the localized name is returned. The returned pointer must not be freed.

If the specified name is not found, **NULL** is returned.

## Remarks

[CryptSetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetoidfunctionvalue) can be called as follows to register additional localized strings.

*dwEncodingType* = CRYPT_LOCALIZED_NAME_ENCODING_TYPE

*pszFuncName* = CRYPT_OID_FIND_LOCALIZED_NAME_FUNC

*pszOID* = CRYPT_LOCALIZED_NAME_OID

*pwszValueName* = Name to be localized, for example, L"ApplicationStore"

*dwValueType* = REG_SZ

*pbValueData* = pointer to the Unicode localized string

*cbValueData* = (wcslen(Unicode localized string) + 1) * sizeof(WCHAR)

[CryptSetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetoidfunctionvalue) can be called as follows to unregister the localized strings.

*pbValueData* = **NULL**

*cbValueData* = 0.

The registered names are searched before the preinstalled names.

|  |  |
| --- | --- |
| CRYPT_LOCALIZED_NAME_ ENCODING_TYPE | 0 |
| CRYPT_LOCALIZED_NAME_ OID | "LocalizedNames" |
| CRYPT_OID_FIND_LOCALIZED_ NAME_FUNC | "CryptDLLFindLocalizedName" |

#### Examples

For an example that uses this function, see
[Example C Program: Setting and Getting Certificate Store Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-setting-and-getting-certificate-store-properties).

## See also

[CryptSetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetoidfunctionvalue)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
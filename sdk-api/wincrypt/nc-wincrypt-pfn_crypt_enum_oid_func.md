# PFN_CRYPT_ENUM_OID_FUNC callback function

## Description

The **CRYPT_ENUM_OID_FUNCTION** callback function is used with the [CryptEnumOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidfunction) function.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to match. Setting this parameter to CRYPT_MATCH_ANY_ENCODING_TYPE matches any encoding type.

**Note** If CRYPT_MATCH_ANY_ENCODING_TYPE is not specified, either a certificate or message encoding type is required.

If the low-order word containing the certificate encoding type is nonzero, it is used. Otherwise, the high-order word containing the message encoding type is used. If both are specified, the certificate encoding type in the low-order word is used. Currently defined encoding types are:

* CRYPT_ASN_ENCODING
* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING
* CRYPT_MATCH_ANY_ENCODING_TYPE

### `pszFuncName`

### `pszOID` [in]

A pointer to either an OID string, such as "2.5.29.1",
an ASCII string, such as "file", or a numeric string,
such as #2000.

### `cValue` [in]

Count of elements in the array of value types.

### `rgdwValueType[]`

### `rgpwszValueName[]`

### `rgpbValueData[]`

### `rgcbValueData[]`

### `pvArg` [in]

A pointer to arguments passed through to the callback function.

#### - pszFunctionName [in]

Name of the OID function.

#### - rgcbValueData [in]

Array that specifies the size, in bytes, of corresponding elements of the *rgpbValueData* array.

#### - rgdwValueType [in]

Array of value types. Each entry in the array will be one of the value types
listed for [CryptGetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionvalue) under *pdwValueType*.

#### - rgpbValueData [in]

Array containing the values corresponding to the names in the *rgpwszValueName* array.

#### - rgpwszValueName [in]

Array of null-terminated strings containing the names of the values.

## Return value

Returns **TRUE** if the function succeeds, **FALSE** if it fails.

## See also

[CryptEnumOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumoidfunction)

[CryptGetOIDFunctionValue](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionvalue)
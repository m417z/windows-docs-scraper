# CryptEnumOIDFunction function

## Description

The **CryptEnumOIDFunction** function enumerates the registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) functions. OID functions that are enumerated can be screened to include those identified by their encoding type, function name, OID, or any combination of encoding type, function name, and OID. For each OID function that matches the selection criteria, an application-provided callback function, **pfnEnumOIDFunc**, is called.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to match. Setting this parameter to CRYPT_MATCH_ANY_ENCODING_TYPE matches any encoding type. Note that if CRYPT_MATCH_ANY_ENCODING_TYPE is not specified, either a certificate or [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is required. If the low-order word that contains the certificate encoding type is nonzero, it is used; otherwise, the high-order word that contains the message encoding type is used. If both are specified, the certificate encoding type in the low-order word is used.

Currently defined encoding types are:

* CRYPT_ASN_ENCODING
* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING
* CRYPT_MATCH_ANY_ENCODING_TYPE

### `pszFuncName` [in]

Name of a function for which a case insensitive match search is performed. Setting this parameter to **NULL** results in a match being found for any function name.

### `pszOID` [in]

If the high-order word of *pszOID* is nonzero, *pszOID* specifies the object identifier for which a case insensitive match search is performed. If the high-order word of *pszOID* is zero, *pszOID* is used to match a numeric object identifier. Setting this parameter to **NULL** matches any object identifier. Setting this parameter to CRYPT_DEFAULT_OID restricts the enumeration to only the default functions.

### `dwFlags` [in]

Reserved for future use and must be zero.

### `pvArg` [in]

A pointer to arguments to be passed through to the [CRYPT_ENUM_OID_FUNCTION](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_enum_oid_func) callback function.

### `pfnEnumOIDFunc` [in]

A pointer to the callback function that is executed for each OID function that matches the input parameters. For details, see [CRYPT_ENUM_OID_FUNCTION](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_enum_oid_func).

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
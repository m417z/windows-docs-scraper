# CryptUnregisterOIDFunction function

## Description

The **CryptUnregisterOIDFunction** function removes the registration of a DLL that contains the function to be called for the specified encoding type, function name, and OID.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

For functions that do not use an encoding type, set this parameter to zero.

### `pszFuncName` [in]

Name of the function being unregistered.

### `pszOID` [in]

A pointer to the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that corresponds to the name of the function being unregistered. If the high order word of the OID is nonzero, *pszOID* is a pointer to either an OID string such as "2.5.29.1" or an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string such as "file." If the high order word of the OID is zero, the low order word specifies the integer identifier to be used as the object identifier.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
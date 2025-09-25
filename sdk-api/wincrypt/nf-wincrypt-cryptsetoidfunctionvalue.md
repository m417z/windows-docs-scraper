# CryptSetOIDFunctionValue function

## Description

The **CryptSetOIDFunctionValue** function sets a value for the specified encoding type, function name, OID, and value name.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pszFuncName` [in]

Name of the function for which the encoding type, OID, and value name is being updated.

### `pszOID` [in]

If the high-order word of the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) is nonzero, *pszOID* is a pointer to either an OID string such as "2.5.29.1" or an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string such as "file". If the high-order word of the OID is zero, the low-order word specifies the integer identifier to be used as the object identifier.

### `pwszValueName` [in]

A pointer to a Unicode string containing the name of the value to set. If a value with this name is not already present, the function creates it.

### `dwValueType` [in]

Specifies the type of information to be stored as the value's data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **REG_DWORD** | A 32-bit number. |
| **REG_EXPAND_SZ** | A null-terminated Unicode string that contains unexpanded references to environment variables (for example, "%PATH%"). |
| **REG_MULTI_SZ** | An array of null-terminated Unicode strings, terminated by two **NULL** characters. |
| **REG_SZ** | A null-terminated Unicode string. |

### `pbValueData` [in]

Points to a buffer containing the data to be stored for the specified value name.

### `cbValueData` [in]

Specifies the size, in bytes, of the information pointed to by the *pbValueData* parameter. If the data is of type REG_SZ, REG_EXPAND_SZ, or REG_MULTI_SZ, the size must include the terminating **NULL** wide character.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
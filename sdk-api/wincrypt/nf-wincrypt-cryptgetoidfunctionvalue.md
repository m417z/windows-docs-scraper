# CryptGetOIDFunctionValue function

## Description

The **CryptGetOIDFunctionValue** function queries a value associated with an OID. The query is made for a specific named value associated with an OID, function name, and encoding type. The function can return the type of queried value, the value, itself, or both.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pszFuncName` [in]

A pointer to the null-terminated string that contains the name of the OID function set.

### `pszOID` [in]

If the high-order word of the OID is nonzero, *pszOID* is a pointer to either a null-terminated OID string such as "2.5.29.1" or a null-terminated [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string such as "file." If the high-order word of the OID is zero, the low-order word specifies the numeric identifier to be used as the object identifier.

### `pwszValueName` [in]

A pointer to a null-terminated Unicode string that contains the name of the value to be queried.

### `pdwValueType` [out]

A pointer to a variable to receive the value's type. The type returned through this parameter will be one of the following.

| Value | Meaning |
| --- | --- |
| **REG_DWORD** | A 32-bit number. |
| **REG_EXPAND_SZ** | A Unicode string that contains unexpanded references to environment variables such as "%PATH%". Applications should ensure that the string has a terminating null character before using it. For details about when the string does not have a terminating null character, see [RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa). |
| **REG_MULTI_SZ** | An array of null-terminated Unicode strings. Applications should ensure that the array is properly terminated by two null characters before using it. For details about when the array is not terminated by two null characters, see [RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa). |
| **REG_SZ** | A Unicode string. Applications should ensure that the string has a terminating null character before using it. For details about when the string does not have a terminating null character, see [RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa). |

The *pdwValueType* parameter can be **NULL** if a returned type is not required.

### `pbValueData` [out]

A pointer to a buffer to receive the value associated with the *pwszValueName* parameter. The buffer must be big enough to contain the terminating **NULL** character. This parameter can be **NULL** if returned data is not required.

This parameter can also be **NULL** to find the size of the buffer for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbValueData` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the buffer pointed to by the *pbValueData*.

In most cases the value returned in **pcbValueData* includes the size of the terminating **NULL** character in the string. For information about situations where the **NULL** character is not included, see the Remarks section of [RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa).

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function has the following error code.

| Value | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbValueData* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, into the variable pointed to by *pcbValueData*. |

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
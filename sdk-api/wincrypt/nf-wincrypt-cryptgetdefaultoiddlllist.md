# CryptGetDefaultOIDDllList function

## Description

The **CryptGetDefaultOIDDllList** function acquires the list of the names of DLL files that contain registered default [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) functions for a specified function set and encoding type.

## Parameters

### `hFuncSet` [in]

Function set handle previously obtained by a call to
[CryptInitOIDFunctionSet](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinitoidfunctionset).

### `dwEncodingType` [in]

Specifies the encoding type to be matched. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. To match both current encoding types, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

**Note** Either a certificate or [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is required. X509_ASN_ENCODING is the default. If that type is indicated, it is used; otherwise, if the PKCS7_ASN_ENCODING type is indicated, it is used.

### `pwszDllList` [out]

A pointer to a buffer to receive the list of zero or more null-terminated file names. The returned list is terminated with a terminating **NULL** character. For example, a list of two names could be:

L"*first*.dll\0" L"*second*.dll\0" L"\0"

To retrieve the number of wide characters the buffer must hold, this parameter can be **NULL**. For more information, see [Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcchDllList` [in, out]

A pointer to a **DWORD** that specifies the size, in wide characters, of the returned list pointed to by the *pwszDllList* parameter. When the function returns, the variable pointed to by the *pcchDllList* parameter contains the number of wide characters stored in the buffer.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function has the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pwszDllList* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in wide characters, in the variable pointed to by *pcchDllList*. |

## See also

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
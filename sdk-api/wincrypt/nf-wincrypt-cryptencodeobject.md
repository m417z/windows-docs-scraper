# CryptEncodeObject function

## Description

The **CryptEncodeObject** function encodes a structure of the type indicated by the value of the *lpszStructType* parameter. The use of
[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) is recommended as an API that performs the same function with significant performance improvements.

## Parameters

### `dwCertEncodingType` [in]

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

**Note** Either a certificate or [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) is required. X509_ASN_ENCODING is the default. If that type is indicated, it is used. Otherwise, if the PKCS7_ASN_ENCODING type is indicated, it is used.

### `lpszStructType` [in]

A pointer to an OID defining the structure type. If the high-order word of the *lpszStructType* parameter is zero, the low-order word specifies the integer identifier for the type of the specified structure. Otherwise, this parameter is a long pointer to a null-terminated string.

For more information about object identifier strings, their predefined constants and corresponding structures, see
[Constants for CryptEncodeObject and CryptDecodeObject](https://learn.microsoft.com/windows/desktop/SecCrypto/constants-for-cryptencodeobject-and-cryptdecodeobject).

### `pvStructInfo` [in]

A pointer to the structure to be encoded. The structure must be of a type specified by *lpszStructType*.

### `pbEncoded` [out]

A pointer to a buffer to receive the encoded structure. When the buffer that is specified is not large enough to receive the decoded structure, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbEncoded*.

This parameter can be **NULL** to retrieve the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbEncoded` [in, out]

A pointer to a **DWORD** variable that contains the size, in bytes, of the buffer pointed to by the *pbEncoded* parameter. When the function returns, the **DWORD** value contains the number of allocated encoded bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes are listed in the following table.

| Return code | Description |
| --- | --- |
| **CRYPT_E_BAD_ENCODE** | An error was encountered while encoding. |
| **ERROR_FILE_NOT_FOUND** | An encoding function could not be found for the specified *dwCertEncodingType* and *lpszStructType*. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbEncoded* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbEncoded*. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

When encoding a cryptographic object using the preferred [CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) function, the terminating **NULL** character is included. When decoding, using the preferred [CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex) function, the terminating **NULL** character is not retained.

#### Examples

For an example that uses this function, see
[Example C Program: Making a Certificate Request](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-making-a-certificate-request) and
[Example C Program: ASN.1 Encoding and Decoding](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-asn1-encoding-and-decoding).

## See also

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex)

[Object Encoding and Decoding Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
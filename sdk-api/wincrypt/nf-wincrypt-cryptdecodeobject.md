# CryptDecodeObject function

## Description

The **CryptDecodeObject** function decodes a structure of the type indicated by the *lpszStructType* parameter. The use of
[CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex) is recommended as an API that performs the same function with significant performance improvements.

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

### `pbEncoded` [in]

A pointer to the encoded structure to be decoded.

### `cbEncoded` [in]

Number of bytes pointed to by *pbEncoded*.

### `dwFlags` [in]

The following flags are defined. They can be combined with a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CRYPT_DECODE_NOCOPY_FLAG** | This flag can be set to indicate that "no copy" optimization is enabled. This optimization, where applicable, updates the *pvStructInfo* parameter to point to content residing within *pbEncoded* instead of making a copy of the content and appending it to *pvStructInfo*. For applicable cases, less memory needs to be allocated by the calling application and execution is faster because a copy is not being made. Note that the trade-off when performing a "no copy" decoding is that *pbEncoded* cannot be freed until *pvStructInfo* is freed. |
| **CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG** | This flag is applicable when decoding X509_UNICODE_NAME, X509_UNICODE_NAME_VALUE, or X509_UNICODE_ANY_STRING. By default, CERT_RDN_T61_STRING encoded values are initially decoded as UTF8. If the UTF8 decoding fails, then the value is decoded as eight-bit characters. If this flag is set, it skips the initial attempt to decode the value as UTF8 and decodes the value as eight-bit characters. |
| **CRYPT_DECODE_TO_BE_SIGNED_FLAG** | By default, the contents of the buffer pointed to by *pbEncoded* included the signed content and the signature. If this flag is set, the buffer includes only the "to be signed" content. This flag is applicable to X509_CERT_TO_BE_SIGNED, X509_CERT_CRL_TO_BE_SIGNED, X509_CRT_REQUEST_TO_BE_SIGNED, and X509_KEYGEN_REQUEST_TO_BE_SIGNED objects. |
| **CRYPT_DECODE_SHARE_OID_STRING_FLAG** | When this flag is set, the OID strings are allocated in Crypt32.dll and shared instead of being copied into the returned data structure. This flag can be set if Crypt32.dll is not unloaded before the caller is unloaded. |
| **CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG** | By default, the signature bytes are reversed. If this flag is set, this byte reversal is inhibited. |

### `pvStructInfo` [out]

A pointer to a buffer to receive the decoded structure. When the buffer that is specified is not large enough to receive the decoded structure, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbStructInfo*.

This parameter can be **NULL** to retrieve the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbStructInfo` [in, out]

A pointer to a **DWORD** value specifying the size, in bytes, of the buffer pointed to by the *pvStructInfo* parameter. When the function returns, this **DWORD** value contains the size of the decoded data copied to *pvStructInfo*. The size contained in the variable pointed to by *pcbStructInfo* can indicate a size larger than the decoded structure, as the decoded structure can include pointers to other structures. This size is the sum of the size needed by the decoded structure and other structures pointed to.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes are listed in the following table.

| Return code | Description |
| --- | --- |
| **CRYPT_E_BAD_ENCODE** | An error was encountered while decoding. |
| **ERROR_FILE_NOT_FOUND** | A decoding function could not be found for the specified *dwCertEncodingType* and *lpszStructType* |
| **ERROR_MORE_DATA** | If the buffer specified by the *pvStructInfo* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbStructInfo*. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

When encoding a cryptographic object using the preferred [CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) function, the terminating **NULL** character is included. When decoding, using the preferred [CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex) function, the terminating **NULL** character is not retained.

#### Examples

For an example that uses this function, see
[Example C Program: ASN.1 Encoding and Decoding](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-asn1-encoding-and-decoding).

## See also

[CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[Object Encoding and Decoding Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
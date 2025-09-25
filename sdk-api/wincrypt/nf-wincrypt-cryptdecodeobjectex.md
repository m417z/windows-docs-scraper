# CryptDecodeObjectEx function

## Description

The **CryptDecodeObjectEx** function decodes a structure of the type indicated by the *lpszStructType* parameter. **CryptDecodeObjectEx** offers a significant performance improvement over
[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) by supporting memory allocation with the CRYPT_DECODE_ALLOC_FLAG value.

## Parameters

### `dwCertEncodingType` [in]

The type of encoding used. It is always acceptable to specify both the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

**Note** Either a certificate or message encoding type is required. X509_ASN_ENCODING is the default. If that type is indicated, it is used. Otherwise, if the PKCS7_ASN_ENCODING type is indicated, it is used.

### `lpszStructType` [in]

A pointer to an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that defines the structure type. If the high-order word of the *lpszStructType* parameter is zero, the low-order word specifies the integer identifier for the type of the specified structure. Otherwise, this parameter is a long pointer to a null-terminated string.

For more information about object identifier strings, their predefined constants, and corresponding structures, see
[Constants for CryptEncodeObject and CryptDecodeObject](https://learn.microsoft.com/windows/desktop/SecCrypto/constants-for-cryptencodeobject-and-cryptdecodeobject).

### `pbEncoded` [in]

A pointer to the data to be decoded. The structure must be of the type specified by *lpszStructType*.

### `cbEncoded` [in]

The number of bytes pointed to by *pbEncoded*. This is the number of bytes to be decoded.

### `dwFlags` [in]

This parameter can be one or more of the following flags. The flags can be combined by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CRYPT_DECODE_ALLOC_FLAG** | The called decoding function allocates memory for the decoded structure. A pointer to the allocated structure is returned in *pvStructInfo*.<br><br>If *pDecodePara* or the **pfnAlloc** member of *pDecodePara* is **NULL**, then [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) is called for the allocation and [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) must be called to free the memory.<br><br>If *pDecodePara* and the **pfnAlloc** member of *pDecodePara* are not **NULL**, then the function pointed to by **pfnAlloc** is called for the allocation and the function pointed to by the **pfnFree** member of *pDecodePara* must be called to free the memory. |
| **CRYPT_DECODE_ENABLE_PUNYCODE_FLAG**<br><br>33554432 (0x2000000) | This flag is applicable for enabling Punycode decoding of Unicode string values. For more information, see Remarks.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **CRYPT_DECODE_NOCOPY_FLAG** | This flag can be set to enable a "no copy" optimization. This optimization updates the *pvStructInfo* members to point to content that resides within *pbEncoded* instead of making a copy of the content and appending it to *pvStructInfo*. The calling application needs to allocate less memory and execution is faster because a copy is not made. Note that when performing "no copy" decoding, *pbEncoded* cannot be freed until *pvStructInfo* is freed. |
| **CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG** | This flag is applicable when decoding X509_UNICODE_NAME, X509_UNICODE_NAME_VALUE, or X509_UNICODE_ANY_STRING. By default, CERT_RDN_T61_STRING encoded values are initially decoded as UTF8. If the UTF8 decoding fails, then the value is decoded as eight-bit characters. If this flag is set, it skips the initial attempt to decode the value as UTF8 and decodes the value as eight-bit characters. |
| **CRYPT_DECODE_TO_BE_SIGNED_FLAG** | By default, the contents of the buffer pointed to by *pbEncoded* included the signed content and the signature. If this flag is set, the buffer includes only the "to be signed" content. This flag is applicable to X509_CERT_TO_BE_SIGNED, X509_CERT_CRL_TO_BE_SIGNED, X509_CRT_REQUEST_TO_BE_SIGNED, and X509_KEYGEN_REQUEST_TO_BE_SIGNED objects. |
| **CRYPT_DECODE_SHARE_OID_STRING_FLAG** | When this flag is set, the OID strings are allocated in Crypt32.dll and shared instead of being copied into the returned data structure. This flag can be set if Crypt32.dll is not unloaded before the caller is unloaded. |
| **CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG** | By default, the signature bytes are reversed. If this flag is set, this byte reversal is inhibited. |

### `pDecodePara` [in]

A pointer to a [CRYPT_DECODE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_decode_para) structure that contains decoding paragraph information. If *pDecodePara* is set to **NULL**, then [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) and [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) are used to allocate and free memory. If *pDecodePara* points to a **CRYPT_DECODE_PARA** structure, that structure passes in callback functions to allocate and free memory. These callback functions override the default memory allocation of **LocalAlloc** and **LocalFree**.

### `pvStructInfo` [out]

If the *dwFlags* CRYPT_ENCODE_ALLOC_FLAG is set, *pvStructInfo* is not a pointer to a buffer but is the address of a pointer to the buffer. Because memory is allocated inside the function and the pointer is stored at **pvStructInfo*, *pvStructInfo* must never be **NULL**.

If CRYPT_ENCODE_ALLOC_FLAG is not set, *pvStructInfo* is a pointer to a buffer that receives the decoded structure. When the buffer that is specified is not large enough to receive the decoded structure, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbStructInfo*.

This parameter can be **NULL** to retrieve the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbStructInfo` [in, out]

A pointer to a **DWORD** variable that contains the size, in bytes, of the buffer pointed to by the *pvStructInfo* parameter. When the function returns, the **DWORD** value contains the number of bytes stored in the buffer. The size contained in the variable pointed to by *pcbStructInfo* can indicate a size larger than the decoded structure because the decoded structure can include pointers to auxiliary data. This size is the sum of the size needed by the decoded structure and the auxiliary data.

When CRYPT_DECODE_ALLOC_FLAG is set, the initial value of **pcbStructInfo* is not used by the function, and on return, **pcbStructInfo* contains the number of bytes allocated for *pvStructInfo*.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table shows some possible error codes.

| Return code | Description |
| --- | --- |
| **CRYPT_E_BAD_ENCODE** | An error was encountered while decoding. |
| **ERROR_FILE_NOT_FOUND** | A decoding function could not be found for the specified *dwCertEncodingType* and *lpszStructType*. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pvStructInfo* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pcbStructInfo*. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

When encoding a cryptographic object using the preferred [CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) function, the terminating **NULL** character is included. When decoding, using the preferred **CryptDecodeObjectEx** function, the terminating **NULL** character is not retained.

Each constant in the list below has an associated structure type that is pointed to by the *pvStructInfo* parameter. The structure pointed to, directly or indirectly, has a reference to a [CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structure.

* X509_ALTERNATE_NAME
* szOID_AUTHORITY_INFO_ACCESS
* X509_AUTHORITY_INFO_ACCESS
* X509_AUTHORITY_KEY_ID2
* szOID_AUTHORITY_KEY_IDENTIFIER2
* szOID_CRL_DIST_POINTS
* X509_CRL_DIST_POINTS
* szOID_CROSS_CERT_DIST_POINTS
* X509_CROSS_CERT_DIST_POINTS
* szOID_ISSUER_ALT_NAME
* szOID_ISSUER_ALT_NAME2
* szOID_ISSUING_DIST_POINT
* X509_ISSUING_DIST_POINT
* X509_NAME_CONSTRAINTS
* szOID_NAME_CONSTRAINTS
* szOID_NEXT_UPDATE_LOCATION
* OCSP_REQUEST
* zOID_SUBJECT_ALT_NAME
* szOID_SUBJECT_ALT_NAME2

The **CRYPT_DECODE_ENABLE_PUNYCODE_FLAG** flag, in conjunction with the value of the **dwAltNameChoice** member of the [CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structure, determines the manner in which strings are encoded.

| **dwAltNameChoice** | Effect |
| --- | --- |
| **CERT_ALT_NAME_DNS_NAME** | If the host name contains a Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string, it is converted to the Unicode equivalent. |
| **CERT_ALT_NAME_RFC822_NAME** | If the host name portion of the email address contains a Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string, it is converted to its Unicode equivalent. |
| **CERT_ALT_NAME_URL** | The URI is decoded. If the server host name of the URI contains a Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string, the host name string is decoded to the Unicode equivalent. |

Each constant in the list below has an associated structure type that is pointed to by the *pvStructInfo* parameter. The structure pointed to, directly or indirectly, has a reference to a [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structure.

* szOID_LOGOTYPE_EXT
* X509_LOGOTYPE_EXT
* szOID_BIOMETRIC_EXT
* X509_BIOMETRIC_EXT

When decoding the [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structure value, the URI is decoded. If the host name contains a Punycode encoded host name, it is converted to the Unicode equivalent.

Each **X509_UNICODE_NAME** constant in the list below has an associated structure type that is pointed to by the *pvStructInfo* parameter.

* X509_UNICODE_NAME

If the *pszObjId* member of the [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) structure is set to **szOID_RSA_emailAddr** and the email address in the **Value** member contains Punycode encoded string, it is converted to the Unicode equivalent.

#### Examples

For an example that uses this function, see [Example C Program: ASN.1 Encoding and Decoding](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-asn1-encoding-and-decoding).

## See also

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex)

[Object Encoding and Decoding Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
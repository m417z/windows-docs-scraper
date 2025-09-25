# CryptEncodeObjectEx function

## Description

The **CryptEncodeObjectEx** function encodes a structure of the type indicated by the value of the *lpszStructType* parameter. This function offers a significant performance improvement over
[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) by supporting memory allocation with the **CRYPT_ENCODE_ALLOC_FLAG** value.

## Parameters

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) to use to encode the object. This parameter can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PKCS_7_ASN_ENCODING**<br><br>65536 (0x10000) | Specifies PKCS 7 message encoding. |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `lpszStructType` [in]

A pointer to an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that defines the structure type. If the high-order word of the *lpszStructType* parameter is zero, the low-order word specifies an integer identifier for the type of the specified structure. Otherwise, this parameter is a pointer to a null-terminated string that contains the string representation of the OID.

For more information about object identifier strings, their predefined constants and corresponding structures, see
[Constants for CryptEncodeObject and CryptDecodeObject](https://learn.microsoft.com/windows/desktop/SecCrypto/constants-for-cryptencodeobject-and-cryptdecodeobject).

### `pvStructInfo` [in]

A pointer to the structure to be encoded. The structure must be of the type specified by *lpszStructType*.

### `dwFlags` [in]

Specifies options for the encoding. This parameter can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_ENCODE_ALLOC_FLAG**<br><br>32768 (0x8000) | The called encoding function allocates memory for the encoded bytes. A pointer to the allocated bytes is returned in *pvEncoded*. |
| **CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG**<br><br>131072 (0x20000) | This flag is applicable for enabling Punycode encoding of Unicode string values. For more information, see Remarks.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG**<br><br>1073741824 (0x40000000) | This flag is applicable when encoding X509_UNICODE_NAME, X509_UNICODE_NAME_VALUE, or X509_UNICODE_ANY_STRING. If this flag is set, the characters are not checked to determine whether they are valid for the specified value type. |
| **CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG**<br><br>2147483648 (0x80000000) | This flag is applicable when encoding X509_UNICODE_NAME. If this flag is set and all the Unicode characters are <= 0xFF, the CERT_RDN_T61_STRING is selected instead of the CERT_RDN_UNICODE_STRING. |
| **CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG**<br><br>536870912 (0x20000000) | This flag is applicable when encoding an X509_UNICODE_NAME. When set, CERT_RDN_UTF8_STRING is selected instead of CERT_RDN_UNICODE_STRING. |
| **CRYPT_UNICODE_NAME_ENCODE_FORCE_UTF8_UNICODE_FLAG**<br><br>268435456 (0x10000000) | This flag is applicable when encoding an X509_UNICODE_NAME. When set, CERT_RDN_UTF8_STRING is selected instead of CERT_RDN_PRINTABLE_STRING for directory string types. Also, this flag enables CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG. |

### `pEncodePara` [in]

A pointer to a
[CRYPT_ENCODE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encode_para) structure that contains encoding information. This parameter can be **NULL**.

If either *pEncodePara* or the **pfnAlloc** member of *pEncodePara* is **NULL**, then [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) is used for the allocation and [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) must be called to free the memory.

If both *pEncodePara* and the **pfnAlloc** member of *pEncodePara* are not **NULL**, then the function pointed to by the **pfnAlloc** member of the [CRYPT_ENCODE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encode_para) structure pointed to by *pEncodePara* is called for the allocation. The function pointed to by the **pfnFree** member of *pEncodePara* must be called to free the memory.

### `pvEncoded` [out]

A pointer to a buffer to receive the encoded structure. The size of this buffer is specified in the *pcbEncoded* parameter. When the buffer that is specified is not large enough to receive the decoded structure, the function sets the **ERROR_MORE_DATA** code and stores the required buffer size, in bytes, in the variable pointed to by *pcbEncoded*.

This parameter can be **NULL** to retrieve the size of the buffer for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

If *dwFlags* contains the **CRYPT_ENCODE_ALLOC_FLAG** flag, *pvEncoded* is not a pointer to a buffer but is the address of a pointer to the buffer. Because memory is allocated inside the function and the pointer is stored in *pvEncoded*, *pvEncoded* cannot be **NULL**.

### `pcbEncoded` [in, out]

A pointer to a **DWORD** variable that contains the size, in bytes, of the buffer pointed to by the *pvEncoded* parameter. When the function returns, the variable pointed to by the *pcbEncoded* parameter contains the number of allocated, encoded bytes stored in the buffer.

When *dwFlags* contains the **CRYPT_ENCODE_ALLOC_FLAG** flag, *pcbEncoded* is the address of a pointer to the **DWORD** value that is updated.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table shows some possible error codes that can be returned from **GetLastError** when **CryptEncodeObjectEx** fails.

| Return code | Description |
| --- | --- |
| **CRYPT_E_BAD_ENCODE** | An error was encountered while encoding. |
| **ERROR_FILE_NOT_FOUND** | An encoding function could not be found for the specified *dwCertEncodingType* and *lpszStructType*. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pvEncoded* parameter is not large enough to hold the returned data, the function sets the **ERROR_MORE_DATA** code and stores the required buffer size, in bytes, in the variable pointed to by *pcbEncoded*. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

When encoding a cryptographic object using the preferred **CryptEncodeObjectEx** function, the terminating **NULL** character is included. When decoding, using the preferred [CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex) function, the terminating **NULL** character is not retained.

**CryptEncodeObjectEx** first looks for an installable extended encoding function. If no extended encoding function is found, the old, nonextended, installable function is located.

 When direct [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) encoding of the object is not possible, you can specify Punycode encoding by setting the *dwFlag* parameter to the **CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG** value. Setting the **CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG** flag has different effects based on the structure type being encoded as specified by the value of the *lpszStructType* parameter.

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
* szOID_NAME_CONSTRAINTS
* X509_NAME_CONSTRAINTS
* szOID_NEXT_UPDATE_LOCATION
* OCSP_REQUEST
* zOID_SUBJECT_ALT_NAME
* szOID_SUBJECT_ALT_NAME2

The **CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG** flag, in conjunction with the value of the **dwAltNameChoice** member of the [CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structure, determines the manner in which strings are encoded.

| **dwAltNameChoice** | Effect |
| --- | --- |
| **CERT_ALT_NAME_DNS_NAME** | If the host name contains Unicode characters outside of the ASCII character set, the host name is first encoded in Punycode and then encoded as an [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string. |
| **CERT_ALT_NAME_RFC822_NAME** | If the host name portion of the email address contains Unicode characters outside of the ASCII character set, the host name portion of the email address is encoded in Punycode. The resultant email address is then encoded as an [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string. |
| **CERT_ALT_NAME_URL** | If the server host name of the URI contains Unicode characters outside of the ASCII character set, then the host name portion of URI is encoded in Punycode. Then the resultant URI is escaped, and the URL is then encoded as an [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string. |

Each constant in the list below has an associated structure type that is pointed to by the *pvStructInfo* parameter. The structure pointed to, directly or indirectly, has a reference to a [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structure.

* szOID_BIOMETRIC_EXT
* X509_BIOMETRIC_EXT
* szOID_LOGOTYPE_EXT
* X509_LOGOTYPE_EXT

When encoding the [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structure value, if the server host name of the URI contains Unicode characters outside of the ASCII character set, and the **CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG** is set, the host name portion of URI is encoded in Punycode. Then the resultant URI is escaped, and the URL is then encoded as an [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string.

Each **X509_UNICODE_NAME** constant in the list below has an associated structure type that is pointed to by the *pvStructInfo* parameter.

* X509_UNICODE_NAME

If the *pszObjId* member of the [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) structure is set to **szOID_RSA_emailAddr** and the email address in the **Value** member contains Unicode characters outside of the ASCII character set, the host name portion of the email address is encoded in Punycode. Then the resultant email address is then encoded as an [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string.

In all cases, the Punycode encoding of the host name is performed on a label-by-label basis.

#### Examples

The following example shows initializing and encoding an X509_NAME structure using **CryptEncodeObjectEx**. For an example that includes the complete context for this example, see [Example C Program: ASN.1 Encoding and Decoding](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-asn1-encoding-and-decoding).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>
#pragma comment(lib, "crypt32.lib")

#define MY_TYPE (X509_ASN_ENCODING)

void main()
{

//#define moved

//--------------------------------------------------------------------
//   Declare and initialize local variables.

char *Cert_Sub_Name ="Test User Name";

//--------------------------------------------------------------------
// Initialize a single RDN structure.

CERT_RDN_ATTR rgNameAttr =
{
   "2.5.4.3",                      // The OID
   CERT_RDN_PRINTABLE_STRING,      // Type of string
   (DWORD)strlen(Cert_Sub_Name)+1, // String length including
                                   //  the terminating null character
   (BYTE *)Cert_Sub_Name           // Pointer to the string
};
//--------------------------------------------------------------------
// Declare and initialize a structure to include
// the array of RDN structures.

CERT_RDN rgRDN[] =
{
   1,               // The number of elements in the array
   &rgNameAttr      // Pointer to the array
};

//--------------------------------------------------------------------
//  Declare and initialize a CERT_NAME_INFO
//  structure that includes a CERT_RND.

CERT_NAME_INFO CertName =
{
    1,          // The number of elements in the CERT_RND's array
    rgRDN
};

//--------------------------------------------------------------------
//  Declare additional variables.

DWORD cbEncoded;              // Variable to hold the
                              //  length of the encoded string
BYTE *pbEncoded;              // Variable to hold a pointer to the
                              //  encoded buffer
//--------------------------------------------------------------------
// Call CrypteEncodeObjectEx to get
// length to allocate for pbEncoded.

if( CryptEncodeObjectEx(
     MY_TYPE,        // The encoding/decoding type
     X509_NAME,
     &CertName,
     0,
     NULL,
     NULL,
     &cbEncoded))    // Fill in the length needed for
                     // the encoded buffer.
{
     printf("The number of bytes needed is %d \n",cbEncoded);
}
else
{
     printf("The first call to the function failed.\n");
     exit(1);
}

if( pbEncoded = (BYTE*)malloc(cbEncoded))
{
     printf("Memory for pvEncoded has been allocated.\n");
}
else
{
    printf("Memory allocation failed.\n");
    exit(1);
}

if(CryptEncodeObjectEx(
     MY_TYPE,
     X509_NAME,
     &CertName,
     0,
     NULL,
     pbEncoded,
     &cbEncoded))
{
     printf("The structure has been encoded.\n");
}
else
{
     printf("Encoding failed.");
     exit(1);
}
// Free allocated memory when done.
// ...
if(pbEncoded)
{
    free(pbEncoded);
}

```

## See also

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[Object Encoding and Decoding Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
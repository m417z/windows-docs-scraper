# CryptGetProvParam function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptGetProvParam** function retrieves parameters that govern the operations of a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Parameters

### `hProv` [in]

 A handle of the CSP target of the query. This handle must have been created by using
the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function.

### `dwParam` [in]

The nature of the query. The following queries are defined.

| Value | Meaning |
| --- | --- |
| **PP_ADMIN_PIN**<br><br>31 (0x1F) | Returns the administrator personal identification number (PIN) in the *pbData* parameter as a **LPSTR**. |
| **PP_APPLI_CERT**<br><br>18 (0x12) | This constant is not used. |
| **PP_CHANGE_PASSWORD**<br><br>7 (0x7) | This constant is not used. |
| **PP_CERTCHAIN**<br><br>9 (0x9) | Returns the certificate chain associated with the *hProv* handle. The returned certificate chain is **X509_ASN_ENCODING** encoded. |
| **PP_CONTAINER**<br><br>6 (0x6) | The name of the current [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) as a **null**-terminated **CHAR** string. This string is exactly the same as the one passed in the *pszContainer* parameter of the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function to specify the key container to use. The *pszContainer* parameter can be read to determine the name of the default key container. |
| **PP_CRYPT_COUNT_KEY_USE**<br><br>41 (0x29) | Not implemented by Microsoft CSPs. This behavior may be implemented by other CSPs.<br><br>**Windows XP:** This parameter is not supported. |
| **PP_ENUMALGS**<br><br>1 (0x1) | A [PROV_ENUMALGS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-prov_enumalgs) structure that contains information about one algorithm supported by the CSP being queried.<br><br>The first time this value is read, the *dwFlags* parameter must contain the **CRYPT_FIRST** flag. Doing so causes this function to retrieve the first element in the enumeration. The subsequent elements can then be retrieved by setting the **CRYPT_NEXT** flag in the *dwFlags* parameter. When this function fails with the **ERROR_NO_MORE_ITEMS** error code, the end of the enumeration has been reached.<br><br>This function is not thread safe, and all of the available algorithms might not be enumerated if this function is used in a multithreaded context. |
| **PP_ENUMALGS_EX**<br><br>22 (0x16) | A [PROV_ENUMALGS_EX](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-prov_enumalgs_ex) structure that contains information about one algorithm supported by the CSP being queried. The structure returned contains more information about the algorithm than the structure returned for PP_ENUMALGS.<br><br>The first time this value is read, the *dwFlags* parameter must contain the **CRYPT_FIRST** flag. Doing so causes this function to retrieve the first element in the enumeration. The subsequent elements can then be retrieved by setting the **CRYPT_NEXT** flag in the *dwFlags* parameter. When this function fails with the **ERROR_NO_MORE_ITEMS** error code, the end of the enumeration has been reached.<br><br>This function is not thread safe and all of the available algorithms might not be enumerated if this function is used in a multithreaded context. |
| **PP_ENUMCONTAINERS**<br><br>2 (0x2) | The name of one of the key containers maintained by the CSP in the form of a **null**-terminated **CHAR** string. <br><br>The first time this value is read, the *dwFlags* parameter must contain the **CRYPT_FIRST** flag. Doing so causes this function to retrieve the first element in the enumeration. The subsequent elements can then be retrieved by setting the **CRYPT_NEXT** flag in the *dwFlags* parameter. When this function fails with the **ERROR_NO_MORE_ITEMS** error code, the end of the enumeration has been reached.<br><br>To enumerate key containers associated with a computer, first call [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) using the **CRYPT_MACHINE_KEYSET** flag, and then use the handle returned from **CryptAcquireContext** as the *hProv* parameter in the call to **CryptGetProvParam**.<br><br>This function is not thread safe and all of the available algorithms might not be enumerated if this function is used in a multithreaded context. |
| **PP_ENUMELECTROOTS**<br><br>26 (0x1A) | This constant is not used. |
| **PP_ENUMEX_SIGNING_PROT**<br><br>40 (0x28) | Indicates that the current CSP supports the **dwProtocols** member of the [PROV_ENUMALGS_EX](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-prov_enumalgs_ex) structure. If this function succeeds, the CSP supports the **dwProtocols** member of the **PROV_ENUMALGS_EX** structure. If this function fails with an **NTE_BAD_TYPE** error code, the CSP does not support the **dwProtocols** member. |
| **PP_ENUMMANDROOTS**<br><br>25 (0x19) | This constant is not used. |
| **PP_IMPTYPE**<br><br>3 (0x3) | A **DWORD** value that indicates how the CSP is implemented. For a table of possible values, see Remarks. |
| **PP_KEY_TYPE_SUBTYPE**<br><br>10 (0xA) | This query is not used. |
| **PP_KEYEXCHANGE_PIN**<br><br>32 (0x20) | Specifies that the key exchange PIN is contained in *pbData*. The PIN is represented as a **null**-terminated ASCII string. |
| **PP_KEYSET_SEC_DESCR**<br><br>8 (0x8) | Retrieves the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the key storage container. The *pbData* parameter is the address of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that receives the security descriptor for the key storage container. The security descriptor is returned in self-relative format. |
| **PP_KEYSET_TYPE**<br><br>27 (0x1B) | Determines whether the *hProv* parameter is a computer key set. The *pbData* parameter must be a **DWORD**; the **DWORD** will be set to the CRYPT_MACHINE_KEYSET flag if that flag was passed to the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function. |
| **PP_KEYSPEC**<br><br>39 (0x27) | Returns information about the key specifier values that the CSP supports. Key specifier values are joined in a logical **OR** and returned in the *pbData* parameter of the call as a **DWORD**. For example, the Microsoft Base Cryptographic Provider version 1.0 returns a **DWORD** value of AT_SIGNATURE \| AT_KEYEXCHANGE. |
| **PP_KEYSTORAGE**<br><br>17 (0x11) | Returns a **DWORD** value of CRYPT_SEC_DESCR. |
| **PP_KEYX_KEYSIZE_INC**<br><br>35 (0x23) | The number of bits for the increment length of AT_KEYEXCHANGE. This information is used with information returned in the PP_ENUMALGS_EX value. With the information returned when using PP_ENUMALGS_EX and PP_KEYX_KEYSIZE_INC, the valid key lengths for AT_KEYEXCHANGE can be determined. These key lengths can then be used with [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey). For example if a CSP enumerates [CALG_RSA_KEYX](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (AT_KEYEXCHANGE) with a minimum key length of 512 bits and a maximum of 1024 bits, and returns the increment length as 64 bits, then valid key lengths are 512, 576, 640,… 1024. |
| **PP_NAME**<br><br>4 (0x4) | The name of the CSP in the form of a **null**-terminated **CHAR** string. This string is identical to the one passed in the *pszProvider* parameter of the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function to specify that the current CSP be used. |
| **PP_PROVTYPE**<br><br>16 (0x10) | A **DWORD** value that indicates the provider type of the CSP. |
| **PP_ROOT_CERTSTORE**<br><br>46 (0x2E) | Obtains the root certificate store for the smart card. This certificate store contains all of the root certificates that are stored on the smart card.<br><br>The *pbData* parameter is the address of an **HCERTSTORE** variable that receives the handle of the certificate store. When this handle is no longer needed, the caller must close it by using the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.<br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |
| **PP_SESSION_KEYSIZE**<br><br>20 (0x14) | The size, in bits, of the session key. |
| **PP_SGC_INFO**<br><br>37 (0x25) | Used with [server gated cryptography](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **PP_SIG_KEYSIZE_INC**<br><br>34 (0x22) | The number of bits for the increment length of AT_SIGNATURE. This information is used with information returned in the PP_ENUMALGS_EX value. With the information returned when using PP_ENUMALGS_EX and PP_SIG_KEYSIZE_INC, the valid [key lengths](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) for AT_SIGNATURE can be determined. These key lengths can then be used with [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey).<br><br>For example, if a CSP enumerates [CALG_RSA_SIGN](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (AT_SIGNATURE) with a minimum [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) of 512 bits and a maximum of 1024 bits, and returns the increment length as 64 bits, then valid key lengths are 512, 576, 640,… 1024. |
| **PP_SIGNATURE_PIN**<br><br>33 (0x21) | Specifies that the key signature PIN is contained in *pbData*. The PIN is represented as a **null**-terminated ASCII string. |
| **PP_SMARTCARD_GUID**<br><br>45 (0x2D) | Obtains the identifier of the smart card. The *pbData* parameter is the address of a **GUID** structure that receives the identifier of the smart card.<br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |
| **PP_SMARTCARD_READER**<br><br>43 (0x2B) | Obtains the name of the smart card reader. The *pbData* parameter is the address of an ANSI character array that receives a **null**-terminated ANSI string that contains the name of the smart card reader. The size of this buffer, contained in the variable pointed to by the *pdwDataLen* parameter, must include the **NULL** terminator.<br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |
| **PP_SYM_KEYSIZE**<br><br>19 (0x13) | The size of the symmetric key. |
| **PP_UI_PROMPT**<br><br>21 (0x15) | This query is not used. |
| **PP_UNIQUE_CONTAINER**<br><br>36 (0x24) | The unique container name of the current key container in the form of a **null**-terminated **CHAR** string. For many CSPs, this name is the same name returned when the PP_CONTAINER value is used. The [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function must work with this container name. |
| **PP_USE_HARDWARE_RNG**<br><br>38 (0x26) | Indicates whether a hardware random number generator (RNG) is supported. When **PP_USE_HARDWARE_RNG** is specified, the function succeeds and returns **TRUE** if a hardware RNG is supported. The function fails and returns **FALSE** if a hardware RNG is not supported. If a RNG is supported, **PP_USE_HARDWARE_RNG** can be set in [CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam) to indicate that the CSP must exclusively use the hardware RNG for this provider context. When **PP_USE_HARDWARE_RNG** is used, the *pbData* parameter must be **NULL** and *dwFlags* must be zero.<br><br>None of the Microsoft CSPs currently support using a hardware RNG. |
| **PP_USER_CERTSTORE**<br><br>42 (0x2A) | Obtains the user certificate store for the smart card. This certificate store contains all of the user certificates that are stored on the smart card. The certificates in this store are encoded by using PKCS_7_ASN_ENCODING or X509_ASN_ENCODING encoding and should contain the **CERT_KEY_PROV_INFO_PROP_ID** property. <br><br>The *pbData* parameter is the address of an **HCERTSTORE** variable that receives the handle of an in-memory certificate store. When this handle is no longer needed, the caller must close it by using the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.<br><br>**Windows Server 2003 and Windows XP:** This parameter is not supported. |
| **PP_VERSION**<br><br>5 (0x5) | The version number of the CSP. The least significant byte contains the minor version number and the next most significant byte the major version number. Version 2.0 is represented as 0x00000200. To maintain backward compatibility with earlier versions of the [Microsoft Base Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider) and the [Microsoft Enhanced Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-enhanced-cryptographic-provider), the provider names retain the "v1.0" designation in later versions. |

### `pbData` [out]

A pointer to a buffer to receive the data. The form of this data varies depending on the value of *dwParam*. When *dwParam* is set to PP_USE_HARDWARE_RNG, *pbData* must be set to **NULL**.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pdwDataLen` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the buffer pointed to by the *pbData* parameter. When the function returns, the **DWORD** value contains the number of bytes stored or to be stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

If PP_ENUMALGS, or PP_ENUMALGS_EX is set, the *pdwDataLen* parameter works somewhat differently. If *pbData* is **NULL** or the value pointed to by *pdwDataLen* is too small, the value returned in this parameter is the size of the largest item in the enumeration list instead of the size of the item currently being read.

If PP_ENUMCONTAINERS is set, the first call to the function returns the size of the maximum key-container allowed by the current provider. This is in contrast to other possible behaviors, like returning the length of the longest existing container, or the length of the current container. Subsequent enumerating calls will not change the *dwLen* parameter. For each enumerated container, the caller can determine the length of the **null**-terminated string programmatically, if desired. If one of the enumeration values is read and the *pbData* parameter is **NULL**, the CRYPT_FIRST flag must be specified for the size information to be correctly retrieved.

### `dwFlags` [in]

If *dwParam* is **PP_KEYSET_SEC_DESCR**, the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) on the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) where the keys are stored is retrieved. For this case, *dwFlags* is used to pass in the **SECURITY_INFORMATION** bit flags that indicate the requested security information, as defined in the Platform SDK. **SECURITY_INFORMATION** bit flags can be combined with a bitwise-**OR** operation.

The following values are defined for use with **PP_KEYSET_SEC_DESCR**.

| Value | Meaning |
| --- | --- |
| **OWNER_SECURITY_INFORMATION** | Owner identifier of the object is being referenced. |
| **GROUP_SECURITY_INFORMATION** | Primary group identifier of the object is being referenced. |
| **DACL_SECURITY_INFORMATION** | Discretionary ACL of the object is being referenced. |
| **SACL_SECURITY_INFORMATION** | System ACL of the object is being referenced. |

The following values are defined for use with **PP_ENUMALGS**, **PP_ENUMALGS_EX**, and **PP_ENUMCONTAINERS**.

| Value | Meaning |
| --- | --- |
| **CRYPT_FIRST**<br><br>1 (0x1) | Retrieve the first element in the enumeration. This has the same effect as resetting the enumerator. |
| **CRYPT_NEXT**<br><br>2 (0x2) | Retrieve the next element in the enumeration. When there are no more elements to retrieve, this function will fail and set the last error to **ERROR_NO_MORE_ITEMS**. |
| **CRYPT_SGC_ENUM**<br><br>4 (0x4) | Retrieve [server-gated cryptography](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SGC) enabled certificates. SGC enabled certificates are no longer supported. |
| **CRYPT_SGC** | This flag is not used. |
| **CRYPT_FASTSGC** | This flag is not used. |

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by NTE are generated by the particular CSP being used. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbData* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by *pdwDataLen*. |
| **ERROR_NO_MORE_ITEMS** | The end of the enumeration list has been reached. No valid data has been placed in the *pbData* buffer. This error code is returned only when *dwParam* equals PP_ENUMALGS or PP_ENUMCONTAINERS. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter specifies a flag that is not valid. |
| **NTE_BAD_TYPE** | The *dwParam* parameter specifies an unknown value number. |
| **NTE_BAD_UID** | The CSP [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) specified by *hProv* is not valid. |

## Remarks

This function must not be used on a thread of a multithreaded program.

The following values are returned in *pbData* if *dwParam* is PP_IMPTYPE.

| Value | Meaning |
| --- | --- |
| CRYPT_IMPL_HARDWARE\ 0x01 | Implementation is in hardware. |
| CRYPT_IMPL_SOFTWARE\ 0x02 | Implementation is in software. |
| CRYPT_IMPL_MIXED\ 0x03 | Implementation involves both hardware and software. |
| CRYPT_IMPL_UNKNOWN\ 0x04 | Implementation type is unknown. |
| CRYPT_IMPL_REMOVABLE\ 0x08 | Implementation is in removable media. |

The *dwFlags* parameter is used to pass in the **SECURITY_INFORMATION** bit flags that indicate the requested security information. The pointer to the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is returned in the *pbData* parameter and the length of the security descriptor is returned in the *pdwDataLen* parameter. Key-container security is handled with
[SetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setfilesecuritya) and
[GetFileSecurity](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfilesecuritya).

The class of an algorithm enumerated with *dwParam* set to PP_ENUMALGS or PP_ENUMALGS_EX can be determined. This might be done to display a list of encryption algorithms supported and to disregard the rest. The **GET_ALG_CLASS(***x***)** macro takes an algorithm identifier as an argument and returns a code indicating the general class of that algorithm. Possible return values include:

* ALG_CLASS_DATA_ENCRYPT
* ALG_CLASS_HASH
* ALG_CLASS_KEY_EXCHANGE
* ALG_CLASS_SIGNATURE

The following table lists the algorithms supported by the Microsoft Base Cryptographic Provider along with the class of each algorithm.

| Name | Identifier | Class |
| --- | --- | --- |
| "MD2" | [CALG_MD2](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_HASH |
| "MD5" | [CALG_MD5](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_HASH |
| "SHA" | [CALG_SHA](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_HASH |
| "MAC" | [CALG_MAC](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_HASH |
| "RSA_SIGN" | [CALG_RSA_SIGN](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_SIGNATURE |
| "RSA_KEYX" | [CALG_RSA_KEYX](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_KEY_EXCHANGE |
| "RC2" | [CALG_RC2](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_DATA_ENCRYPT |
| "RC4" | [CALG_RC4](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) | ALG_CLASS_DATA_ENCRYPT |

Applications must not use an algorithm with an algorithm identifier that is not recognized. Using an unknown cryptographic algorithm can produce unpredictable results.

#### Examples

The following example shows finding the name of the CSP associated with a cryptographic service provider handle and the name of the key container associated with the handle. For the complete context for this example, see
[Example C Program: Using CryptAcquireContext](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-using-cryptacquirecontext).

For another example that uses this function, see [Example C Program: Enumerating CSP Providers and Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-enumerating-csp-providers-and-provider-types).

```cpp
//-----------------------------------------------------------------
//  Declare and initialize variables.

HCRYPTPROV hCryptProv;
BYTE       pbData[1000];       // 1000 will hold the longest
                               // key container name.
DWORD cbData;

//-------------------------------------------------------------------
// An HCRYPTPROV must be acquired before using code like that in
// "Example C Program Using CryptAcquireContext."

//-------------------------------------------------------------------
// Read the name of the default CSP.

cbData = 1000;
if(CryptGetProvParam(
    hCryptProv,
    PP_NAME,
    pbData,
    &cbData,
    0))
{
    printf("CryptGetProvParam succeeded.\n");
    printf("Provider name: %s\n", pbData);
}
else
{
    printf("Error reading CSP name. \n");
    exit(1);
}
//--------------------------------------------------------------------
// Read the name of the default key container.

cbData = 1000;
if(CryptGetProvParam(
    hCryptProv,
    PP_CONTAINER,
    pbData,
    &cbData,
    0))
{
    printf("CryptGetProvParam succeeded. \n");
    printf("Key Container name: %s\n", pbData);
}
else
{
    printf("Error reading key container name. \n");
    exit(1);
}
```

## See also

[Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors)

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)

[CryptDeriveKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptderivekey)

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam)

[CryptSetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetprovparam)

[Service Provider Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
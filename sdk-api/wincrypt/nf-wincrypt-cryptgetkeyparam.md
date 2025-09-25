# CryptGetKeyParam function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptGetKeyParam** function retrieves data that governs the operations of a key. If the
[Microsoft Cryptographic Service Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-cryptographic-service-providers) is used, the base symmetric keying material is not obtainable by this or any other function.

## Parameters

### `hKey` [in]

The handle of the key being queried.

### `dwParam` [in]

Specifies the type of query being made.

For all key types, this parameter can contain one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_ALGID** | Retrieve the key algorithm. The *pbData* parameter is a pointer to an [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) value that receives the identifier of the algorithm that was specified when the key was created.<br><br>When **AT_KEYEXCHANGE** or **AT_SIGNATURE** is specified for the *Algid* parameter of the [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) function, the algorithm identifiers that are used to generate the key depend on the provider used. For more information, see [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id). |
| **KP_BLOCKLEN** | If a session key is specified by the *hKey* parameter, retrieve the block length of the key cipher. The *pbData* parameter is a pointer to a **DWORD** value that receives the block length, in bits. For [stream ciphers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), this value is always zero.<br><br>If a [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) is specified by *hKey*, retrieve the encryption granularity of the key pair. The *pbData* parameter is a pointer to a **DWORD** value that receives the encryption granularity, in bits. For example, the [Microsoft Base Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider) generates 512-bit RSA key pairs, so a value of 512 is returned for these keys. If the [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) does not support [encryption](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly), the value retrieved is undefined. |
| **KP_CERTIFICATE** | *pbData* is the address of a buffer that receives the X.509 certificate that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER). The [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) must match the corresponding signature or exchange key. |
| **KP_GET_USE_COUNT** | This value is not used. |
| **KP_KEYLEN** | Retrieve the actual length of the key. The *pbData* parameter is a pointer to a **DWORD** value that receives the key length, in bits. **KP_KEYLEN** can be used to get the length of any key type. Microsoft [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs) return a key length of 64 bits for **CALG_DES**, 128 bits for **CALG_3DES_112**, and 192 bits for **CALG_3DES**. These lengths are different from the lengths returned when you are enumerating algorithms with the *dwParam* value of the [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function set to **PP_ENUMALGS**. The length returned by this call is the actual size of the key, including the parity bits included in the key.<br><br>Microsoft CSPs that support the **CALG_CYLINK_MEK** [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) return 64 bits for that algorithm. **CALG_CYLINK_MEK** is a 40-bit key but has parity and zeroed key bits to make the key length 64 bits. |
| **KP_SALT** | Retrieve the [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the key. The *pbData* parameter is a pointer to a **BYTE** array that receives the salt value in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) form. The size of the salt value varies depending on the CSP and algorithm being used. Salt values do not apply to [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **KP_PERMISSIONS** | Retrieve the key permissions. The *pbData* parameter is a pointer to a **DWORD** value that receives the permission flags for the key.<br><br>The following permission identifiers are currently defined. The key permissions can be zero or a combination of one or more of the following values.<br><br>CRYPT_ARCHIVE<br><br>Allow export during the lifetime of the handle of the key. This permission can be set only if it is already set in the internal permissions field of the key. Attempts to clear this permission are ignored.<br><br>CRYPT_DECRYPT<br><br>Allow decryption.<br><br>CRYPT_ENCRYPT<br><br>Allow encryption.<br><br>CRYPT_EXPORT<br><br>Allow the key to be exported.<br><br>CRYPT_EXPORT_KEY<br><br>Allow the key to be used for exporting keys.<br><br>CRYPT_IMPORT_KEY<br><br>Allow the key to be used for importing keys.<br><br>CRYPT_MAC<br><br>Allow [Message Authentication Codes](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MACs) to be used with key.<br><br>CRYPT_READ<br><br>Allow values to be read.<br><br>CRYPT_WRITE<br><br>Allow values to be set. |

If a [Digital Signature Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSS) key is specified by the *hKey* parameter, the *dwParam* value can also be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_P** | Retrieve the modulus prime number P of the DSS key. The *pbData* parameter is a pointer to a buffer that receives the value in little-endian form. The *pdwDataLen* parameter contains the size of the buffer, in bytes. |
| **KP_Q** | Retrieve the modulus prime number Q of the DSS key. The *pbData* parameter is a pointer to a buffer that receives the value in little-endian form. The *pdwDataLen* parameter contains the size of the buffer, in bytes. |
| **KP_G** | Retrieve the generator G of the DSS key. The *pbData* parameter is a pointer to a buffer that receives the value in little-endian form. The *pdwDataLen* parameter contains the size of the buffer, in bytes. |

If a [block cipher](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is specified by the *hKey* parameter, the *dwParam* value can also be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_EFFECTIVE_KEYLEN** | Retrieve the effective key length of an RC2 key. The *pbData* parameter is a pointer to a **DWORD** value that receives the effective key length. |
| **KP_IV** | Retrieve the initialization vector of the key. The *pbData* parameter is a pointer to a **BYTE** array that receives the initialization vector. The size of this array is the block size, in bytes. For example, if the block length is 64 bits, the initialization vector consists of 8 bytes. |
| **KP_PADDING** | Retrieve the padding mode. The *pbData* parameter is a pointer to a **DWORD** value that receives a numeric identifier that identifies the [padding](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) method used by the [cipher](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This can be one of the following values.<br><br>PKCS5_PADDING<br><br>Specifies the PKCS 5 (sec 6.2) padding method.<br><br>RANDOM_PADDING<br><br>The padding uses random numbers. This padding method is not supported by the Microsoft supplied CSPs.<br><br>ZERO_PADDING<br><br>The padding uses zeros. This padding method is not supported by the Microsoft supplied CSPs. |
| **KP_MODE** | Retrieve the [cipher mode](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The *pbData* parameter is a pointer to a **DWORD** value that receives a cipher mode identifier. For more information about cipher modes, see [Data Encryption and Decryption](https://learn.microsoft.com/windows/desktop/SecCrypto/data-encryption-and-decryption).<br><br>The following cipher mode identifiers are currently defined.<br><br>CRYPT_MODE_CBC<br><br>The cipher mode is [cipher block chaining](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).<br><br>CRYPT_MODE_CFB<br><br>The cipher mode is [cipher feedback](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CFB). Microsoft CSPs currently support only 8-bit feedback in cipher feedback mode.<br><br>CRYPT_MODE_ECB<br><br>The cipher mode is [electronic codebook](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly).<br><br>CRYPT_MODE_OFB<br><br>The cipher mode is [Output Feedback](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OFB). Microsoft CSPs currently do not support Output Feedback Mode.<br><br>CRYPT_MODE_CTS<br><br>The cipher mode is [ciphertext](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) stealing mode. |
| **KP_MODE_BITS** | Retrieve the number of bits to feed back. The *pbData* parameter is a pointer to a **DWORD** value that receives the number of bits that are processed per cycle when the OFB or CFB cipher modes are used. |

If a [Diffie-Hellman algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) or [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) key is specified by *hKey*, the *dwParam* value can also be set to the following value.

| Value | Meaning |
| --- | --- |
| **KP_VERIFY_PARAMS** | Verifies the parameters of a Diffie-Hellman algorithm or DSA key. The *pbData* parameter is not used, and the value pointed to by *pdwDataLen* receives zero.<br><br>This function returns a nonzero value if the key parameters are valid or zero otherwise. |
| **KP_KEYVAL** | This value is not used.<br><br>**Windows Vista, Windows Server 2003 and Windows XP:** Retrieve the secret agreement value from an imported [Diffie-Hellman algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) key of type **CALG_AGREEDKEY_ANY**. The *pbData* parameter is the address of a buffer that receives the secret agreement value, in little-endian format. This buffer must be the same length as the key. The *dwFlags* parameter must be set to 0xF42A19B6. This property can only be retrieved by a thread running under the local system account.This property is available for use in the operating systems listed above. It may be altered or unavailable in subsequent versions. |

If a certificate is specified by *hKey*, the *dwParam* value can also be set to the following value.

| Value | Meaning |
| --- | --- |
| **KP_CERTIFICATE** | A buffer that contains the DER-encoded X.509 certificate. The *pbData* parameter is not used, and the value pointed to by *pdwDataLen* receives zero.<br><br>This function returns a nonzero value if the key parameters are valid or zero otherwise. |

### `pbData` [out]

A pointer to a buffer that receives the data. The form of this data depends on the value of *dwParam*.

If the size of this buffer is not known, the required size can be retrieved at run time by passing **NULL** for this parameter and setting the value pointed to by *pdwDataLen* to zero. This function will place the required size of the buffer, in bytes, in the value pointed to by *pdwDataLen*. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pdwDataLen` [in, out]

A pointer to a **DWORD** value that, on entry, contains the size, in bytes, of the buffer pointed to by the *pbData* parameter. When the function returns, the **DWORD** value contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size may be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are sometimes specified large enough to ensure that the largest possible output data fits in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by "NTE" are generated by the particular CSP being used. Some possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbData* parameter is not large enough to hold the returned data, the function sets the **ERROR_MORE_DATA** code and stores the required buffer size, in bytes, in the variable pointed to by *pdwDataLen*. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter is nonzero. |
| **NTE_BAD_KEY or NTE_NO_KEY** | The key specified by the *hKey* parameter is not valid. |
| **NTE_BAD_TYPE** | The *dwParam* parameter specifies an unknown value number. |
| **NTE_BAD_UID** | The CSP [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was specified when the key was created cannot be found. |

## See also

[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CryptSetKeyParam function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptSetKeyParam** function customizes various aspects of a session key's operations. The values set by this function are not persisted to memory and can only be used with in a single session.

The
[Microsoft Base Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider) does not permit setting values for key exchange or signature keys; however, custom providers can define values that can be set for its keys.

## Parameters

### `hKey` [in]

A handle to the key for which values are to be set.

### `dwParam` [in]

The following tables contain predefined values that can be used.

For all key types, this parameter can contain one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_ALGID** | *pbData* points to an appropriate [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id). This is used when exchanging session keys with the Microsoft Base Digital Signature Standard (DSS), Diffie-Hellman Cryptographic Provider, or compatible CSPs. After a key is agreed upon with the [CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) function, the session key is enabled for use by setting its algorithm type. |
| **KP_CERTIFICATE** | *pbData* is the address of a buffer that contains the X.509 certificate that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER). The public key in the certificate must match the corresponding signature or exchange key. |
| **KP_PERMISSIONS** | *pbData* points to a **DWORD** value that specifies zero or more permission flags. For a description of these flags, see [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam). |
| **KP_SALT** | *pbData* points to a **BYTE** array that specifies a new [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to be made part of the session key. The size of the salt value varies depending on the CSP being used. Before setting this value, determine the size of the salt value by calling the [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam) function. Salt values are used to make the session keys more unique, which makes dictionary attacks more difficult. The salt value is zero by default for Microsoft Base Cryptographic Provider. |
| **KP_SALT_EX** | *pbData* points to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the salt. For more information, see [Specifying a Salt Value](https://learn.microsoft.com/windows/desktop/SecCrypto/specifying-a-salt-value). |

If a [Digital Signature Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSS) key is specified by the *hKey* parameter, the *dwParam* value can also be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_G** | *pbData* points to the generator G from the DSS [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). The data is in the form of a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure, where the **pbData** member is the value, and the **cbData** member is the length of the value. The value is expected with no header information and in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) form. |
| **KP_P** | *pbData* points to the prime modulus P of a DSS key BLOB. The data is in the form of a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. The **pbData** member is the value, and the **cbData** member is the length of the value. The value is expected with no header information and in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) form. |
| **KP_Q** | *pbData* points to the prime Q of a DSS key BLOB. The data is in the form of a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure where the **pbData** member is the value, and the **cbData** member is the length of the value. The value is expected with no header information and in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) form. |
| **KP_X** | After the P, Q, and G values have been set, a call that specifies the KP_X value for *dwParam* and **NULL** for the *pbData* parameter can be made to the **CryptSetKeyParam** function. This causes the X and Y values to be generated. |

If a [Diffie-Hellman algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) or [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) key is specified by *hKey*, the *dwParam* value can also be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_CMS_DH_KEY_INFO** | Sets the information for an imported [Diffie-Hellman](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) key. The *pbData* parameter is the address of a [CMS_DH_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cms_dh_key_info) structure that contains the key information to be set. |
| **KP_PUB_PARAMS** | Sets the public parameters (P, Q, G, and so on) of a DSS or Diffie-Hellman key. The key handle for this key must be in the PREGEN state, generated with the CRYPT_PREGEN flag. The *pbData* parameter must be a pointer to a [DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure where the data in this structure is a DHPUBKEY_VER3 or DSSPUBKEY_VER3 BLOB. The function copies the public parameters from this **CRYPT_INTEGER_BLOB** structure to the key handle. After this call is made, the KP_X parameter value should be used with **CryptSetKeyParam** to create the actual private key. The KP_PUB_PARAMS parameter is used as one call rather than multiple calls with the parameter values KP_P, KP_Q, and KP_G. |

If a [block cipher](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is specified by the *hKey* parameter, the *dwParam* value can also be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **KP_EFFECTIVE_KEYLEN** | This value type can only be used with RC2 keys and has been added because of the implementation of the **CryptSetKeyParam** function in the Microsoft Enhanced Cryptographic Provider prior to Windows 2000. In the previous implementation, the RC2 keys in the Enhanced Provider were 128 bits in strength, but the effective key length used to expand keys into the key table was only 40 bits. This reduced the strength of the algorithm to 40 bits. To maintain backward compatibility, the previous implementation will remain as is. However, the effective key length can be set to be greater than 40 bits by using KP_EFFECTIVE_KEYLEN in the **CryptSetKeyParam** call. The effective key length is passed in the *pbData* parameter as a pointer to a **DWORD** value with the effective key length value. The minimum effective key length on the Microsoft Base Cryptographic Provider is one, and the maximum is 40. In the Microsoft Enhanced Cryptographic Provider, the minimum is one and the maximum is 1,024. The key length must be set prior to encrypting or decrypting with the key. |
| **KP_HIGHEST_VERSION** | Sets the highest [Transport Layer Security](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) version allowed. This property only applies to SSL and TLS keys. The *pbData* parameter is the address of a **DWORD** variable that contains the highest TLS version number supported. |
| **KP_IV** | *pbData* points to a **BYTE** array that specifies the initialization vector. This array must contain *BlockLength*/8 elements. For example, if the block length is 64 bits, the initialization vector consists of 8 bytes. <br><br>The initialization vector is set to zero by default for the Microsoft Base Cryptographic Provider. |
| **KP_KEYVAL** | Set the key value for a [Data Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DES) key. The *pbData* parameter is the address of a buffer that contains the key. This buffer must be the same length as the key. This property only applies to DES keys. |
| **KP_PADDING** | Set the padding mode. The *pbData* parameter is a pointer to a **DWORD** value that receives a numeric identifier that identifies the [padding](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) method used by the [cipher](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This can be one of the following values.<br><br>PKCS5_PADDING<br><br>Specifies the PKCS 5 (sec 6.2) padding method.<br><br>RANDOM_PADDING<br><br>The padding uses a random number. This padding method is not supported by the Microsoft supplied CSPs.<br><br>ZERO_PADDING<br><br>The padding uses zeros. This padding method is not supported by the Microsoft supplied CSPs. |
| **KP_MODE** | *pbData* points to a **DWORD** value that specifies the [cipher mode](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be used. For a list of the defined cipher modes, see [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam). The cipher mode is set to CRYPT_MODE_CBC by default for the Microsoft Base Cryptographic Provider. |
| **KP_MODE_BITS** | *pbData* points to a **DWORD** value that indicates the number of bits processed per cycle when the [Output Feedback](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OFB) or [Cipher Feedback](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CFB) cipher mode is used. The number of bits processed per cycle is set to 8 by default for the Microsoft Base Cryptographic Provider. |

If an [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) key is specified in the *hKey* parameter, the *dwParam* parameter value can be the following value.

| Value | Meaning |
| --- | --- |
| **KP_OAEP_PARAMS** | Set the Optimal Asymmetric Encryption Padding (OAEP) (PKCS #1 version 2) parameters for the key. The *pbData* parameter is the address of a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the OAEP label. This property only applies to RSA keys. |

Note that the following values are not used:

* KP_ADMIN_PIN
* KP_CMS_KEY_INFO
* KP_INFO
* KP_KEYEXCHANGE_PIN
* KP_PRECOMP_MD5
* KP_PRECOMP_SHA
* KP_PREHASH
* KP_PUB_EX_LEN
* KP_PUB_EX_VAL
* KP_RA
* KP_RB
* KP_ROUNDS
* KP_RP
* KP_SIGNATURE_PIN
* KP_Y

### `pbData` [in]

A pointer to a buffer initialized with the value to be set before calling **CryptSetKeyParam**. The form of this data varies depending on the value of *dwParam*.

### `dwFlags` [in]

Used only when *dwParam* is KP_ALGID. The *dwFlags* parameter is used to pass in flag values for the enabled key. The *dwFlags* parameter can hold values such as the key size and the other flag values allowed when generating the same type of key with [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey). For information about allowable flag values, see
**CryptGenKey**.

## Return value

If the function succeeds, the return value is nonzero (TRUE).

If the function fails, the return value is zero (FALSE). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by "NTE" are generated by the particular CSP being used. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_BUSY** | The CSP context is currently being used by another [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter is nonzero, or the *pbData* buffer contains a value that is not valid. |
| **NTE_BAD_TYPE** | The *dwParam* parameter specifies an unknown parameter. |
| **NTE_BAD_UID** | The CSP context that was specified when the *hKey* key was created cannot be found. |
| **NTE_FAIL** | The function failed in some unexpected way. |
| **NTE_FIXEDPARAMETER** | Some CSPs have hard-coded P, Q, and G values. If this is the case, then using KP_P, KP_Q, and KP_G for the value of *dwParam* causes this error. |

## Remarks

If the KP_Q, KP_P, or KP_X parameters are set on a PREGEN Diffie-Hellman or DSS key, the key lengths must be compatible with the [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) set using the upper 16 bits of the *dwFlags* parameter when the key was created using [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey). If no key length was set in **CryptGenKey**, the default key length was used. This will create an error if a nondefault key length is used to set P, Q, or X.

#### Examples

For an example that uses this function, see [Example C Program: Duplicating a Session Key](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-duplicating-a-session-key).
For more code that uses this function, see
[Example C Program: Setting and Getting Session Key Parameters](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-setting-and-getting-session-key-parameters) .

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam)

[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
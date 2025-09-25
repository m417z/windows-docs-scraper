# CryptGenKey function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptGenKey** function generates a random cryptographic [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) or a [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). A handle to the key or key pair is returned in *phKey*. This handle can then be used as needed with any CryptoAPI function that requires a key handle.

The calling application must specify the algorithm when calling this function. Because this algorithm type is kept bundled with the key, the application does not need to specify the algorithm later when the actual cryptographic operations are performed.

## Parameters

### `hProv` [in]

A handle to a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) created by a call to
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `Algid` [in]

An
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) value that identifies the algorithm for which the key is to be generated. Values for this parameter vary depending on the CSP used.

For **ALG_ID** values to use with the Microsoft Base Cryptographic Provider, see
[Base Provider Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/base-provider-algorithms).

For **ALG_ID** values to use with the Microsoft Strong Cryptographic Provider or the Microsoft Enhanced Cryptographic Provider, see
[Enhanced Provider Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/enhanced-provider-algorithms).

For a Diffie-Hellman CSP, use one of the following values.

| Value | Meaning |
| --- | --- |
| **CALG_DH_EPHEM** | Specifies an "Ephemeral" Diffie-Hellman key. |
| **CALG_DH_SF** | Specifies a "Store and Forward" Diffie-Hellman key. |

In addition to generating session keys for [symmetric algorithms](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), this function can also generate [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). Each CryptoAPI client generally possesses two public/private key pairs. To generate one of these key pairs, set the *Algid* parameter to one of the following values.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Key exchange |
| **AT_SIGNATURE** | Digital signature |

**Note** When key specifications AT_KEYEXCHANGE and AT_SIGNATURE are specified, the algorithm identifiers that are used to generate the key depend on the provider used. As a result, for these key specifications, the values returned from
[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam) (when the KP_ALGID parameter is specified) depend on the provider used. To determine which algorithm identifier is used by the different providers for the key specs AT_KEYEXCHANGE and AT_SIGNATURE, see
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id).

### `dwFlags` [in]

Specifies the type of key generated. The sizes of a session key, RSA signature key, and RSA key [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) can be set when the key is generated. The key size, representing the length of the key modulus in bits, is set with the upper 16 bits of this parameter. Thus, if a 2,048-bit RSA signature key is to be generated, the value 0x08000000 is combined with any other *dwFlags* predefined value with a bitwise-**OR** operation. The upper 16 bits of 0x08000000 is 0x0800, or decimal 2,048. The **RSA1024BIT_KEY** value can be used to specify a 1024-bit RSA key.

Due to changing export control restrictions, the default CSP and default [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) may change between operating system versions. It is important that both the encryption and decryption use the same CSP and that the key length be explicitly set using the *dwFlags* parameter to ensure interoperability on different operating system platforms.

In particular, the default RSA Full Cryptographic Service Provider is the Microsoft RSA Strong Cryptographic Provider. The default DSS Signature Diffie-Hellman Cryptographic Service Provider is the Microsoft Enhanced DSS Diffie-Hellman Cryptographic Provider. Each of these CSPs has a default 128-bit symmetric key length for RC2 and RC4 and a 1,024-bit default key length for public key algorithms.

If the upper 16 bits is zero, the default key size is generated. If a key larger than the maximum or smaller than the minimum is specified, the call fails with the ERROR_INVALID_PARAMETER code.

The following table lists minimum, default, and maximum signature and exchange key lengths beginning with Windows XP.

| Key type and provider | Minimum length | Default length | Maximum length |
| --- | --- | --- | --- |
| RSA Base Provider<br><br>Signature and ExchangeKeys | 384 | 512 | 16,384 |
| RSA Strong and Enhanced Providers<br><br>Signature and Exchange Keys | 384 | 1,024 | 16,384 |
| DSS Base Providers<br><br>Signature Keys | 512 | 1,024 | 1,024 |
| DSS Base Providers<br><br>Exchange Keys | Not applicable | Not applicable | Not applicable |
| DSS/DH Base Providers<br><br>Signature Keys | 512 | 1,024 | 1,024 |
| DSS/DH Base Providers<br><br>Exchange Keys | 512 | 512 | 1,024 |
| DSS/DH Enhanced Providers<br><br>Signature Keys | 512 | 1,024 | 1,024 |
| DSS/DH Enhanced Providers<br><br>Exchange Keys | 512 | 1,024 | 4,096 |

For session key lengths, see [CryptDeriveKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptderivekey).

For more information about keys generated using Microsoft providers, see
[Microsoft Cryptographic Service Providers](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-cryptographic-service-providers).

The lower 16-bits of this parameter can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_ARCHIVABLE** | If this flag is set, the key can be exported until its handle is closed by a call to [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey). This allows newly generated keys to be exported upon creation for archiving or key recovery. After the handle is closed, the key is no longer exportable. |
| **CRYPT_CREATE_IV** | This flag is not used. |
| **CRYPT_CREATE_SALT** | If this flag is set, then the key is assigned a random [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) automatically. You can retrieve this salt value by using the [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam) function with the *dwParam* parameter set to KP_SALT.<br><br>If this flag is not set, then the key is given a salt value of zero.<br><br>When keys with nonzero salt values are exported (through [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey)), then the [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) must also be obtained and kept with the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). |
| **CRYPT_DATA_KEY** | This flag is not used. |
| **CRYPT_EXPORTABLE** | If this flag is set, then the key can be transferred out of the CSP into a key BLOB by using the [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) function. Because session keys generally must be exportable, this flag should usually be set when they are created.<br><br>If this flag is not set, then the key is not exportable. For a session key, this means that the key is available only within the current session and only the application that created it will be able to use it. For a [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), this means that the private key cannot be transported or backed up.<br><br>This flag applies only to session key and [private key BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). It does not apply to public keys, which are always exportable. |
| **CRYPT_FORCE_KEY_PROTECTION_HIGH** | This flag specifies strong key protection. When this flag is set, the user is prompted to enter a password for the key when the key is created. The user will be prompted to enter the password whenever this key is used. <br><br>This flag is only used by the CSPs that are provided by Microsoft. Third party CSPs will define their own behavior for strong key protection.<br><br>Specifying this flag causes the same result as calling this function with the **CRYPT_USER_PROTECTED** flag when strong key protection is specified in the system registry.<br><br>If this flag is specified and the provider handle in the *hProv* parameter was created by using the **CRYPT_VERIFYCONTEXT** or **CRYPT_SILENT** flag, this function will set the last error to **NTE_SILENT_CONTEXT** and return zero.<br><br>**Windows Server 2003 and Windows XP:** This flag is not supported. |
| **CRYPT_KEK** | This flag is not used. |
| **CRYPT_INITIATOR** | This flag is not used. |
| **CRYPT_NO_SALT** | This flag specifies that a no [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) gets allocated for a forty-bit [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). For more information, see [Salt Value Functionality](https://learn.microsoft.com/windows/desktop/SecCrypto/salt-value-functionality). |
| **CRYPT_ONLINE** | This flag is not used. |
| **CRYPT_PREGEN** | This flag specifies an initial Diffie-Hellman or DSS key generation. This flag is useful only with Diffie-Hellman and DSS CSPs. When used, a default key length will be used unless a key length is specified in the upper 16 bits of the *dwFlags* parameter. If parameters that involve key lengths are set on a PREGEN Diffie-Hellman or DSS key using [CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam), the key lengths must be compatible with the key length set here. |
| **CRYPT_RECIPIENT** | This flag is not used. |
| **CRYPT_SF** | This flag is not used. |
| **CRYPT_SGCKEY** | This flag is not used. |
| **CRYPT_USER_PROTECTED** | If this flag is set, the user is notified through a dialog box or another method when certain actions are attempting to use this key. The precise behavior is specified by the CSP being used. If the provider context was opened with the CRYPT_SILENT flag set, using this flag causes a failure and the last error is set to NTE_SILENT_CONTEXT. |
| **CRYPT_VOLATILE** | This flag is not used. |

### `phKey` [out]

Address to which the function copies the handle of the newly generated key. When you have finished using the key, delete the handle to the key by calling the [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) function.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by "NTE" are generated by the particular CSP being used. Some possible error codes are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_ALGID** | The *Algid* parameter specifies an algorithm that this CSP does not support. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_BAD_UID** | The *hProv* parameter does not contain a valid context handle. |
| **NTE_FAIL** | The function failed in some unexpected way. |
| **NTE_SILENT_CONTEXT** | The provider could not perform the action because the context was acquired as silent. |

## Remarks

If keys are generated for [symmetric](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [block ciphers](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly), the key, by default, is set up in [cipher block chaining](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CBC) mode with an initialization vector of zero. This [cipher mode](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) provides a good default method for bulk encrypting data. To change these parameters, use the
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) function.

To choose an appropriate [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), the following methods are recommended:

* Enumerate the algorithms that the CSP supports and get maximum and minimum key lengths for each algorithm. To do this, call [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) with PP_ENUMALGS_EX.
* Use the minimum and maximum lengths to choose an appropriate key length. It is not always advisable to choose the maximum length because this can lead to performance issues.
* After the desired key length has been chosen, use the upper 16 bits of the *dwFlags* parameter to specify the key length.

#### Examples

The following example shows the creation of a random session key. For an example that includes the complete context for this example, see [Example C Program: Encrypting a File](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encrypting-a-file). For another example that uses this function, see [Example C Program: Decrypting a File](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-decrypting-a-file).

```cpp
//-------------------------------------------------------------------
//  Declare the handle to the key.
HCRYPTKEY hKey;
//-------------------------------------------------------------------
//  This example assumes that a cryptographic context
//  has been acquired, and that it is stored in hCryptProv.
//---------------------------------------------------------------
//  Create a random session key.

 if(CryptGenKey(
          hCryptProv,
          ENCRYPT_ALGORITHM,
          KEYLENGTH | CRYPT_EXPORTABLE,
          &hKey))
 {
         printf("A session key has been created.\n");
 }
 else
 {
          printf("Error during CryptGenKey.\n");
          exit(1);
 }
//-------------------------------------------------------------------
//  The key created can be exported into a key BLOB that can be
//  written to a file.
//  ...
//  When you have finished using the key, free the resource.
if (!CryptDestroyKey(hKey))
{
          printf("Error during CryptDestroyKey.\n");
          exit(1);
}
```

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey)

[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey)

[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam)

[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey)

[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Threading Issues with Cryptographic Service Providers](https://learn.microsoft.com/previous-versions/aa388149(v=vs.85))
# CryptDeriveKey function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptDeriveKey** function generates cryptographic [session keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) derived from a base data value. This function guarantees that when the same [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) and algorithms are used, the keys generated from the same base data are identical. The base data can be a password or any other user data.

This function is the same as
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey), except that the generated [session keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) are derived from base data instead of being random. **CryptDeriveKey** can only be used to generate session keys. It cannot generate [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

A handle to the session key is returned in the *phKey* parameter. This handle can be used with any CryptoAPI function that requires a key handle.

## Parameters

### `hProv` [in]

A [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle of a CSP created by a call to
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `Algid` [in]

An
[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) structure that identifies the [symmetric encryption](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) algorithm for which the key is to be generated. The algorithms available will most likely be different for each CSP. For more information about which algorithm identifier is used by the different providers for the key specs AT_KEYEXCHANGE and AT_SIGNATURE, see
**ALG_ID**.

For more information about [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) values to use with the Microsoft Base Cryptographic Provider, see
[Base Provider Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/base-provider-algorithms). For more information about **ALG_ID** values to use with the Microsoft Strong Cryptographic Provider or the Microsoft Enhanced Cryptographic Provider, see
[Enhanced Provider Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/enhanced-provider-algorithms).

### `hBaseData` [in]

A handle to a [hash object](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) that has been fed the exact base data.

To obtain this handle, an application must first create a hash object with
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash) and then add the base data to the hash object with
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata). This process is described in detail in
[Hashes and Digital Signatures](https://learn.microsoft.com/windows/desktop/SecCrypto/hashes-and-digital-signatures).

### `dwFlags` [in]

Specifies the type of key generated.

The sizes of a session key can be set when the key is generated. The key size, representing the length of the key modulus in bits, is set with the upper 16 bits of this parameter. Thus, if a 128-bit [RC4](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) session key is to be generated, the value 0x00800000 is combined with any other *dwFlags* predefined value with a bitwise-**OR** operation. Due to changing export control restrictions, the default CSP and default [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) may change between operating system releases. It is important that both the encryption and decryption use the same CSP and that the key length be explicitly set using the *dwFlags* parameter to ensure interoperability on different operating system platforms.

The lower 16 bits of this parameter can be zero or you can specify one or more of the following flags by using the bitwise-**OR** operator to combine them.

| Value | Meaning |
| --- | --- |
| **CRYPT_CREATE_SALT** | Typically, when a session key is made from a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) value, there are a number of leftover bits. For example, if the hash value is 128 bits and the session key is 40 bits, there will be 88 bits left over.<br><br>If this flag is set, then the key is assigned a [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) based on the unused hash value bits. You can retrieve this *salt value* by using the [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam) function with the *dwParam* parameter set to KP_SALT.<br><br>If this flag is not set, then the key is given a salt value of zero.<br><br>When keys with nonzero salt values are exported (by using [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey)), the salt value must also be obtained and kept with the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). |
| **CRYPT_EXPORTABLE** | If this flag is set, the session key can be transferred out of the CSP into a key BLOB through the [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) function. Because keys generally must be exportable, this flag should usually be set.<br><br>If this flag is not set, then the session key is not exportable. This means the key is available only within the current session and only the application that created it is able to use it.<br><br>This flag does not apply to [public/private key pairs](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). |
| **CRYPT_NO_SALT** | This flag specifies that a no [salt value](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) gets allocated for a 40-bit [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). For more information, see [Salt Value Functionality](https://learn.microsoft.com/windows/desktop/SecCrypto/salt-value-functionality). |
| **CRYPT_UPDATE_KEY** | Some CSPs use session keys that are derived from multiple hash values. When this is the case, **CryptDeriveKey** must be called multiple times.<br><br>If this flag is set, a new session key is not generated. Instead, the key specified by *phKey* is modified. The precise behavior of this flag is dependent on the type of key being generated and on the particular CSP being used.<br><br>Microsoft cryptographic service providers ignore this flag. |
| **CRYPT_SERVER**<br><br>1024 (0x400) | This flag is used only with [Schannel](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) providers. If this flag is set, the key to be generated is a server-write key; otherwise, it is a client-write key. |

### `phKey` [in, out]

A pointer to a [HCRYPTKEY](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptkey) variable to receive the address of the handle of the newly generated key. When you have finished using the key, release the handle by calling the [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) function.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by "NTE" are generated by the particular CSP being used. Some possible error codes are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_ALGID** | The *Algid* parameter specifies an algorithm that this CSP does not support. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_BAD_HASH** | The *hBaseData* parameter does not contain a valid handle to a [hash object](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly). |
| **NTE_BAD_HASH_STATE** | An attempt was made to add data to a hash object that is already marked "finished." |
| **NTE_BAD_UID** | The *hProv* parameter does not contain a valid context handle. |
| **NTE_FAIL** | The function failed in some unexpected way. |
| **NTE_SILENT_CONTEXT** | The provider could not perform the action because the context was acquired as silent. |

## Remarks

When keys are generated for [symmetric](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [block ciphers](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly), the key by default is set up in [cipher block chaining](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CBC) mode with an initialization vector of zero. This [cipher mode](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) provides a good default method for bulk-encrypting data. To change these parameters, use the
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) function.

The **CryptDeriveKey** function completes the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly). After **CryptDeriveKey** has been called, no more data can be added to the hash. Additional calls to
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) or
[CryptHashSessionKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashsessionkey) fail. After the application is done with the hash,
[CryptDestroyHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroyhash) must be called to destroy the hash object.

To choose an appropriate [key length](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly), the following methods are recommended.

* To enumerate the algorithms that the CSP supports and to get maximum and minimum key lengths for each algorithm, call [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) with PP_ENUMALGS_EX.
* Use the minimum and maximum lengths to choose an appropriate key length. It is not always advisable to choose the maximum length because this can lead to performance issues.
* After the desired key length has been chosen, use the upper 16 bits of the *dwFlags* parameter to specify the key length.

Let **n** be the required derived key length, in bytes. The derived key is the first **n** bytes of the hash value after the hash computation has been completed by **CryptDeriveKey**. If the hash is not a member of the SHA-2 family and the required key is for either 3DES or AES, the key is derived as follows:

1. Form a 64-byte buffer by repeating the constant **0x36** 64 times. Let **k** be the length of the hash value that is represented by the input parameter *hBaseData*. Set the first **k** bytes of the buffer to the result of an **XOR** operation of the first **k** bytes of the buffer with the hash value that is represented by the input parameter *hBaseData*.
2. Form a 64-byte buffer by repeating the constant **0x5C** 64 times. Set the first **k** bytes of the buffer to the result of an **XOR** operation of the first **k** bytes of the buffer with the hash value that is represented by the input parameter *hBaseData*.
3. Hash the result of step 1 by using the same hash algorithm as that used to compute the hash value that is represented by the *hBaseData* parameter.
4. Hash the result of step 2 by using the same hash algorithm as that used to compute the hash value that is represented by the *hBaseData* parameter.
5. Concatenate the result of step 3 with the result of step 4.
6. Use the first **n** bytes of the result of step 5 as the derived key.

The default RSA Full Cryptographic Service Provider is the Microsoft RSA Strong Cryptographic Provider. The default DSS Signature Diffie-Hellman Cryptographic Service Provider is the Microsoft Enhanced DSS Diffie-Hellman Cryptographic Provider. Each of these CSPs has a default 128-bit symmetric key length for [RC2](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) and RC4.

The following table lists minimum, default, and maximum key lengths for session key by algorithm and provider.

| Provider | Algorithms | Minimum key length | Default key length | Maximum key length |
| --- | --- | --- | --- | --- |
| MS Base | RC4 and RC2 | 40 | 40 | 56 |
| MS Base | DES | 56 | 56 | 56 |
| MS Enhanced | RC4 and RC2 | 40 | 128 | 128 |
| MS Enhanced | DES | 56 | 56 | 56 |
| MS Enhanced | 3DES 112 | 112 | 112 | 112 |
| MS Enhanced | 3DES | 168 | 168 | 168 |
| MS Strong | RC4 and RC2 | 40 | 128 | 128 |
| MS Strong | DES | 56 | 56 | 56 |
| MS Strong | 3DES 112 | 112 | 112 | 112 |
| MS Strong | 3DES | 168 | 168 | 168 |
| DSS/DH Base | RC4 and RC2 | 40 | 40 | 56 |
| DSS/DH Base | Cylink MEK | 40 | 40 | 40 |
| DSS/DH Base | DES | 56 | 56 | 56 |
| DSS/DH Enh | RC4 and RC2 | 40 | 128 | 128 |
| DSS/DH Enh | Cylink MEK | 40 | 40 | 40 |
| DSS/DH Enh | DES | 56 | 56 | 56 |
| DSS/DH Enh | 3DES 112 | 112 | 112 | 112 |
| DSS/DH Enh | 3DES | 168 | 168 | 168 |

#### Examples

For an example that uses this function, see [Example C Program: Deriving a Session Key from a Password](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-deriving-a-session-key-from-a-password).

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)

[CryptDestroyHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroyhash)

[CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey)

[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey)

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam)

[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata)

[CryptHashSessionKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashsessionkey)

[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam)

[Key Generation and Exchange Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
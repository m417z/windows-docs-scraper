# CryptEncrypt function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptEncrypt** function encrypts data. The algorithm used to encrypt the data is designated by the key held by the CSP module and is referenced by the *hKey* parameter.

Important changes to support [Secure/Multipurpose Internet Mail Extensions](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (S/MIME) email interoperability have been made to CryptoAPI that affect the handling of enveloped messages. For more information, see the Remarks section of [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode).

**Important** The **CryptEncrypt** function is not guaranteed to be thread safe and may return incorrect results if invoked simultaneously by multiple callers.

## Parameters

### `hKey` [in]

A handle to the encryption key. An application obtains this handle by using either the
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) or the
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey) function.

The key specifies the encryption algorithm used.

### `hHash` [in]

A handle to a [hash object](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly). If data is to be hashed and encrypted simultaneously, a handle to a hash object can be passed in the *hHash* parameter. The hash value is updated with the [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) passed in. This option is useful when generating signed and encrypted text.

Before calling **CryptEncrypt**, the application must obtain a handle to the hash object by calling the
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash) function. After the encryption is complete, the hash value can be obtained by using the
[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam) function, or the hash can be signed by using the
[CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha) function.

If no hash is to be done, this parameter must be **NULL**.

### `Final` [in]

A Boolean value that specifies whether this is the last section in a series being encrypted. *Final* is set to **TRUE** for the last or only block and to **FALSE** if there are more blocks to be encrypted. For more information, see Remarks.

### `dwFlags` [in]

The following *dwFlags* value is defined but reserved for future use.

| Value | Meaning |
| --- | --- |
| **CRYPT_OAEP** | Use Optimal Asymmetric Encryption Padding (OAEP) (PKCS #1 version 2). This flag is only supported by the [Microsoft Enhanced Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-enhanced-cryptographic-provider) with RSA encryption/decryption. |

### `pbData` [in, out]

A pointer to a buffer that contains the plaintext to be encrypted. The plaintext in this buffer is overwritten with the [ciphertext](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) created by this function.

The *pdwDataLen* parameter points to a variable that contains the length, in bytes, of the plaintext. The *dwBufLen* parameter contains the total size, in bytes, of this buffer.

If this parameter contains **NULL**, this function will calculate the required size for the ciphertext and place that in the value pointed to by the *pdwDataLen* parameter.

### `pdwDataLen` [in, out]

A pointer to a **DWORD** value that , on entry, contains the length, in bytes, of the plaintext in the *pbData* buffer. On exit, this **DWORD** contains the length, in bytes, of the ciphertext written to the *pbData* buffer.

If the buffer allocated for *pbData* is not large enough to hold the encrypted data,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_MORE_DATA** and stores the required buffer size, in bytes, in the **DWORD** value pointed to by *pdwDataLen*.

If *pbData* is **NULL**, no error is returned, and the function stores the size of the encrypted data, in bytes, in the **DWORD** value pointed to by *pdwDataLen*. This allows an application to determine the correct buffer size.

When a [block cipher](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) is used, this data length must be a multiple of the block size unless this is the final section of data to be encrypted and the *Final* parameter is **TRUE**.

### `dwBufLen` [in]

Specifies the total size, in bytes, of the input *pbData* buffer.

Note that, depending on the algorithm used, the encrypted text can be larger than the original plaintext. In this case, the *pbData* buffer needs to be large enough to contain the encrypted text and any padding.

As a rule, if a [stream cipher](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is used, the ciphertext is the same size as the plaintext. If a [block cipher](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) is used, the ciphertext is up to a block length larger than the plaintext.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The error codes prefaced by NTE are generated by the particular CSP being used. Some possible error codes follow.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | One of the parameters specifies a handle that is not valid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. This is most often a pointer that is not valid. |
| **NTE_BAD_ALGID** | The *hKey* [session key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) specifies an algorithm that this CSP does not support. |
| **NTE_BAD_DATA** | The data to be encrypted is not valid. For example, when a block cipher is used and the *Final* flag is **FALSE**, the value specified by *pdwDataLen* must be a multiple of the block size. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter is nonzero. |
| **NTE_BAD_HASH** | The *hHash* parameter contains a handle that is not valid. |
| **NTE_BAD_HASH_STATE** | An attempt was made to add data to a hash object that is already marked "finished." |
| **NTE_BAD_KEY** | The *hKey* parameter does not contain a valid handle to a key. |
| **NTE_BAD_LEN** | The size of the output buffer is too small to hold the generated ciphertext. |
| **NTE_BAD_UID** | The CSP context that was specified when the key was created cannot be found. |
| **NTE_DOUBLE_ENCRYPT** | The application attempted to encrypt the same data twice. |
| **NTE_FAIL** | The function failed in some unexpected way. |
| **NTE_NO_MEMORY** | The CSP ran out of memory during the operation. |

## Remarks

If a large amount of data is to be encrypted, it can be done in sections by calling **CryptEncrypt** repeatedly. The *Final* parameter must be set to **TRUE** on the last call to **CryptEncrypt**, so that the encryption engine can properly finish the encryption process. The following extra actions are performed when *Final* is **TRUE**:

* If the key is a block cipher key, the data is padded to a multiple of the block size of the cipher. If the data length equals the block size of the cipher, one additional block of padding is appended to the data. To find the block size of a cipher, use
  [CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam) to get the KP_BLOCKLEN value of the key.
* If the cipher is operating in a [chaining mode](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), the next **CryptEncrypt** operation resets the cipher's feedback register to the KP_IV value of the key.
* If the cipher is a [stream cipher](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), the next **CryptEncrypt** resets the cipher to its initial [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

There is no way to set the cipher's feedback register to the KP_IV value of the key without setting the *Final* parameter to **TRUE**. If this is necessary, as in the case where you do not want to add an additional padding block or change the size of each block, you can simulate this by creating a duplicate of the original key by using the [CryptDuplicateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptduplicatekey) function, and passing the duplicate key to the **CryptEncrypt** function. This causes the KP_IV of the original key to be placed in the duplicate key. After you create or import the original key, you cannot use the original key for encryption because the feedback register of the key will be changed. The following pseudocode shows how this can be done.

``` syntax
// Set the IV for the original key. Do not use the original key for
// encryption or decryption after doing this because the key's
// feedback register will get modified and you cannot change it.
CryptSetKeyParam(hOriginalKey, KP_IV, newIV)

while(block = NextBlock())
{
    // Create a duplicate of the original key. This causes the
    // original key's IV to be copied into the duplicate key's
    // feedback register.
    hDuplicateKey = CryptDuplicateKey(hOriginalKey)

    // Encrypt the block with the duplicate key.
    CryptEncrypt(hDuplicateKey, block)

    // Destroy the duplicate key. Its feedback register has been
    // modified by the CryptEncrypt function, so it cannot be used
    // again. It will be re-duplicated in the next iteration of the
    // loop.
    CryptDestroyKey(hDuplicateKey)
}
```

The [Microsoft Enhanced Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-enhanced-cryptographic-provider) supports direct encryption with [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) [public keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and decryption with RSA [private keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The encryption uses PKCS #1 [padding](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). On decryption, this padding is verified. The length of plaintext data that can be encrypted with a call to **CryptEncrypt** with an RSA key is the length of the key modulus minus eleven bytes. The eleven bytes is the chosen minimum for PKCS #1 padding. The ciphertext is returned in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) format.

#### Examples

For examples that use this function, see [Example C Program: Encrypting a File](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encrypting-a-file) and [Example C Program: Decrypting a File](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-decrypting-a-file).

## See also

[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)

[CryptDecrypt](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecrypt)

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam)

[CryptGetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetkeyparam)

[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha)

[Data Encryption and Decryption Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
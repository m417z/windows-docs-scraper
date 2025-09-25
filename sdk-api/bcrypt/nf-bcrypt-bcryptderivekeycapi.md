# BCryptDeriveKeyCapi function

## Description

The **BCryptDeriveKeyCapi** function derives a key from a hash value.

This function is provided as a helper function to assist in migrating legacy Cryptography API (CAPI)–based applications to use Cryptography API: Next Generation (CNG). The **BCryptDeriveKeyCapi** function performs the key derivation in a manner that is compatible with the CAPI [CryptDeriveKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptderivekey) function.

## Parameters

### `hHash` [in]

The handle of the hash object. The handle is obtained by calling the [BCryptCreateHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatehash) function. When you have finished using the handle, you must free it by calling the [BCryptDestroyHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroyhash) function.

### `hTargetAlg` [in, optional]

The handle of the algorithm object. This can be an [ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id) value that is compatible with the [CryptDeriveKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptderivekey) function.

**Note** Limitations in CAPI and key expansion prevent the use of any hash algorithm that generates an output that is larger than 512 bits.

### `pbDerivedKey` [out]

A pointer to the buffer that receives the derived key.

### `cbDerivedKey` [in]

The size, in characters, of the derived key pointed to by the *pbDerivedKey* parameter.

### `dwFlags` [in]

This parameter is reserved and must be set to zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The handle in the *hHash* or *hTargetAlg* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | The value in the *cbDerivedKey* parameter is larger than twice the output size of the hash function. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

This function does not support the PK salt functionality of the CAPI [CryptDeriveKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptderivekey) function.
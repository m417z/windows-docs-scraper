# BCryptHash function

## Description

Performs a single cryptographic hash or [Message Authentication Code](https://learn.microsoft.com/windows/win32/SecGloss/m-gly) (MAC) computation. This is a convenience function that wraps calls to [BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash), [BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata), [BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash), and [BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash).

## Parameters

### `hAlgorithm` [in, out]

The handle of an algorithm provider that supports the hash or MAC interface. This handle is obtained by calling the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function, or may be a [CNG Algorithm Pseudo-handle](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-pseudo-handles).

### `pbSecret` [in, optional]

A pointer to a buffer that contains the key to use for a MAC. The *cbSecret* parameter contains the size of this buffer. If used with a hash algorithm, the algorithm must have been promoted to HMAC by using the **BCRYPT_ALG_HANDLE_HMAC** flag in [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider).

To compute a hash, set this parameter to `NULL`.

### `cbSecret` [in]

The size, in bytes, of the *pbSecret* buffer. If no key is used, set this parameter to zero.

### `pbInput` [in]

A pointer to a buffer that contains the data to process. The *cbInput* parameter contains the number of bytes in this buffer. This function does not modify the contents of this buffer.

### `cbInput` [in]

The size, in bytes, of the *pbInput* buffer.

### `pbOutput` [out]

A pointer to a buffer that receives the hash or MAC value. The *cbOutput* parameter contains the size of this buffer.

### `cbOutput` [in]

The size, in bytes, of the *pbOutput* buffer. This size must exactly match the size of the hash or MAC value if it has a fixed size.

The size can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_HASH_LENGTH** property. This will provide the size of the hash or MAC value for the specified algorithm. Extendable-output functions (XOFs), such as SHAKE256 may support a variable output size, but a default size which maintains full security of the XOF can be queried using **BCRYPT_HASH_LENGTH**.

## Return value

A status code indicating success or failure.

## See also

[BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash)

[BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata)

[BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash)

[BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash)
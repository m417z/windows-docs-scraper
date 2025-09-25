# BCryptCreateHash function

## Description

The **BCryptCreateHash** function is called to create a hash or [Message Authentication Code](https://learn.microsoft.com/windows/win32/SecGloss/m-gly) (MAC) object.

## Parameters

### `hAlgorithm` [in, out]

The handle of an algorithm provider that supports the hash or MAC interface. This handle is obtained by calling the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function, or may be a [CNG Algorithm Pseudo-handle](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-pseudo-handles).

### `phHash` [out]

A pointer to a **BCRYPT_HASH_HANDLE** value that receives a handle that represents the hash or MAC object. This handle is used in subsequent hashing or MAC functions, such as the [BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata) function. When you have finished using this handle, release it by passing it to the [BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash) function.

### `pbHashObject` [out, optional]

A pointer to a buffer that receives the hash or MAC object. The *cbHashObject* parameter contains the size of this buffer. The required size of this buffer can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_OBJECT_LENGTH** property from the algorithm handle. This will provide the size of the hash or MAC object for the specified algorithm.

This memory can only be freed after the handle pointed to by the *phHash* parameter is destroyed.

If the value of this parameter is `NULL` and the value of the *cbHashObject* parameter is zero, the memory for the hash object is allocated by this function, and freed by [BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash). **Windows 7:** This memory management functionality is available beginning with Windows 7.

### `cbHashObject` [in]

The size, in bytes, of the *pbHashObject* buffer.

If the value of this parameter is zero and the value of the *pbHashObject* parameter is `NULL`, the memory for the key object is allocated by this function, and freed by [BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash). **Windows 7:** This memory management functionality is available beginning with Windows 7.

### `pbSecret` [in, optional]

A pointer to a buffer that contains the key to use for a MAC. The *cbSecret* parameter contains the size of this buffer. If used with a hash algorithm, the algorithm must have been promoted to HMAC by using the **BCRYPT_ALG_HANDLE_HMAC** flag in [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider).

To compute a hash, set this parameter to `NULL`.

### `cbSecret` [in]

The size, in bytes, of the *pbSecret* buffer. If no key is used, set this parameter to zero.

### `dwFlags` [in]

Flags that modify the behavior of the function. This can be zero or the following value:

| Value | Meaning |
|-------|---------|
| **BCRYPT_HASH_REUSABLE_FLAG** | Creates a reusable hashing object. The object can be used for a new hashing operation immediately after calling [BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash). For more information, see [Creating a Hash with CNG](https://learn.microsoft.com/windows/desktop/SecCNG/creating-a-hash-with-cng).**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This flag is not supported. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the hash object specified by the *cbHashObject* parameter is not large enough to hold the hash object. |
| **STATUS_INVALID_HANDLE** | The algorithm handle in the *hAlgorithm* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The algorithm provider specified by the *hAlgorithm* parameter does not support the hash or MAC interface. |

## Remarks

When using a supported algorithm provider, **BCryptCreateHash** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hAlgorithm* parameter must have been opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptCreateHash** function must refer to nonpaged (or locked) memory.

The caller should release *phHash* with [BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash) when the object is no longer in use.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptDuplicateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptduplicatehash)

[BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata)

[BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash)

[BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash)
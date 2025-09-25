# BCryptGenerateSymmetricKey function

## Description

The **BCryptGenerateSymmetricKey** function creates a key object for use with an algorithm which uses symmetric keys, using supplied secret key data.

## Parameters

### `hAlgorithm` [in, out]

The handle of an algorithm provider that uses symmetric keys. Examples of types of algorithms include Ciphers, and Key Derivation Functions (KDF). This handle is obtained by calling the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function, or may be a [CNG Algorithm Pseudo-handle](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-pseudo-handles).

### `phKey` [out]

A pointer to a **BCRYPT_KEY_HANDLE** that receives the handle of the key. This handle is used in subsequent functions that require a symmetric key, such as [BCryptEncrypt](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptencrypt) and [BCryptKeyDerivation](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptkeyderivation). This handle must be released when it is no longer needed by passing it to the [BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

### `pbKeyObject` [out, optional]

A pointer to a buffer that receives the key object. The *cbKeyObject* parameter contains the size of this buffer. The required size of this buffer can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_OBJECT_LENGTH** property from the algorithm handle. This will provide the size of the key object for the specified algorithm.

This memory can only be freed after the *phKey* key handle is destroyed.

If the value of this parameter is `NULL` and the value of the *cbKeyObject* parameter is zero, the memory for the key object is allocated by this function, and freed by [BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey). **Windows 7:** This memory management functionality is available beginning with Windows 7.

### `cbKeyObject` [in]

The size, in bytes, of the *pbKeyObject* buffer.

If the value of this parameter is zero and the value of the *pbKeyObject* parameter is `NULL`, the memory for the key object is allocated by this function, and freed by [BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey). **Windows 7:** This memory management functionality is available beginning with Windows 7.

### `pbSecret` [in]

Pointer to a buffer that contains the key data from which to create the key object. The *cbSecret* parameter contains the size of this buffer. This is normally the result of a call to [BCryptDeriveKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptderivekey) or some other reproducible secret data. If the data passed in exceeds the target key size, the data will be truncated and the excess will be ignored.

> [!NOTE]
> We strongly recommended that applications pass in the exact number of bytes required by the target key.

### `cbSecret` [in]

The size, in bytes, of the *pbSecret* buffer.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are currently defined, so this parameter should be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the key object specified by the *cbKeyObject* parameter is not large enough to hold the key object. |
| **STATUS_INVALID_HANDLE** | The algorithm handle in the *hAlgorithm* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |

## Remarks

When using a supported algorithm provider, *BCryptGenerateSymmetricKey* can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hAlgorithm* parameter must have been opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the *BCryptGenerateSymmetricKey* function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptDestroyKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroykey)
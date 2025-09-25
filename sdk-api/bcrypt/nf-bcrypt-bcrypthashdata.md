# BCryptHashData function

## Description

The **BCryptHashData** function appends data to an ongoing cryptographic hash or [Message Authentication Code](https://learn.microsoft.com/windows/win32/SecGloss/m-gly) (MAC) computation.

## Parameters

### `hHash` [in, out]

The handle of the hash or MAC object to use to perform the operation. This handle is obtained by calling the [BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash) or [BCryptDuplicateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptduplicatehash) functions.

### `pbInput` [in]

A pointer to a buffer that contains the data to process. The *cbInput* parameter contains the number of bytes in this buffer. This function does not modify the contents of this buffer.

### `cbInput` [in]

The size, in bytes, of the *pbInput* buffer.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are currently defined, so this parameter should be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_INVALID_HANDLE** | The handle in the *hHash* parameter is not valid. After the [BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash) function has been called, that handle cannot be reused, unless the handle was created with the **BCRYPT_HASH_REUSABLE_FLAG** flag. |

## Remarks

To combine more than one buffer into the hash or MAC, you can call this function multiple times, passing a different buffer each time. This is functionally equivalent to concatenating these buffers into a single buffer and doing a single hash or MAC call, but is more often more convenient when the data is not naturally contiguous in memory.

To obtain the hash or MAC value, call the [BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash) function. After the [BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash) function has been called, the *hHash* handle cannot be reused, unless it was created with the **BCRYPT_HASH_REUSABLE_FLAG** flag.

When using a supported algorithm provider, **BCryptHashData** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hAlgorithm* parameter must have been opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptHashData** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash)

[BCryptFinishHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinishhash)

[BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash)
# BCryptDuplicateKey function

## Description

The **BCryptDuplicateKey** function creates a duplicate of a [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `hKey` [in]

The handle of the key to duplicate. This must be a handle to a symmetric key.

### `phNewKey` [out]

A pointer to a **BCRYPT_KEY_HANDLE** variable that receives the handle of the duplicate key. This handle is used in subsequent functions that require a key, such as [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt). This handle must be released when it is no longer needed by passing it to the [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey) function.

### `pbKeyObject` [out]

An ***optional*** pointer to a buffer that receives the duplicate key object. The *cbKeyObject* parameter contains the size of this buffer. The required size of this buffer can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_OBJECT_LENGTH** property. This will provide the size of the key object for the specified algorithm.

This memory can only be freed after the *phNewKey* key handle is destroyed.

If the value of this parameter is **NULL** and the value of the *cbKeyObject* parameter is zero, the memory for the duplicate key object is allocated by this function and freed by [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey). **Windows 7:** This memory management functionality is available beginning with Windows 7.

### `cbKeyObject` [in]

The size, in bytes, of the *pbKeyObject* buffer.

If the value of this parameter is zero and the value of the *pbKeyObject* parameter is **NULL**, the memory for the duplicate key object is allocated by this function and freed by [BCryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroykey). **Windows 7:** This memory management functionality is available beginning with Windows 7.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are currently defined, so this parameter should be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the key object specified by the *cbKeyObject* parameter is not large enough to hold the key object. |
| **STATUS_INVALID_HANDLE** | The key handle in the *hKey* parameter is not valid. This value is also returned if the key to duplicate is not a symmetric key. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |

## Remarks

When using a supported algorithm provider, **BCryptDuplicateKey** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hKey* parameter must be derived from an algorithm handle returned by a provider that was opened with the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptDuplicateKey** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.
# BCryptFinalizeKeyPair function

## Description

The **BCryptFinalizeKeyPair** function completes a [public/private key pair](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The key cannot be used until this function has been called. After this function has been called, the [BCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsetproperty) function can no longer be used for this key.

## Parameters

### `hKey` [in, out]

The handle of the key to complete. This handle is obtained by calling the [BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair) function.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are currently defined, so this parameter should be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The key handle in the *hKey* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The specified provider does not support asymmetric key encryption. |

## Remarks

When using a supported algorithm provider, **BCryptFinalizeKeyPair** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hKey* parameter must be derived from an algorithm handle returned by a provider that was opened with the **BCRYPT_PROV_DISPATCH** flag.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair)
# BCryptDestroyHash function

## Description

The **BCryptDestroyHash** function destroys a hash or [Message Authentication Code](https://learn.microsoft.com/windows/win32/SecGloss/m-gly) (MAC) object.

## Parameters

### `hHash` [in, out]

The handle of the hash or MAC object to destroy. This handle is obtained by using the [BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash) function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The algorithm handle in the *hHash* parameter is not valid. |

## Remarks

When using a supported algorithm provider, *BCryptDestroyHash* can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hHash* parameter must be derived from an algorithm handle returned by a provider that was opened by using the **BCRYPT_PROV_DISPATCH** flag.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash)
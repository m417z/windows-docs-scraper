# BCryptDestroySecret function

## Description

The **BCryptDestroySecret** function destroys a secret agreement handle that was created by using the [BCryptSecretAgreement](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsecretagreement) function.

## Parameters

### `hSecret` [in]

The **BCRYPT_SECRET_HANDLE** to be destroyed.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The handle in the *hSecret* parameter is not valid. |

## Remarks

When using a supported algorithm provider, **BCryptDestroySecret** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hSecret* parameter must be derived from an algorithm handle returned by a provider that was opened by using the **BCRYPT_PROV_DISPATCH** flag.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptSecretAgreement](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptsecretagreement)
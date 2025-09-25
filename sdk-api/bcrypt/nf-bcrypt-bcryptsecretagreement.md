# BCryptSecretAgreement function

## Description

The **BCryptSecretAgreement** function creates a secret agreement value from a private and a public key.

## Parameters

### `hPrivKey` [in]

The handle of the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to create the secret agreement value. This key and the *hPubKey* key must come from the same CNG cryptographic algorithm provider.

### `hPubKey` [in]

The handle of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to create the secret agreement value. This key and the *hPrivKey* key must come from the same CNG cryptographic algorithm provider.

### `phAgreedSecret` [out]

A pointer to a **BCRYPT_SECRET_HANDLE** that receives a handle that represents the secret agreement value. This handle must be released by passing it to the [BCryptDestroySecret](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroysecret) function when it is no longer needed.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The key handle in the *hPrivKey* or *hPubKey* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The key handle in the *hPrivKey* parameter is not a Diffie-Hellman key. |

## Remarks

When using a supported algorithm provider, **BCryptSecretAgreement** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handles provided in the *hPrivKey* and *hPubKey* parameters must be derived from an algorithm handle returned by a provider that was opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptSecretAgreement** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptDestroySecret](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptdestroysecret)
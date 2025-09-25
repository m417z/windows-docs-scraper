# NCryptSecretAgreement function

## Description

The **NCryptSecretAgreement** function creates a secret agreement value from a private and a public key.

## Parameters

### `hPrivKey` [in]

The handle of the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to create the secret agreement value. This key and the *hPubKey* key must come from the same key storage provider.

### `hPubKey` [in]

The handle of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to create the secret agreement value. This key and the *hPrivKey* key must come from the same key storage provider.

### `phAgreedSecret` [out]

A pointer to an **NCRYPT_SECRET_HANDLE** variable that receives a handle that represents the secret agreement value. When this handle is no longer needed, release it by passing it to the [NCryptFreeObject](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreeobject) function.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of one or more of the following values. The set of valid flags is specific to each key storage provider. The following flag applies to all providers.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_HANDLE** | The *hPrivKey* or the *hPubKey* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

## See also

[NCryptFreeObject](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreeobject)
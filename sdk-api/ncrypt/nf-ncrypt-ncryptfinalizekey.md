# NCryptFinalizeKey function

## Description

The **NCryptFinalizeKey** function completes a CNG key storage key. The key cannot be used until this function has been called.

## Parameters

### `hKey` [in]

The handle of the key to complete. This handle is obtained by calling the [NCryptCreatePersistedKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptcreatepersistedkey) function.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_NO_KEY_VALIDATION** | Do not validate the public portion of the key pair. This flag only applies to public/private key pairs. |
| **NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG** | Also save the key in legacy storage. This allows the key to be used with CryptoAPI. This flag only applies to RSA keys. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_HANDLE** | The *hKey* parameter is not valid. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.
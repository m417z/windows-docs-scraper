# NCryptEnumStorageProviders function

## Description

The **NCryptEnumStorageProviders** function obtains the names of the registered key storage providers.

## Parameters

### `pdwProviderCount` [out]

The address of a **DWORD** to receive the number of elements in the *ppProviderList* array.

### `ppProviderList` [out]

The address of an [NCryptProviderName](https://learn.microsoft.com/windows/desktop/api/ncrypt/ns-ncrypt-ncryptprovidername) structure pointer to receive an array of the registered key storage provider names. The variable pointed to by the *pdwProviderCount* parameter receives the number of elements in this array.

When this memory is no longer needed, free it by passing this pointer to the [NCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreebuffer) function.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero (0) or the following value.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

## See also

[NCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreebuffer)
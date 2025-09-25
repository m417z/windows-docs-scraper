# NCryptEnumKeys function

## Description

The **NCryptEnumKeys** function obtains the names of the keys that are stored by the provider.

## Parameters

### `hProvider` [in]

The handle of the key storage provider to enumerate the keys for. This handle is obtained with the [NCryptOpenStorageProvider](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenstorageprovider) function.

### `pszScope` [in, optional]

This parameter is not currently used and must be **NULL**.

### `ppKeyName` [out]

The address of a pointer to an [NCryptKeyName](https://learn.microsoft.com/windows/desktop/api/ncrypt/ns-ncrypt-ncryptkeyname) structure that receives the name of the retrieved key. When the application has finished using this memory, free it by calling the [NCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreebuffer) function.

### `ppEnumState` [in, out]

The address of a **VOID** pointer that receives enumeration state information that is used in subsequent calls to this function. This information only has meaning to the key storage provider and is opaque to the caller. The key storage provider uses this information to determine which item is next in the enumeration. If the variable pointed to by this parameter contains **NULL**, the enumeration is started from the beginning.

When this memory is no longer needed, it must be freed by passing this pointer to the [NCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreebuffer) function.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_MACHINE_KEY_FLAG** | Enumerate the keys for the local computer. If this flag is not present, the current user keys are enumerated. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_HANDLE** | The *hProvider* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |
| **NTE_NO_MORE_ITEMS** | The end of the enumeration has been reached. |
| **NTE_SILENT_CONTEXT** | The *dwFlags* parameter contains the **NCRYPT_SILENT_FLAG** flag, but the key being enumerated requires user interaction. |

## Remarks

This function retrieves only one item each time it is called. The state of the enumeration is stored in the variable pointed to by the *ppEnumState* parameter, so this must be preserved between calls to this function. When the last key stored by the provider has been retrieved, this function will return **NTE_NO_MORE_ITEMS** the next time it is called. To start the enumeration over, set the variable pointed to by the *ppEnumState* parameter to **NULL**, free the memory pointed to by the *ppKeyName* parameter, if it is not **NULL**, and call this function again.

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.
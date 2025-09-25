# NCryptDeleteKey function

## Description

The **NCryptDeleteKey** function deletes a CNG key.

## Parameters

### `hKey` [in]

The handle of the key to delete. This handle is obtained by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

**Note** The **NCryptDeleteKey** function deletes the key and frees the handle. Applications may use [NCryptFreeObject](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreeobject) function to free the handle if **NCryptDeleteKey** fails.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of values that is specific to each key storage provider.

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
| **NTE_INVALID_HANDLE** | The *hKey* parameter is not valid. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

## See also

[NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey)
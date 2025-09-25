# IAzAuthorizationStore::CloseApplication

## Description

The **CloseApplication** method unloads a specified [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object from the cache.

This method is not supported for XML authorization policy stores.

## Parameters

### `bstrApplicationName` [in]

The name of the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object to close.

### `lFlag` [in]

Flags that control the behavior of the operation. The following table shows the possible values.

| Value | Meaning |
|--------|--------|
| **0** | Child objects of the specified [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object will be unloaded from the cache only when the user closes the last handle to the **IAzApplication** object. |
| **AZ_AZSTORE_FORCE_APPLICATION_CLOSE** | All child objects of the specified [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object will be forcefully closed. Attempts to reference an open handle to a child object of the specified **IAzApplication** object will result in an **HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE)** error. This flag should be used only if the user has implemented code to gracefully handle the error. |

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## See also

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)
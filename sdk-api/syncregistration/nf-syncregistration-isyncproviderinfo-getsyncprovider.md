# ISyncProviderInfo::GetSyncProvider

## Description

Creates an instance of the synchronization provider.

## Parameters

### `dwClsContext` [in]

The context in which the code that manages the newly created object will run. The only context supported is **CLSCTX_INPROC_SERVER**.

### `ppSyncProvider` [out]

The instance of the synchronization provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to create the synchronization provider. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)** | Information stored in the registration store is an unexpected size. |

## See also

[ISyncProviderInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo)
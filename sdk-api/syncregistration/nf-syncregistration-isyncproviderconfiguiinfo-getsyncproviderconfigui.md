# ISyncProviderConfigUIInfo::GetSyncProviderConfigUI

## Description

Creates an instance of a synchronization provider configuration UI.

## Parameters

### `dwClsContext` [in]

The context in which the code that manages the newly created object will run. The only context supported is **CLSCTX_INPROC_SERVER**.

### `ppSyncProviderConfigUI` [out]

The instance of the synchronization provider configuration UI.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to create the configuration UI. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)** | Information stored in the registration store is an unexpected size. |

## See also

[ISyncProviderConfigUIInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo)
# ISyncProviderConfigUI::CreateAndRegisterNewSyncProvider

## Description

Creates and registers a new synchronization provider.

## Parameters

### `hwndParent` [in]

HWND serving as the parent for the configuration UI that needs to be presented before the synchronization provider can be created.
The HWND should be **NULL** only if the **dwCapabilities** member of the [SyncProviderConfigUIConfiguration](https://learn.microsoft.com/windows/win32/api/syncregistration/ns-syncregistration-syncproviderconfiguiconfiguration) structure is set to not support a UI.

### `pUnkContext` [in]

Pointer to an interface containing additional information needed to generate the synchronization provider. The pointer will be **NULL** if no additional information is needed.

### `ppProviderInfo` [out]

An [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) object that contains information about the newly created and registered synchronization provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to create and register the synchronization provider. |

## See also

[ISyncProviderConfigUI Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui)
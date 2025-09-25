# ISyncProviderRegistration::UnregisterSyncProviderConfigUI

## Description

Unregisters and removes the specified synchronization provider configuration UI from the registration store.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the synchronization provider configuration UI.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | The CLSID and content type combination does not exist in the registration store for a configuration UI. |

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)

[SyncProviderConfigUIConfiguration Structure](https://learn.microsoft.com/windows/desktop/api/syncregistration/ns-syncregistration-syncproviderconfiguiconfiguration)
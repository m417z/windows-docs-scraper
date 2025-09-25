# ISyncProviderRegistration::UnregisterSyncProvider

## Description

Unregisters and removes the specified synchronization provider from the registration store.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the synchronization provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | A synchronization provider with the specified instance ID is not currently registered. |

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
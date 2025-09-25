# ISyncProviderRegistration::GetSyncProviderState

## Description

Returns the state of the specified synchronization provider.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the synchronization provider.

### `pdwStateFlags` [out]

One of the following flags that represent the synchronization provider state.

* **SYNC_PROVIDER_STATE_ENABLED** ((DWORD)0x00000001)The provider is enabled and available for synchronization.
* **SYNC_PROVIDER_STATE_DIRTY** ((DWORD)0x00000002)The active provider has been updated and has new data to synchronize.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | A synchronization provider with the specified instance ID was not registered. |

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
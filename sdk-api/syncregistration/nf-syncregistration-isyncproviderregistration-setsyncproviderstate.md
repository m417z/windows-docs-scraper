# ISyncProviderRegistration::SetSyncProviderState

## Description

Sets the state of the specified synchronization provider.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the synchronization provider.

### `dwStateFlagsMask` [in]

A synchronization provider state flag that can be used to mask (preserve or remove) the existing state. If this parameter is set to zero, all synchronization provider states will be enumerated. See the *dwStateFlags* parameter description for a list of flags.

### `dwStateFlags` [in]

One of the following flags that represent the synchronization provider state.

* **SYNC_PROVIDER_STATE_ENABLED** ((DWORD)0x00000001)The provider is enabled and available for synchronization.
* **SYNC_PROVIDER_STATE_DIRTY** ((DWORD)0x00000002)The active provider has been updated and has new data to synchronize.

If this parameter is set to zero, all synchronization provider states will be enumerated.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | A synchronization provider with the specified instance ID was not registered. |

## Remarks

To get the synchronization provider state, call the [GetSyncProviderState](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-getsyncproviderstate) method.

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
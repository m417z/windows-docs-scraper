# ISyncProviderRegistration::CreateSyncProviderRegistrationInstance

## Description

Creates an in-memory instance of a synchronization provider.

## Parameters

### `pProviderConfiguration` [in]

A [SyncProviderConfiguration](https://learn.microsoft.com/windows/win32/api/syncregistration/ns-syncregistration-syncproviderconfiguration) structure that contains the synchronization provider registration information.

### `ppProviderInfo` [out]

Returns a pointer to an [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) interface that is used to obtain information about the synchronization provider and access the configuration property store in order to store the synchronization provider configuration.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_ALREADYREGISTERED** | The same unique instance ID has already been registered for a synchronization provider. |

## Remarks

The synchronization provider is not registered on the system until the **ISyncProviderInfo::Commit** method is called. This method is inherited by [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) from **IPropertyStore**. For an example of this, see [Overview of Registering a Synchronization Provider](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/overview-of-registering-a-synchronization-provider).

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)

[SyncProviderConfiguration Structure](https://learn.microsoft.com/windows/win32/api/syncregistration/ns-syncregistration-syncproviderconfiguration)
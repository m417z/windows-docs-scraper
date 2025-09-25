# ISyncProviderRegistration::GetSyncProviderInfo

## Description

Returns an [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) object for the specific synchronization provider instance ID.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the synchronization provider.

### `ppProviderInfo` [out]

The synchronization provider information object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | The specified instance ID does not match a registered synchronization provider. |

## Remarks

By calling the [GetSyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderinfo-getsyncprovider) method of the **ISyncProviderInfo** object that is returned by this method, you can get and set the properties of the synchronization provider, and obtain the synchronization provider's [IRegisteredSyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-iregisteredsyncprovider) instance.

## See also

[IRegisteredSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-iregisteredsyncprovider)

[ISyncProviderInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
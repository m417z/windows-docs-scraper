# ISyncProviderRegistration::GetSyncProviderConfigUIInfoforProvider

## Description

Returns an [ISyncProviderConfigUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo) object for the specified synchronization provider instance ID.

## Parameters

### `pguidProviderInstanceId` [in]

The unique instance ID of the synchronization provider.

### `ppProviderConfigUIInfo` [out]

The configuration UI information object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | No configuration UI was specified for the synchronization provider. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to return the synchronization provider. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | The specified instance ID does not match a registered synchronization provider, or the requested configuration UI is not registered. |

## Remarks

This method is used to get and set the configuration UI properties for the specified synchronization provider and to obtain the **ISyncProviderConfigUI** instance.

This method is used to obtain an **ISyncProviderConfigUIInfo** object when the instance ID is not known, but the instance ID of the synchronization provider is known. The [GetSyncProviderConfigUIFromInstanceId](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-getsyncproviderconfiguifrominstanceid) method should be used if you want to access an **ISyncProviderConfigUIInfo** object directly using the instance ID of an **ISyncProviderConfigUI**.

## See also

[ISyncProviderConfigUI Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui)

[ISyncProviderConfigUIInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
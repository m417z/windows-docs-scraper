# ISyncProviderRegistration::GetSyncProviderConfigUIInfo

## Description

Returns an [ISyncProviderConfigUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo) object for the given unique instance ID.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the **ISyncProviderConfigUIInfo** object.

### `ppConfigUIInfo` [out]

The configuration UI information object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to return the configuration UI. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | A configuration UI with the specified instance ID was not registered. |

## Remarks

This method is used to get and set the configuration UI properties for the specified configuration UI object.

## See also

[ISyncProviderConfigUIInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
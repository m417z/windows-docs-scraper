# ISyncProviderRegistration::CreateSyncProviderConfigUIRegistrationInstance

## Description

Creates an in-memory instance of a synchronization provider configuration UI.

## Parameters

### `pConfigUIConfig` [in]

A [SyncProviderConfigUIConfiguration](https://learn.microsoft.com/windows/win32/api/syncregistration/ns-syncregistration-syncproviderconfiguiconfiguration) structure that contains the configuration UI registration information.

### `ppConfigUIInfo` [out]

 Returns a pointer to an [ISyncProviderConfigUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo) interface that is used to store the configuration UI’s UX elements and any necessary persisted configuration information.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_REGISTRATION_ALREADYREGISTERED** | The same CLSID and content type combination, or the same unique instance ID has already been registered for a configuration UI. |

## Remarks

The configuration UI is not registered on the system until the **ISyncProviderConfigUIInfo::Commit** method is called. This method is inherited by [ISyncProviderConfigUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo) from **IPropertyStore**.

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)

[SyncProviderConfigUIConfiguration Structure](https://learn.microsoft.com/windows/win32/api/syncregistration/ns-syncregistration-syncproviderconfiguiconfiguration)
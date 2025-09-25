# ISyncProviderRegistration::GetSyncProviderConfigUIFromInstanceId

## Description

Returns an initialized and instantiated [ISyncProviderConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui) object for the given unique instance ID.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the **ISyncProviderConfigUI** object.

### `dwClsContext` [in]

The context in which the code that manages the newly created object will run. The only context supported is **CLSCTX_INPROC_SERVER**.

### `ppConfigUI` [out]

The initialized and instantiated configuration UI object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** | The instance ID is **GUID_NULL**. |
| **E_OUTOFMEMORY** | There was not enough memory available to create the configuration UI. |
| **REGDB_E_CLASSNOTREG** | The synchronization provider’s CLSID is not registered with the requested context or the configuration UI has not had its DLL registered. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | A configuration UI with the specified instance ID was not registered. |

## Remarks

This method is used to obtain an **ISyncProviderConfigUIInfo** directly when the instance ID of the **ISyncProviderConfigUI** is known. The [GetSyncProviderConfigUIInfoforProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-getsyncproviderconfiguiinfoforprovider) method can be used to access an **ISyncProviderConfigUIInfo** object from the instance ID of a synchronization provider.

## See also

[ISyncProviderConfigUI Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
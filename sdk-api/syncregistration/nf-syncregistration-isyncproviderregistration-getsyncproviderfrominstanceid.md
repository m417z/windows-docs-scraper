# ISyncProviderRegistration::GetSyncProviderFromInstanceId

## Description

Returns an initialized and instantiated [IRegisteredSyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-iregisteredsyncprovider) object for the specific unique instance ID.

## Parameters

### `pguidInstanceId` [in]

The unique instance ID of the **IRegisteredSyncProvider** object.

### `dwClsContext` [in]

The context in which the code that manages the newly created object will run. The only context supported is **CLSCTX_INPROC_SERVER**.

### `ppSyncProvider` [out]

The initialized and instantiated synchronization provider object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** | The instance ID is **GUID_NULL**. |
| **E_OUTOFMEMORY** | There was not enough memory available to create the synchronization provider. |
| **REGDB_E_CLASSNOTREG** | The synchronization provider’s CLSID is not registered with the requested context or the provider has not had its DLL registered. |
| **SYNC_E_REGISTRATION_NOTREGISTERED** | A synchronization provider with the specified instance ID was not registered. |

## Remarks

**Note** The caller of this method should not explicitly call **IRegisteredSyncProvider::Init** on the **IRegisteredSyncProvider** object that is returned, as this method will do this on the caller's behalf. The caller should call **QueryInterface** on the **IRegisteredSyncProvider** object that is returned to obtain an [ISyncProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider) interface to pass to the synchronization session.

## See also

[IRegisteredSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-iregisteredsyncprovider)

[ISyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)
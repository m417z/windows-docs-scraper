# IKnowledgeSyncProvider::ProcessChangeBatch

## Description

Processes a set of changes by detecting conflicts and applying changes to the item store.

## Parameters

### `resolutionPolicy` [in]

The conflict resolution policy to use when this method applies changes.

### `pSourceChangeBatch` [in]

A batch of changes from the source provider to be applied locally.

### `pUnkDataRetriever` [in]

An object that can be used to retrieve change data. It can be an [ISynchronousDataRetriever](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever) object or a provider-specific object.

### `pCallback` [in]

An object that receives event notifications during change application.

### `pSyncSessionStatistics` [in, out]

Tracks change statistics. For a provider that uses custom change application, this object must be updated with the results of the change application.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## Remarks

When a source change contains change unit changes, the destination provider must determine which, if any, change unit versions to include in the batch of destination versions that is sent to the change applier. This decision depends on the kind of change from the source provider and whether the item is marked as deleted on the destination replica.

## See also

[CONFLICT RESOLUTION POLICY Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-conflict_resolution_policy)

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)
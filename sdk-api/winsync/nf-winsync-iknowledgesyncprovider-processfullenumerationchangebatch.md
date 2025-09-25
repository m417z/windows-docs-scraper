# IKnowledgeSyncProvider::ProcessFullEnumerationChangeBatch

## Description

Processes a set of changes for a full enumeration by applying changes to the item store.

## Parameters

### `resolutionPolicy` [in]

The conflict resolution policy to use when this method applies changes.

### `pSourceChangeBatch` [in]

A batch of changes from the source provider to be applied locally.

### `pUnkDataRetriever` [in]

An object that can be used to retrieve change data. It can be an **ISynchronousDataRetriever** object or a provider-specific object.

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

This method is called during forgotten knowledge recovery.

## See also

[CONFLICT RESOLUTION POLICY Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-conflict_resolution_policy)

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)

[SYNC RANGE Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_range)
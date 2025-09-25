# IKnowledgeSyncProvider::GetFullEnumerationChangeBatch

## Description

Gets a change batch that contains item metadata for items that have IDs greater than the specified lower bound, as part of a full enumeration.

## Parameters

### `dwBatchSize` [in]

The number of changes to include in the change batch.

### `pbLowerEnumerationBound` [in]

The lower bound for item IDs. This method returns changes that have IDs greater than or equal to this ID value.

### `pSyncKnowledge` [in]

If an item change is contained in this knowledge object, data for that item already exists on the destination replica.

### `ppSyncChangeBatch` [out]

Returns a change batch that contains item metadata for items that have IDs greater than the specified lower bound.

### `ppUnkDataRetriever` [out]

Returns an object that can be used to retrieve change data. It can be an [ISynchronousDataRetriever](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever) object or a provider-specific object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## Remarks

This method enumerates, in sorted order by item ID, changes that have an item ID of *pbLowerEnumerationBound* or greater. This enables a synchronization session to determine which items on the destination provider have been deleted but forgotten by the source provider. Optionally, this method can also add changes to the batch, sorted by item ID, that have item ID less than *pbLowerEnumerationBound* and that are not contained in the destination knowledge.

**Note** If there are no more changes to send after this batch, [ISyncChangeBatchBase::SetLastBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangebatchbase-setlastbatch) must be called on the returned change batch. Otherwise, the synchronization session calls **GetFullEnumerationChangeBatch** again to retrieve another batch of changes.

For a provider that sends item data together with item change metadata, *pSyncKnowledge* can be used to determine whether it is necessary to send item data. Item data does not have to be sent when the item change is contained in *pSyncKnowledge*. Be aware that before it can be used to check items for containment, *pSyncKnowledge* must be mapped by using the [ISyncKnowledge::MapRemoteToLocal](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-mapremotetolocal) method on the knowledge object that is contained in the current provider.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISynchronousDataRetriever Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever)

[Windows Sync Reference](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-reference)
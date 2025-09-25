# IKnowledgeSyncProvider::GetChangeBatch

## Description

Gets a change batch that contains item metadata for items that are not contained in the specified knowledge from the destination provider.

## Parameters

### `dwBatchSize` [in]

The requested number of changes to include in the change batch.

### `pSyncKnowledge` [in]

The knowledge from the destination provider. This knowledge must be mapped by calling [ISyncKnowledge::MapRemoteToLocal](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-mapremotetolocal) on the source knowledge before it can be used for change enumeration.

### `ppSyncChangeBatch` [out]

Returns a change batch that contains item metadata for items that are not contained in *pSyncKnowledge*.

### `ppUnkDataRetriever` [out]

Returns an object that can be used to retrieve change data. It can be an [ISynchronousDataRetriever](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever) object or a provider-specific object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes** |  |

## Remarks

Be aware that *dwBatchSize* is a requested number only. A smaller or larger batch can be returned.

**Note** If there are no more changes to send after this batch, [ISyncChangeBatchBase::SetLastBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase) must be called on the returned change batch before **GetChangeBatch** is called again.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)
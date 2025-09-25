# ISyncChangeBatchBase::GetIsLastBatch

## Description

Gets a flag that indicates whether the changes in this change batch are the last batch of a synchronization session.

## Parameters

### `pfLastBatch` [out]

Returns a flag that indicates whether this batch is the last batch.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pfLastBatch* is **NULL**. |

## Remarks

When returning a change batch in response to the [IKnowledgeSyncProvider::GetChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-getchangebatch) method, the source provider must call [SetLastBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchangebatchbase-setlastbatch) if the change batch is the last batch of changes.

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)
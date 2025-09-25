# ISyncChangeBatchBase::SetLastBatch

## Description

Sets a flag that indicates there are no more changes to be enumerated in the synchronization session.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When returning a change batch in response to the [IKnowledgeSyncProvider::GetChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-iknowledgesyncprovider-getchangebatch) method, the source provider must call **SetLastBatch** if the change batch is the last batch of changes.

## See also

[IKnowledgeSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iknowledgesyncprovider)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)
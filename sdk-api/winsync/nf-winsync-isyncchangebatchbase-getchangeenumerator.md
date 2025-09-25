# ISyncChangeBatchBase::GetChangeEnumerator

## Description

Gets an [IEnumSyncChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumsyncchanges) object that enumerates the item changes in this change batch.

## Parameters

### `ppEnum` [out]

Returns an enumerator that contains the item changes in this change batch.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |

## See also

[IEnumSyncChanges Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumsyncchanges)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)
# ILoadChangeContext::GetSyncChange

## Description

Gets the change item for which the change data should be retrieved from the item store.

## Parameters

### `ppSyncChange` [out]

Returns the change item for which the change data should be retrieved from the item store.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INTERNAL_ERROR** | When an internal error occurs. |

## See also

[ILoadChangeContext Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iloadchangecontext)

[ISynchronousDataRetriever Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynchronousdataretriever)
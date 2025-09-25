# ISyncKnowledge2::GetLowestUncontainedId

## Description

Returns the lowest item ID that is not contained in this knowledge and that is contained in the specified knowledge.

## Parameters

### `piSyncKnowledge` [in]

The item ID that is returned in *pbItemId* is contained in *piSyncKnowledge*.

### `pbItemId` [in, out]

The lowest item ID that is contained in *piSyncKnowledge* and is not contained in this knowledge.

### `pcbItemIdSize` [in, out]

The number of bytes in *pbItemId*. Returns either the number of bytes that are required to retrieve the ID when *pbItemId* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | *piSyncKnowledge* is contained in this knowledge. In this situation, there is no uncontained item ID to return. |
| **E_INVALIDARG** | The ID format schema of *piSyncKnowledge* is not the same as the ID format schema of this knowledge. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pbItemId* is too small. In this situation, the required number of bytes is returned in *pcbItemIdSize*. |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)
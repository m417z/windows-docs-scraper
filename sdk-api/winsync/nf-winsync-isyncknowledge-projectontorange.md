# ISyncKnowledge::ProjectOntoRange

## Description

Gets the knowledge for the specified range of item IDs.

## Parameters

### `psrngSyncRange` [in]

 The range of item IDs to look up.

### `ppKnowledgeOut` [out]

Returns a knowledge object that contains only the range of item IDs specified by *psrngSyncRange*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[SYNC_RANGE Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_range)
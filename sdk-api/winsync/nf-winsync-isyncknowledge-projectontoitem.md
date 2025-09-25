# ISyncKnowledge::ProjectOntoItem

## Description

Gets the knowledge for the specified item.

## Parameters

### `pbItemId` [in]

The ID of the item to look up.

### `ppKnowledgeOut` [out]

Returns a knowledge object that contains only the item specified by *pbItemId*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)
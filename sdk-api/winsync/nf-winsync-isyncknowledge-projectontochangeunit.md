# ISyncKnowledge::ProjectOntoChangeUnit

## Description

Gets the knowledge for the specified change unit.

## Parameters

### `pbItemId` [in]

The ID of the item that contains the change unit to look up.

### `pbChangeUnitId` [in]

The ID of the change unit to look up.

### `ppKnowledgeOut` [out]

Returns a knowledge object that contains only the change unit specified by *pbChangeUnitId*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)
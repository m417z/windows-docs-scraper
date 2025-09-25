# ISyncChange::GetMadeWithKnowledge

## Description

Gets the made-with knowledge for this change.

## Parameters

### `ppMadeWithKnowledge` [out]

Returns the made-with knowledge for this change. The made-with knowledge for a change is typically the knowledge that the replica had when this change was made. This knowledge is only meaningful when the **ISyncChange** object represents a change from the source provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_CHANGE_NEEDS_KNOWLEDGE** | This item does not contain made-with knowledge. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)
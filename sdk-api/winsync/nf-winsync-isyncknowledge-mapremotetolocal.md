# ISyncKnowledge::MapRemoteToLocal

## Description

Converts a knowledge object from another replica into one that is compatible with the replica that owns this knowledge.

## Parameters

### `pRemoteKnowledge` [in]

A knowledge object that is owned by another replica.

### `ppMappedKnowledge` [out]

Returns the knowledge object, converted for use by the replica that owns this knowledge.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)
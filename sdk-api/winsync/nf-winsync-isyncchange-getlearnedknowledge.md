# ISyncChange::GetLearnedKnowledge

## Description

Gets the knowledge that a replica will learn when this change is applied to its item store.

## Parameters

### `ppLearnedKnowledge` [out]

Returns the knowledge that a replica will learn when this change is applied to its item store. This knowledge is valid only when the current knowledge of the replica contains the prerequisite knowledge of the change batch that contains this change. This knowledge is only meaningful when the **ISyncChange** object represents a change from the source provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | When  *pbCurrentReplicaId* is not the correct replica ID. |
| **SYNC_E_CHANGE_NEEDS_KNOWLEDGE** | When the change has not been added to a change batch group or if the change batch group has not been ended. |

## Remarks

**GetLearnedKnowledge** can be used by a provider that uses a custom change applier.

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)
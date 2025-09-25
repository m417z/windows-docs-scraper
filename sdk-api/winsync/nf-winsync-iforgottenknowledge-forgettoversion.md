# IForgottenKnowledge::ForgetToVersion

## Description

Updates the forgotten knowledge to reflect that all versions that are less than or equal to the specified version might have been forgotten, and that corresponding tombstones might have been deleted.

## Parameters

### `pKnowledge` [in]

The current knowledge of the replica that owns this forgotten knowledge object.

### `pVersion` [in]

The version of the tombstone that has been cleaned up.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## Remarks

When a replica cleans up the tombstone for an item, its associated provider must call this method and specify the version of the tombstone that was removed.

## See also

[IForgottenKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iforgottenknowledge)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)
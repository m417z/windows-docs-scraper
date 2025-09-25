# IReplicaKeyMap::LookupReplicaKey

## Description

Gets the replica key that corresponds to the specified replica ID.

## Parameters

### `pbReplicaId` [in]

The replica ID to look up.

### `pdwReplicaKey` [out]

Returns the replica key that corresponds to *pbReplicaId*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** |  |
| **SYNC_E_ID_FORMAT_MISMATCH** | When *pbReplicaId* is not in the format that is specified by the ID format schema of the provider. |
| **SYNC_E_REPLICA_NOT_FOUND** | When *pbReplicaId* is not found. |

## See also

[IReplicaKeyMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ireplicakeymap)
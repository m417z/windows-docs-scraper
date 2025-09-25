# IConstructReplicaKeyMap::FindOrAddReplica

## Description

Adds entries to or finds entries in an **IReplicaKeyMap** object.

## Parameters

### `pbReplicaId` [in]

The ID of the replica to add or find.

### `pdwReplicaKey` [out]

The key of the replica in the map. If an entry for *pbReplicaId* does not exist in the map, an entry is created and a new key is assigned to it.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_ID_FORMAT_MISMATCH** | *pbReplicaId* is not of the format that the provider specified. |

## See also

[IConstructReplicaKeyMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iconstructreplicakeymap)
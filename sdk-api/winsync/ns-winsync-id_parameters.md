# ID_PARAMETERS structure

## Description

Represents the format schema for the group of IDs that are used to identify entities in a synchronization session.

## Members

### `dwSize`

The number of bytes in the **ID_PARAMETERS** structure.

### `replicaId`

The ID format that is expected for replica IDs.

### `itemId`

The ID format that is expected for item IDs.

### `changeUnitId`

The ID format that is expected for change unit IDs.

## Remarks

To obtain ID parameters, both providers are queried through a call to [ISyncProvider::GetIdParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncprovider-getidparameters). These ID parameters are then compared to verify that both providers use the same ID schema. If this verification fails, the synchronization session is not created, and an error code is returned.

## See also

[ID_PARAMETER_PAIR Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameter_pair)

[ISyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider)

[Windows Sync Structures](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-structures)
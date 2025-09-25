# ISyncChange::GetCreationVersion

## Description

Gets the creation version of the changed item.

## Parameters

### `pbCurrentReplicaId` [in]

The ID of the replica that owns this change. The ID format must match the format that is specified by the [ID_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters) property of the provider.

### `pVersion` [out]

Returns the creation version of the item.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** | *pbCurrentReplicaId* is not the correct replica ID. |
| **SYNC_E_ID_FORMAT_MISMATCH** | *pbCurrentReplicaId* is not in the format that is specified by the ID format schema of the provider. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)

[SYNC VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)
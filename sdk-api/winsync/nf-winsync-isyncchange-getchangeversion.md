# ISyncChange::GetChangeVersion

## Description

Gets the version that is associated with this change.

## Parameters

### `pbCurrentReplicaId` [in]

The ID of the replica that owns this change. The ID format must match the format that is specified by the [ID_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters) property of the provider.

### `pVersion` [out]

Returns the change version of the item.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** | *pbCurrentReplicaId* is not the correct replica ID. |
| **SYNC_E_ITEM_HAS_NO_VERSION_DATA** | The item has been forgotten. |
| **SYNC_E_ID_FORMAT_MISMATCH** | *pbCurrentReplicaId* is not in the format that is specified by the ID format schema of the provider. |
| **SYNC_E_ITEM_HAS_CHANGE_UNITS** | The item has change units. |

## See also

[ISyncChange Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchange)

[SYNC VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)
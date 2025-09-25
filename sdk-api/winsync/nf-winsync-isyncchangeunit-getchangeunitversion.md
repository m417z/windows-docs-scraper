# ISyncChangeUnit::GetChangeUnitVersion

## Description

Gets the version for the change unit change.

## Parameters

### `pbCurrentReplicaId` [in]

The ID of the replica that originated the change to retrieve.

### `pVersion` [out]

Returns the version of the change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_INVALIDARG** | *pbCurrentReplicaId* is not the correct replica ID. |

## See also

[ISyncChangeUnit Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangeunit)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)
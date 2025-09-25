# ISyncChangeBuilder::AddChangeUnitMetadata

## Description

Adds change unit metadata to an item change.

## Parameters

### `pbChangeUnitId` [in]

The ID of the change unit to add to the item change.

### `pChangeUnitVersion` [in]

The version of the change unit change to add to the item change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |
| **SYNC_E_ID_FORMAT_MISMATCH** | The format of the change unit ID that is contained in *pbChangeUnitId* does not match the format that is specified by the ID format schema of the provider. |
| **SYNC_E_INVALID_OPERATION** | The item change to which to add this change unit to has **SYNC_CHANGE_FLAG_DELETE** or **SYNC_CHANGE_FLAG_DOES_NOT_EXIST** set as one of its flags. |

## See also

[ISyncChangeBuilder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebuilder)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)
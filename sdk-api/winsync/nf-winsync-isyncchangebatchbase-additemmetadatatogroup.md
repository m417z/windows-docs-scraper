# ISyncChangeBatchBase::AddItemMetadataToGroup

## Description

Adds a specified item change to the group that is currently open.

## Parameters

### `pbOwnerReplicaId` [in]

The replica ID of the replica where *pChangeVersion* and *pCreationVersion* are valid. The ID format must match the format that is specified by the [ID_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters) structure of the provider.

### `pbItemId` [in]

The ID of the item. The ID format must match the format that is specified by the [ID_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters) structure of the provider.

### `pChangeVersion` [in]

The version of this change.

### `pCreationVersion` [in]

The creation version of the item.

### `dwFlags` [in]

Flags that specify the state of the item change. For the flag values, see [ISyncChange::GetFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncchange-getflags).

### `dwWorkForChange` [in]

The work estimate for the change. This value is used during change application to report completed work to the application.

### `ppChangeBuilder` [in, out]

Returns an object that can be used to add change unit information to the change.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwFlags* contains a flag value that is not valid. |
| **SYNC_E_INVALID_OPERATION** | No group is open or an empty group was previously added to the batch. |
| **SYNC_E_RANGE_OUT_OF_ORDER** | An ordered group is open and *pbItemId* is less than the item ID of the previous item that was added to the group, or less than the item ID that was specified when the group was opened. |
| **SYNC_E_CHANGE_BATCH_IS_READ_ONLY** | The **ISyncChangeBatchBase** object has been sent to a change applier or to the synchronization session. |

## See also

[ID_PARAMETERS Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)

[SYNC_VERSION Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-sync_version)
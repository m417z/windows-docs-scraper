# IVssFileShareSnapshotProvider::DeleteSnapshots

## Description

Deletes specific snapshots, or all snapshots in a specified snapshot set.

## Parameters

### `SourceObjectId` [in]

Identifier of the shadow copy or shadow copy set to be deleted.

### `eSourceObjectType` [in]

Type of the object to be deleted. The value of this parameter is VSS_OBJECT_SNAPSHOT or VSS_OBJECT_SNAPSHOT_SET.

### `bForceDelete` [in]

If the value of this parameter is **TRUE**, the provider will do everything possible to delete the shadow copy or shadow copies in a shadow copy set. If it is **FALSE**, no additional effort will be made.

### `plDeletedSnapshots` [out]

Pointer to a variable that receives the number of shadow copies that were deleted.

### `pNondeletedSnapshotID` [out]

If an error occurs, this parameter receives a pointer to the identifier of the first shadow copy that could not be deleted. Otherwise, it points to GUID_NULL.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copies were successfully deleted. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copies were not found. |
| **VSS_E_PROVIDER_VETO** | Provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

The VSS coordinator calls this method as part of the snapshot auto-release process. The method is also called in response to requester driven delete operations.

## See also

[IVssFileShareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssfilesharesnapshotprovider)
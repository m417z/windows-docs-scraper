# IVssBackupComponents::DeleteSnapshots

## Description

The **DeleteSnapshots** method deletes
one or more shadow copies or a shadow copy set.

## Parameters

### `SourceObjectId` [in]

Identifier of the shadow copy or a shadow copy set to be deleted.

### `eSourceObjectType` [in]

Type of the object on which all shadow copies will be deleted. The value of this parameter is
**VSS_OBJECT_SNAPSHOT** or **VSS_OBJECT_SNAPSHOT_SET**.

### `bForceDelete` [in]

If the value of this parameter is **TRUE**, the provider will do everything possible to delete the shadow copy or
shadow copies in a shadow copy set. If it is **FALSE**, no additional effort will be made.

### `plDeletedSnapshots` [out]

Number of deleted shadow copies.

### `pNondeletedSnapshotID` [out]

If an error occurs, the value of this parameter is the identifier of the first shadow copy that could not be
deleted. Otherwise, it is **GUID_NULL**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copies were successfully deleted. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy does not exist. |
| **VSS_E_PROVIDER_VETO** | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | Unexpected provider error. The error code is logged in the error log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

Multiple shadow copies in a shadow copy set are deleted sequentially. If an error occurs during one of these
individual deletions,
**DeleteSnapshots** will return
immediately; no attempt will be made to delete any remaining shadow copies. The
[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) of the undeleted shadow copy is
returned in *pNondeletedSnapshotID*.

The requester is responsible for serializing the delete shadow copy operation.

During a backup, shadow copies are automatically released as soon as the
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) instance is released. In this
case, it is not necessary to explicitly delete shadow copies.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::StartSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-startsnapshotset)

[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)
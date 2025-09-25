# IVssComponent::GetFileRestoreStatus

## Description

The
**GetFileRestoreStatus** method returns the status of a completed attempt to restore all the files of a selected component or component set as a
[VSS_FILE_RESTORE_STATUS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_file_restore_status) enumeration. (See
[Working with Selectability and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for information on selecting components.)

Either a writer or a requester can call this method.

## Parameters

### `pStatus` [out]

The address of a caller-allocated variable that receives a
[VSS_FILE_RESTORE_STATUS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_file_restore_status) enumeration value that specifies whether all files were successfully restored.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The method was not called as part of a restore operation. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

This method should be called only following a
[PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event.

The status returned is undefined if this method is applied to a component that has not been selected for restore by being added to the Backup Components via
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[VSS_FILE_RESTORE_STATUS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_file_restore_status)
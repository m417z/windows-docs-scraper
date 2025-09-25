# IVssComponent::GetBackupSucceeded

## Description

The
**GetBackupSucceeded** method returns the status of a complete attempt at backing up all the files of a selected component or component set as a
[VSS_FILE_RESTORE_STATUS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_file_restore_status) enumeration. (See
[Working with Selectability and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for information on selecting components.)

Either a writer or a requester can call this method.

## Parameters

### `pbSucceeded` [out]

The address of a caller-allocated variable that receives **true** if the backup was successful, or **false** otherwise.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | The backup success state is undefined because the method was called prior to a [BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

This method should not be called prior to a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event, and is designed for use in an implementation of the event handler
[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete).

## See also

[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)
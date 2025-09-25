# IVssBackupComponents::SetBackupSucceeded

## Description

The
**SetBackupSucceeded** method indicates whether the backup of the specified component of a specific writer was successful.

## Parameters

### `instanceId` [in]

Globally unique identifier (GUID) of the writer instance.

### `writerId` [in]

Globally unique identifier (GUID) of the writer class.

### `ct` [in]

Type of the component. See
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for the possible values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component.

The string cannot be **NULL** and should contain the same component name as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

### `bSucceded` [in]

Set this parameter to **true** if the component was successfully backed up, or **false** otherwise.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the backup succeeded state. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The backup component does not exist. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

When working in component mode (when
[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate) is called with its select components argument set to **true**), writers check the state of each components backup using
[IVssComponent::GetBackupSucceeded](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupsucceeded). Therefore, a well-behaved backup application (requester) must call
**SetBackupSucceeded** after each component has been processed and prior to calling
[IVssBackupComponents::BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete).

Do not call this method if the call to [IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset) failed. For more information about how requesters use **DoSnapshotSet**, **SetBackupSucceeded**, and [BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) in a backup operation, see [Overview of Pre-Backup Tasks](https://learn.microsoft.com/windows/desktop/VSS/overview-of-pre-backup-tasks) and [Overview of Actual Backup Of Files](https://learn.microsoft.com/windows/desktop/VSS/overview-of-actual-backup-of-files).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete)

[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)
# IVssBackupComponents::SetPreviousBackupStamp

## Description

The
**SetPreviousBackupStamp** method sets the backup stamp of an earlier backup operation, upon which a differential or incremental backup operation will be based.

The method can be called only during a backup operation.

## Parameters

### `writerId` [in]

Writer identifier.

### `ct` [in]

Type of the component. See
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for the possible values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The logical path can be **NULL**.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component.

The string cannot be **NULL** and should contain the same component name as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

### `wszPreviousBackupStamp` [in]

The backup stamp to be set.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the previous backup time stamp. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The backup component does not exist. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

This method should be called before
[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup).

Only requesters can call this method.

The backup stamp set by
**SetPreviousBackupStamp** applies to all files in the component and any nonselectable subcomponents it has.

Requesters merely store the backup stamps in the Backup Components Document. They cannot make direct use of the backup stamps, do not know their format, and do not know how to generate them.

Therefore, the value set with
**SetPreviousBackupStamp** should either be retrieved from the stored Backup Components Document of an earlier backup operation (using
[IVssComponent::GetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupstamp) for the correct component), or from information stored by the requester into its own internal records.

A writer will then obtain this value (using
[IVssComponent::GetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpreviousbackupstamp)) and using it will be able to mark the appropriate files for participation in an incremental or differential backup.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)
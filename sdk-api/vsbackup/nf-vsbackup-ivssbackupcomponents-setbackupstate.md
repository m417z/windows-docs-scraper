# IVssBackupComponents::SetBackupState

## Description

The
**SetBackupState** method defines an overall configuration for a backup operation.

## Parameters

### `bSelectComponents` [in]

Indicates whether a backup or restore operation will be in component mode.

Operation in component mode supports selectively backing up designated individual components (which can allow their exclusion), or only supports backing up all files and components on a volume.

The Boolean is **true** if the operation will be conducted in component mode and **false** if not.

### `bBackupBootableSystemState` [in]

Indicates whether a bootable system state backup is being performed.

### `backupType` [in]

A
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) enumeration value indicating the type of backup to be performed.

### `bPartialFileSupport` [in]

Optional. If the value of this parameter is **true**, partial file support is enabled. The default value for this argument is **false**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the backup state. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Applications must call
**SetBackupState** prior to calling
[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type)
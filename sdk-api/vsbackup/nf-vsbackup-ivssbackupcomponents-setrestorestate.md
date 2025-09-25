# IVssBackupComponents::SetRestoreState

## Description

The
**SetRestoreState** method defines an overall configuration for a restore operation.

## Parameters

### `restoreType` [in]

A
[VSS_RESTORE_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_restore_type) enumeration value indicating the type of restore to be performed.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the backup state. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a backup operation, or this method has not been called within the correct sequence. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Typically, most restore operations will not need to override the default restore type (VSS_RTYPE_UNDEFINED). Writers should treat this restore type as if it were VSS_RTYPE_BY_COPY.

If applications need to call
**SetRestoreState**, it should be called prior to calling
[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore).

If
**SetRestoreState** is not called prior to [IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore), the default restore state () is used.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate)

[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type)

[VSS_RESTORE_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_restore_type)
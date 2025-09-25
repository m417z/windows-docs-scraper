# IVssBackupComponents::AbortBackup

## Description

The
**AbortBackup** method notifies VSS that a backup operation was terminated.

This method must be called if a backup operation terminates after the creation of a shadow copy set with
[IVssBackupComponents::StartSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-startsnapshotset) and before
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset) returns.

If
**AbortBackup** is called and no shadow copy or backup operations are underway, it is ignored.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The query operation was successful. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**AbortBackup** generates an [Abort](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-a) event, which is handled by each instance of each writer through the
[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort) method.

## See also

[IVssAsync::Cancel](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-cancel)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete)

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)

[IVssBackupComponents::StartSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-startsnapshotset)
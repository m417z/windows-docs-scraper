# IVssBackupComponents::BackupComplete

## Description

The
**BackupComplete** method causes VSS to generate a
**BackupComplete** event, which signals writers
that the backup process has completed.

## Parameters

### `ppAsync` [out]

Doubly indirect pointer to an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) instance.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an instance of the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface. Refer to [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) for the valid values returned by the *pHrResult* parameter. |
| **E_INVALIDARG** | *ppAsync* does not point to a valid pointer; that is, it is **NULL**. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_WRITER_ERROR** | An unexpected error occurred during communication with writers. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

When working in component mode ([IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate) was called with a select components argument of **TRUE**), writers can determine the success or failure of the backup of any component explicitly included in the Backup Components Document components by using
[IVssComponent::GetBackupSucceeded](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupsucceeded). Therefore, a well-behaved backup application (requester) must call
[IVssBackupComponents::SetBackupSucceeded](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupsucceeded) after each component has been processed and prior to calling
**BackupComplete**.

Do not call this method if the call to [IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset) failed. For more information about how requesters use **DoSnapshotSet**, [SetBackupSucceeded](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupsucceeded), and **BackupComplete** in a backup operation, see [Overview of Pre-Backup Tasks](https://learn.microsoft.com/windows/desktop/VSS/overview-of-pre-backup-tasks) and [Overview of Actual Backup Of Files](https://learn.microsoft.com/windows/desktop/VSS/overview-of-actual-backup-of-files).

This operation is asynchronous. The caller can use the
[QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) interface method in the returned
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface to determine the status of the notification.

After calling **BackupComplete**, requesters must call [GatherWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwriterstatus) to cause the writer session to be set to a completed state.

**Note** This is only necessary on Windows Server 2008 with Service Pack 2 (SP2) and earlier.

The backup application can choose to abort the backup at any time after the shadow copy is created by calling
[IVssAsync::Cancel](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-cancel).

The calling application is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the resources held by the returned
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) when it is no longer needed.

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssAsync::Cancel](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-cancel)

[IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate)

[IVssBackupComponents::SetBackupSucceeded](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupsucceeded)
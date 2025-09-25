# IVssBackupComponents::DoSnapshotSet

## Description

Commits all
shadow copies in this set simultaneously.

## Parameters

### `ppAsync` [out]

A
doubly indirect pointer to the required [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) asynchronous
interface. This is used to query the method execution state and to retrieve the final error code.

## Return value

The following are the valid return codes for this method. These error codes may be returned from this method, or
from the [QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method on the
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface returned in the
*ppAsync* parameter.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an instance of the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface. See [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) for the valid values returned by the *pHrResult* parameter. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | *ppAsync* does not point to a valid pointer; that is, it is **NULL**. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object has not been initialized or the prerequisite calls for a given shadow copy context have not been made prior to calling [DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset). |
| **VSS_E_INSUFFICIENT_STORAGE** | The system or provider has insufficient storage space. If possible delete any old or unnecessary persistent shadow copies and try again. This error code is only returned via the [QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method on the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface returned in the *ppAsync* parameter. |
| **VSS_E_FLUSH_WRITES_TIMEOUT** | The system was unable to flush I/O writes. This can be a transient problem. It is recommended to wait ten minutes and try again, up to three times. |
| **VSS_E_HOLD_WRITES_TIMEOUT** | The system was unable to hold I/O writes. This can be a transient problem. It is recommended to wait ten minutes and try again, up to three times. |
| **VSS_E_NESTED_VOLUME_LIMIT** | The specified volume is nested too deeply to participate in the VSS operation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This return code is not supported. |
| **VSS_E_PROVIDER_VETO** | The provider was unable to perform the request at this time. This can be a transient problem. It is recommended to wait ten minutes and try again, up to three times. This error code is only returned via the [QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method on the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface returned in the *ppAsync* parameter. |
| **VSS_E_REBOOT_REQUIRED** | The provider encountered an error that requires the user to restart the computer. <br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **VSS_E_TRANSACTION_FREEZE_TIMEOUT** | The system was unable to freeze the Distributed Transaction Coordinator (DTC) or the Kernel Transaction Manager (KTM).<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **VSS_E_TRANSACTION_THAW_TIMEOUT** | The system was unable to thaw the Distributed Transaction Coordinator (DTC) or the Kernel Transaction Manager (KTM).<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | The provider returned an unexpected error code. This can be a transient problem. It is recommended to wait ten minutes and try again, up to three times. This error code is only returned via the [QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method on the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface returned in the *ppAsync* parameter. |

## Remarks

The caller is responsible for releasing the
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface.

This method cannot be called for a virtual hard disk (VHD) that is nested inside another VHD.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** VHDs are not supported.

For information on how to use
**IVssBackupComponents::DoSnapshotSet** to
create a standard backup shadow copy, see
[Overview of Pre-Backup Tasks](https://learn.microsoft.com/windows/desktop/VSS/overview-of-pre-backup-tasks) and
[Simple Shadow Copy Creation for Backup](https://learn.microsoft.com/windows/desktop/VSS/simple-shadow-copy-creation-for-backup).
For information on how the method is used under different VSS contexts, see
[Implementation Details for
Creating Shadow Copies](https://learn.microsoft.com/windows/desktop/VSS/implementation-details-for-creating-shadow-copies).

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent)

[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset)

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)

[IVssBackupComponents::StartSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-startsnapshotset)
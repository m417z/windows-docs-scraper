# IVssBackupComponents::PreRestore

## Description

The
**PreRestore** method will cause VSS to generate a
[PreRestore](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event, signaling writers to prepare for an upcoming restore operation.

## Parameters

### `ppAsync` [out]

Doubly indirect pointer to an
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object containing status data for the signaled event.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an instance of the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface. Refer to [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) for the error codes returned in the *pHrResult* parameter. |
| **E_INVALIDARG** | The *ppAsync* parameter does not point to a valid pointer; that is, it is **NULL**. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller is responsible for releasing the
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer.

Special consideration should be given to EFI systems when the requester has selected the Automated System Recovery (ASR) writer for restore. If you are restoring to a disk that contains the EFI partition, and one of the following conditions exists, you must first clean the disk by calling the [IVdsAdvancedDisk::Clean](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-clean) method:

* You are restoring to an EFI system disk whose partitioning has changed since the last ASR backup.
* You are restoring to a different physical drive than the one from which the backup was taken.

Failure to perform this disk-cleaning step may result in unexpected results during [PreRestore](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p).

For more information about the ASR writer, see [In-Box VSS Writers](https://learn.microsoft.com/windows/desktop/VSS/in-box-vss-writers).

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)
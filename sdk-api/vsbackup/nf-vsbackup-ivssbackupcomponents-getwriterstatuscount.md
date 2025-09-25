# IVssBackupComponents::GetWriterStatusCount

## Description

The
**GetWriterStatusCount** method returns the number of writers with status.

## Parameters

### `pcWriters` [out]

The number of writers with status.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the number of writers with status. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

A requester must call the asynchronous operation
[IVssBackupComponents::GatherWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwriterstatus) and wait for it to complete prior to calling **IVssBackupComponents::GetWriterStatusCount**.

The number of writers returned by
**GetWriterStatusCount** should always be the same as that returned by
[IVssBackupComponents::GetWriterMetadataCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritermetadatacount).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::GatherWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwriterstatus)

[IVssBackupComponents::GetWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwriterstatus)

[VSS_WRITER_STATE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_writer_state)
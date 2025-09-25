# IVssAsync::QueryStatus

## Description

The **QueryStatus** method queries the status of an
asynchronous operation.

## Parameters

### `pHrResult` [out]

The status of the asynchronous operation that returned the current
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object.

All calls to **QueryStatus** for all
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) objects support the following status codes.

| Value | Meaning |
| --- | --- |
| **VSS_S_ASYNC_CANCELLED** | The asynchronous operation was canceled by a previous call to [IVssAsync::Cancel](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-cancel). |
| **VSS_S_ASYNC_FINISHED** | The asynchronous operation was completed successfully. |
| **VSS_S_ASYNC_PENDING** | The asynchronous operation is still running. |

Additional return values can be returned, but depend on the return codes of the method that initially
returned the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object.

### `pReserved` [out]

The value of this parameter should be **NULL**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The query operation was successful. |
| **E_ACCESSDENIED** | The query operation failed because the user did not have the correct privileges. |
| **E_INVALIDARG** | The pointer to the variable used to hold the *pHrResult* return value is **NULL** or is not a valid memory location. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

In the event of an error during the course of an asynchronous operation,
**QueryStatus** will return the same error code as the
method that initially returned the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object.

To obtain a complete list of return values for an
**IVssAsync::QueryStatus** object returned by a
specific method, see the error codes documented for that method.

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)

[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata)

[IVssBackupComponents::GatherWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwriterstatus)

[IVssBackupComponents::ImportSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-importsnapshots)

[IVssBackupComponents::PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore)

[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)
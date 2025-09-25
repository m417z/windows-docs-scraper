# IVssBackupComponents::GatherWriterMetadata

## Description

The
**GatherWriterMetadata** method prompts each writer to send the metadata they have collected. The method will generate an [Identify](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-i) event to communicate with writers.

## Parameters

### `pAsync` [out]

Doubly indirect pointer to an
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object containing the writer metadata.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an instance of the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface. See [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) for the valid values returned by the *pHrResult* parameter. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | *ppAsync* does not point to a valid pointer; that is, it is **NULL**. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_WRITER_INFRASTRUCTURE** | The writer infrastructure is not operating properly. Check that the Event Service and VSS have been started, and check for errors associated with those services in the error log. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller is responsible for releasing the
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface.

**GatherWriterMetadata** should be called only once during the lifetime of a given
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) object.

**GatherWriterMetadata** generates an Identify event, which is handled by each instance of each writer through the
[CVssWriter::OnIdentify](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onidentify) method, which is used to fill the Writer Metadata Document.

## See also

[CVssWriter::OnIdentify](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onidentify)

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)
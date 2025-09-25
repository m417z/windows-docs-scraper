# IVssBackupComponents::GetWriterMetadata

## Description

The
**GetWriterMetadata** method returns the metadata for a specific writer running on the system.

## Parameters

### `iWriter` [in]

Index of the writer whose metadata is to be retrieved. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of writers on the current system. The value of *n* is returned by
[IVssBackupComponents::GetWriterMetadataCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritermetadatacount).

### `pidInstance` [out]

Pointer to the instance identifier of the writer that collected the metadata.

### `ppMetadata` [out]

Doubly indirect pointer to the instance of the
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object that contains the returned metadata.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) interface object. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

A requester must call the asynchronous operation
[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) and wait for it to complete prior to calling **GetWriterMetadata**.

Although
[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) must be called prior to either a restore or backup operation,
**GetWriterMetadata** is not typically called for restores.

Component information retrieved (during backup operations) using
[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent), where the
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) interface has been returned by
**GetWriterMetadata**, comes from the Writer Metadata Document of a live writer process.

This is in contrast to the information returned by
[GetWriterComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritercomponents) (during restore operations), which was stored in the Backup Components Document by calls to
[AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

When the caller of this method is finished accessing the metadata, it must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent)

[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata)

[IVssBackupComponents::GetWriterComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritercomponents)

[IVssBackupComponents::GetWriterMetadataCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritermetadatacount)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)
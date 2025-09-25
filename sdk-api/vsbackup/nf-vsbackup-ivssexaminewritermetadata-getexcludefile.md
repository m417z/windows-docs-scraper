# IVssExamineWriterMetadata::GetExcludeFile

## Description

The
**GetExcludeFile** method obtains information about files that have been explicitly excluded from backup for a given writer.

## Parameters

### `iFile` [in]

Index for an excluded file set. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of file sets explicitly excluded from the components of a given writer. The value of *n* is returned by
[IVssExamineWriterMetadata::GetFileCounts](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getfilecounts).

### `ppFiledesc` [out]

Doubly indirect pointer to an
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object containing the file element information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) interface. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The file set specified for exclusion does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

For more information on excluding files, see
[Exclude File List Specification](https://learn.microsoft.com/windows/desktop/VSS/writer-metadata-document-contents).

The caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the resources of the returned
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object.

## See also

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[IVssExamineWriterMetadata::GetFileCounts](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getfilecounts)
# IVssExamineWriterMetadata::GetComponent

## Description

The
**GetComponent** method obtains a Writer Metadata Document for a specified backup component.

## Parameters

### `iComponent` [in]

Index for a component. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of components supported by a given writer. The value of *n* is returned by
[IVssExamineWriterMetadata::GetFileCounts](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getfilecounts).

### `ppComponent` [out]

Doubly indirect pointer to a
[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) object containing the component information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) interface. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified component does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the resources of the returned
[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) object.

## See also

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[IVssExamineWriterMetadata::GetFileCounts](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getfilecounts)

[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent)
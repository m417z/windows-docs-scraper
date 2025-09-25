# IVssExamineWriterMetadata::LoadFromXML

## Description

The
**LoadFromXML** method loads an XML document that contains a writer's metadata document into an
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) interface.

## Parameters

### `bstrXML` [in]

String that contains an XML document that represents a writer's metadata document.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the *bstrXML* parameter value to the XML document. |
| **S_FALSE** | The XML document could not be loaded. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

This method is used at restore time to load writer metadata that was saved by
[IVssExamineWriterMetadata::SaveAsXML](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-saveasxml) at the time of the backup operation.

Users should not tamper with this metadata document.

## See also

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[IVssExamineWriterMetadata::SaveAsXML](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-saveasxml)
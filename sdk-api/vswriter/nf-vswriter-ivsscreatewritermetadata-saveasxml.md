# IVssCreateWriterMetadata::SaveAsXML

## Description

The
**SaveAsXML** method saves the Writer Metadata Document that contains a writer's state information to a specified string.

## Parameters

### `pbstrXML` [in]

Pointer to a string to be used to store the Writer Metadata Document that contains a writer's state information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## See also

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)
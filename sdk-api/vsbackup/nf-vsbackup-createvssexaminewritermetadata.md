# CreateVssExamineWriterMetadata function

## Description

The **CreateVssExamineWriterMetadata**
function creates an
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object.

**Note** This function is exported as **CreateVssExamineWriterMetadataInternal**, but you should call **CreateVssExamineWriterMetadata**, not **CreateVssExamineWriterMetadataInternal**.

## Parameters

### `bstrXML` [in]

An XML string containing a Writer Metadata Document with which to initialize the returned
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object.

### `ppMetadata` [out]

A variable that receives an
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)
interface pointer to the object.

## Return value

The return values listed here are in addition to the normal COM HRESULTs that may be returned at any time
from the function.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) interface. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | Out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document passed in the *bstrXML* parameter is not valid—that is, either it is not a correctly formed XML string or it does not match the schema. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

To save a copy of a writer’s Writer Metadata Document into an XML string to pass in the *bstrXML* parameter, use the [IVssExamineWriterMetadata::SaveAsXML](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-saveasxml) method.

To retrieve the latest version of a writer’s Writer Metadata Document, use the [IVssBackupComponents::GetWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritermetadata) method.

To load a writer metadata document into an existing [IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object, use the [IVssExamineWriterMetadata::LoadFromXML](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-loadfromxml) method.

Users should not attempt to modify the contents of the Writer Metadata Document.

The calling application is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the
resources held by
the [IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object when the object
is no longer needed.

## See also

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)
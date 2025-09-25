# IVssExamineWriterMetadata::GetIdentity

## Description

The
**GetIdentity** method obtains basic information about a specific writer instance.

## Parameters

### `pidInstance` [out]

The address of a caller-allocated variable that receives the instance identifier of the writer.

### `pidWriter` [out]

The address of a caller-allocated variable that receives the class identifier of the writer.

### `pbstrWriterName` [out]

The address of a caller-allocated variable that receives a string that contains the name of the writer.

### `pUsage` [out]

The address of a caller-allocated variable that receives a
[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type) enumeration value that specifies how the data managed by the writer is used on the host system.

### `pSource` [out]

The address of a caller-allocated variable that receives a
[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type) enumeration value that specifies the type of data managed by the writer.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the identity information. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller must free the memory held by the *pbstrWriterName* parameter by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

An
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) interface might be from stored writer state information (created by a call to
[CreateVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-createvssexaminewritermetadata)). If this is the case, then the following are true:

* *pidInstance* may not mean anything in terms of live writers.
* If *pidWriter* does not match the writer class of any live writer, a requester should not use that writer's components.

## See also

[CreateVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-createvssexaminewritermetadata)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type)

[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type)
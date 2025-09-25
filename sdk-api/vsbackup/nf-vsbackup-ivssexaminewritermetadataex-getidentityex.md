# IVssExamineWriterMetadataEx::GetIdentityEx

## Description

The **GetIdentityEx** method obtains the writer instance name and other basic information about a specific writer instance.

## Parameters

### `pidInstance` [out]

Globally unique identifier (GUID) of the writer instance.

### `pidWriter` [out]

GUID of the writer class.

### `pbstrWriterName` [out]

Pointer to a string specifying the name of the writer.

### `pbstrInstanceName` [out]

Pointer to a string specifying the writer instance name.

### `pUsage` [out]

Pointer to a
[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type) enumeration value indicating how the data managed by the writer is used on the host system.

### `pSource` [out]

Pointer to a
[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type) enumeration value indicating the type of data managed by the writer.

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

This method is identical to the [IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity) method except for the *pbstrInstanceName* parameter.

The *pbstrInstanceName* parameter is the writer instance name that was specified during writer initialization by [CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize).

The writer instance name is useful for writers that support running multiple writer instances with the same writer class ID on a single computer. The writer instance name can be used to identify the specific instance. Therefore, the writer must make the instance name unique within the writer class. Also, the writer instance name is expected to persist between backup and restore, and it is used by VSS to correctly restore multiple-instance writers.

The caller must free the memory held by the *pbstrWriterName* and *pbstrInstanceName* parameters by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

An
[IVssExamineWriterMetadataEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadataex) interface might be from stored writer state information (created by a call to
[CreateVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-createvssexaminewritermetadata)). If this is the case, then the following are true:

* *pidInstance* may not mean anything in terms of live writers.
* If *pidWriter* does not match the writer class of any live writer, a requester should not use that writer's components.

## See also

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[IVssExamineWriterMetadataEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadataex)
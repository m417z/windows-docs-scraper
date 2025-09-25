# IVssExamineWriterMetadataEx2::GetVersion

## Description

Obtains the version information for a writer application.

## Parameters

### `pdwMajorVersion` [out]

A pointer to the major version of the writer application.

### `pdwMinorVersion` [out]

A pointer to the minor version of the writer application.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer version information was successfully returned. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The **GetVersion** method returns nonzero results only if the writer was initialized by calling the [CVssWriterEx::InitializeEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex-initializeex) method and explicit version information was specified. If the writer is initialized by calling the [CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize) method, or if no version information was specified in the call to the **CVssWriterEx::InitializeEx** method, the **GetVersion** method returns zero in the *pdwMajorVersion* and *pdwMinorVersion* parameters.

## See also

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[CVssWriterEx::InitializeEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex-initializeex)

[IVssExamineWriterMetadataEx2](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadataex2)
# IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotFile

## Description

Obtains information about [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) that have been explicitly excluded from a given shadow copy.

## Parameters

### `iFile` [in]

An index for an excluded [file set](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f). The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of *file sets* explicitly excluded from a given shadow copy. The value of *n* is returned by
the **IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotCount** method.

### `ppFiledesc` [out]

A doubly indirect pointer to an
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object containing the file element information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The pointer to an [IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) interface was successfully returned. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller is responsible for calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to release the resources of the returned
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object.

The **GetExcludeFromSnapshotFile** method is intended to report information about [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) excluded from a shadow copy. Requesters should not exclude files from backup based on the information returned by this method.

## See also

[IVssCreateWriterMetadataEx::AddExcludeFilesFromSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadataex-addexcludefilesfromsnapshot)

[IVssExamineWriterMetadataEx2](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadataex2)

[IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex2-getexcludefromsnapshotfile)
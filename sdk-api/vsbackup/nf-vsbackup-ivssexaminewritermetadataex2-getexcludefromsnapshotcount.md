# IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotCount

## Description

Obtains the number of [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) that have been explicitly excluded from a given shadow copy.

## Parameters

### `pcExcludedFromSnapshot` [out]

A pointer to the number of [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) explicitly excluded from the shadow copy.

## Return value

The following are the valid return codes for this method.

| Return code | Description |
| --- | --- |
| **S_OK** | The number of [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) was successfully returned. |
| **E_INVALIDARG** | The *pcExcludedFromSnapshot* parameter was **NULL**. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## See also

[IVssCreateWriterMetadataEx::AddExcludeFilesFromSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadataex-addexcludefilesfromsnapshot)

[IVssExamineWriterMetadataEx2](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadataex2)

[IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex2-getexcludefromsnapshotfile)
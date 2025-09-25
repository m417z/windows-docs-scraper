# IVssWMFiledesc::GetBackupTypeMask

## Description

The **GetBackupTypeMask** method
returns the file backup specification for the files specified by the current file descriptor as a bit mask (or
bitwise OR) of [VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type) values.
This information indicates if the files are to be evaluated by their writer for participation in various specific
types of backup operations (or if they will participate in an incremental or differential backups).

## Parameters

### `pdwTypeMask`

Pointer to a **DWORD** containing a bit mask (or bitwise OR) of
[VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type) values indicating
the file backup specification for the file or file set described by the current
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) interface.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the filespec information. |
| **E_INVALIDARG** | The *pdwTypeMask* variable points to a **NULL** region of memory. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

A file backup specification is specified by a writer when it adds a file specification to a component using the
[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles) method.

## See also

[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles)

[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles)

[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup)

[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc)

[VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type)
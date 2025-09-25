# IVssComponent::AddDifferencedFilesByLastModifyTime

## Description

The
**AddDifferencedFilesByLastModifyTime**
method is used by a writer to indicate that a file set (a specified file or files) should be evaluated against a
last modification time stamp for inclusion in a time stamped incremental or differential backup using entire
files, not partial files.

This method can be called by a writer only during a backup operation.

## Parameters

### `wszPath` [in]

Null-terminated wide character string containing the name of the directory or directory hierarchy
containing the files to be mapped.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard
characters.

There is no requirement that the path end with a backslash ("\"). It is up to applications that
retrieve this information to check.

### `wszFilespec` [in]

Null-terminated wide character string containing the file specification of the files to be mapped.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain
the ? and * wildcard characters.

### `bRecursive` [in]

A Boolean value specifying whether the path specified by the *wszPath* parameter identifies
only a single directory or if it indicates a hierarchy of directories to be traversed recursively. This parameter should be set to **true** if the path is treated as a hierarchy of directories to be traversed recursively, or **false** if not.

For information on traversing mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

### `ftLastModifyTime` [in]

The writer specification of the time of last modification for the difference files, expressed as a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

The last-modify time is always given in Greenwich Mean Time.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added differenced files. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | This method was not called by a writer or, if called by a writer, it either was not called during a backup operation or was called while handling a [BackupComplete](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) or [BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) event. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

A writer calls this method to specify that certain files in a component should be backed up only if they have been modified since a certain time. For more information, see [Backup By Last Modify Time](https://learn.microsoft.com/windows/desktop/VSS/writer-role-in-backing-up-complex-stores).

This method can be called only by writers supporting the last modified schema
(**VSS_BS_LAST_MODIFY**), and only during backup operations. Writers using this method do
not have to support the time-stamp schema (**VSS_BS_TIMESTAMPED**).

Files added by
**AddDifferencedFilesByLastModifyTime**
should not also be added by
[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile).

If the backup type ([VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type)) is incremental
(**VSS_BT_INCREMENTAL**), writers using
**AddDifferencedFilesByLastModifyTime**
must support the incremental schema (**VSS_BS_INCREMENTAL**). If the backup type is
differential, the writer must support the **VSS_BS_DIFFERENTIAL** schema.

The
**AddDifferencedFilesByLastModifyTime**
method should be called prior to the actual start of a backup operation, typically while handling the
[PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event (see
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)).

If the time-stamp value set by
**AddDifferencedFilesByLastModifyTime**
is nonzero, a requester must respect this value regardless of its own records and file system information when
determining if the differenced file should be included in a differential or incremental backup.

If the time stamp set by
**AddDifferencedFilesByLastModifyTime**
(*ftLastModifyTime*) is zero, the requester can use file system information and its own
records to determine whether the differenced files should be included in a differential or incremental backup.

Requesters retrieve the number of differenced files managed by a component by calling
[IVssComponent::GetDifferencedFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfile).

Differenced file sets can be either of the following:

* A member of the current component or (if the component defines a component set) its subcomponents
* New files not previously included in the component or subcomponents. The
  **AddDifferencedFilesByLastModifyTime**
  method allows writers to indicate that files created since the original backup should be included in the
  component to support incremental or differential backups.

When referring to files that are already part of the component, the combination of path, file specification,
and recursion flag (*wszPath*, *wszFileSpec*, and
*bRecursive*, respectively) provided to
**AddDifferencedFilesByLastModifyTime**
to be mapped must match that of one of the file sets added to a component by
[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles).

When adding new files to the component,
**AddDifferencedFilesByLastModifyTime**,
the writer should not add files managed by another component or writer.

There is no method in the
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) interface that allows for changing or adding
an alternate location mappings for new files added by
**AddDifferencedFilesByLastModifyTime**.
If an alternate location mapping corresponds to the new file, then that alternate location will be used.

## See also

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetDifferencedFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfile)

[IVssComponent::GetDifferencedFilesCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfilescount)

[Incremental and Differential Backups](https://learn.microsoft.com/windows/desktop/VSS/incremental-and-differential-backups)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)

[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type)

[VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type)
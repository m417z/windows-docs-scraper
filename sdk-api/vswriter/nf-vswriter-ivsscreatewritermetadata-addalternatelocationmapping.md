# IVssCreateWriterMetadata::AddAlternateLocationMapping

## Description

The
**AddAlternateLocationMapping** method creates an alternate location mapping for a file set.

## Parameters

### `wszSourcePath` [in]

Null-terminated wide character string containing the name of the directory or directory hierarchy containing the files to be mapped.

The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters.

There is no requirement that the path end with a backslash ("\"). It is up to applications that retrieve this information to check.

### `wszSourceFilespec` [in]

Null-terminated wide character string containing the file specification of the files to be mapped.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `bRecursive` [in]

A Boolean value specifying whether the path specified by the *wszPath* parameter identifies only a single directory or if it indicates a hierarchy of directories to be traversed recursively. This parameter should be set to **true** if the path is treated as a hierarchy of directories to be traversed recursively, or **false** if not.

For information on traversing mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

### `wszDestination` [in]

Null-terminated wide character string containing the fully qualified path to the directory where the files will be relocated.

The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

UNC paths are supported.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT**<br><br>0x80042311L | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The [IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod) method was not called before this method was called. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012. Writers support only local resources—sets of files whose absolute path starts with a valid local volume specification and cannot be a mapped network drive. Therefore, path inputs (*wszPath* and *wszDestination*) to
**AddAlternateLocationMapping** (after the resolution of any environment variables) must be in this format.

This method can be called multiple times to add mapping for multiple files.

The combination of path, file specification, and recursion flag (*wszPath*, *wszFileSpec*, and *bRecursive*, respectively) provided to
**AddAlternateLocationMapping** to be mapped must match that of one of the file sets added to one of the writer's components using
[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles).

The
**AddAlternateLocationMapping** method should be called only after
[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod) is called.

A file should always be restored to its alternate location mapping if either of the following is true:

* The restore method (set at backup time) is VSS_RME_RESTORE_TO_ALTERNATE_LOCATION.
* Its restore target was set (at restore time) to VSS_RT_ALTERNATE.

In either case, if no valid alternate location mapping is defined, this constitutes a writer error.

A file can be restored to an alternate location mapping if either of the following is true:

* The restore method is VSS_RME_RESTORE_IF_NOT_THERE and a version of the file is already present on disk.
* The restore method is VSS_RME_RESTORE_IF_CAN_REPLACE and a version of the file is present on disk and cannot be replaced.

Again, if no valid alternate location mapping is defined, this constitutes a writer error.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

For more information on backup and restore file locations under VSS, see
[Non-Default Backup And Restore Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations).

## See also

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)
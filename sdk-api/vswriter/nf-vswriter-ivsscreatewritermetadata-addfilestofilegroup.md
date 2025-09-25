# IVssCreateWriterMetadata::AddFilesToFileGroup

## Description

The
**AddFilesToFileGroup** method adds a file set (a specified file or files) to a specified file group component.

## Parameters

### `wszLogicalPath` [in]

Pointer to a **null**-terminated wide character string containing the logical path (which may be **NULL**) of the component to which to add the files. For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

### `wszGroupName` [in]

Pointer to a **null**-terminated wide character string containing the name of the file group component. The type of this component must be VSS_CT_FILEGROUP; otherwise, the method will return an error.

### `wszPath` [in]

Pointer to a **null**-terminated wide character string containing the default root directory of the files to be added.

The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

UNC paths are supported.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters.

There is no requirement that the path end with a backslash ("\"). It is up to applications that retrieve this information to check.

### `wszFilespec` [in]

Pointer to a **null**-terminated wide character string containing the file specification of the files to be included.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `bRecursive` [in]

A Boolean value specifying whether the path specified by the *wszPath* parameter identifies only a single directory or if it indicates a hierarchy of directories to be traversed recursively. This parameter should be set to **true** if the path is treated as a hierarchy of directories to be recursed through, or **false** otherwise.

For information on traversing over mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

### `wszAlternateLocation` [in]

Pointer to a **null**-terminated wide character string containing the alternate path, which actually contains the files to be backed up with this component.

 The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

UNC paths are supported.

Specifying an alternate path is optional; if no alternate path is needed, *wszAlternatePath* should be **NULL**.

An alternate path should not be confused with an alternate location mapping.

### `dwBackupTypeMask` [in]

A bitmask of
[VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type) enumeration values to indicate if a writer should evaluate the file for participation in a certain type of backup operations.

The default value for this argument is (VSS_FSBT_ALL_BACKUP_REQUIRED | VSS_FSBT_ALL_SNAPSHOT_REQUIRED).

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid, or the caller attempted to add file-group files to a non-file-group component. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT**<br><br>0x80042311L | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_NOT_SUPPORTED**<br><br>0x8004232FL | For express writers, the value of *wszAlternatePath* must be **NULL**, and the *dwBackupTypeMask* bitmask cannot include **VSS_FSBT_DIFFERENTIAL_BACKUP_REQUIRED**, **VSS_FSBT_INCREMENTAL_BACKUP_REQUIRED**, or **VSS_FSBT_LOG_BACKUP_REQUIRED**. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The specified component does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012. Writers support only local resources—sets of files whose absolute path starts with a valid local volume specification and cannot be a mapped network drive. Therefore, path inputs (*wszPath* and *wszAlternatePath*) to
**AddFilesToFileGroup** (after the resolution of any environment variables) must be in this format.

A writer can call this method multiple times to add several sets of files to its file group component. However, you should make sure that the file specifications do not overlap, because a particular file can be specified only once.

The locations from which files are backed up and to which they are restored depends on the values for the root directory defined by *wszPath* and the alternate path defined by *wszAlternatePath*.

Note the following when using path information provided by
**AddFilesToFileGroup**:

* Restore operations should (if possible) restore files added to a component by
  **AddFilesToFileGroup** under the default root directory defined by *wszPath*.
* If an alternate path is not specified (if *wszAlternatePath* is **NULL**), the files added to the component will be backed up from the default root directory and restored to the default root directory indicated by *wszPath*.
* If an alternate path is specified (if *wszAlternatePath* is non-**NULL**), files added to the component are backed up from the alternate path specified by *wszAlternatePath*. However, requesters will still use *wszPath* as the default restoration location.
* If the alternate path is defined (*wszAlternatePath* is non-**NULL**) and there are files matching the file specification (*wszFilespec*) in both the alternate path and the default root directory (*wszPath*), then a backup operation should back up files located under the alternate path, not files located under the default root directory.
* Files should be restored to the directory indicated by *wszPath* unless an alternate location mapping was set by
  [IVssCreateWriterMetadata::AddAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addalternatelocationmapping) and the restore method or restore target requires it.

For more information on backup and restore file locations under VSS, see
[Non-Default Backup And Restore Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations).

## See also

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)

[IVssCreateWriterMetadata::AddAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addalternatelocationmapping)
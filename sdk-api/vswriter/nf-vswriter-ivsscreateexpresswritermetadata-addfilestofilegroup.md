# IVssCreateExpressWriterMetadata::AddFilesToFileGroup

## Description

Adds a file set (a specified file or files) to a specified file group component for an express writer.

## Parameters

### `wszLogicalPath` [in]

A pointer to a **null**-terminated wide character string containing the logical path (which may be **NULL**) of the component to which to add the files. For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

### `wszGroupName` [in]

A pointer to a **null**-terminated wide character string containing the name of the file group component. The type of this component must be VSS_CT_FILEGROUP; otherwise, the method will return an error.

### `wszPath` [in]

A pointer to a **null**-terminated wide character string containing the default root directory of the files to be added.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters.

There is no requirement that the path end with a backslash (\\). It is up to applications that retrieve this information to check.

### `wszFilespec` [in]

A pointer to a **null**-terminated wide character string containing the file specification of the files to be included.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `bRecursive` [in]

A Boolean value specifying whether the path specified by the *wszPath* parameter identifies only a single directory or if it indicates a hierarchy of directories to be traversed recursively. This parameter should be set to **true** if the path is treated as a hierarchy of directories to be recursed through, or **false** otherwise.

For information on traversing over mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

### `wszAlternateLocation` [in]

This parameter is reserved and must be **NULL**.

### `dwBackupTypeMask` [in]

A bitmask of
[VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type) enumeration values to indicate if a writer should evaluate the file for participation in a certain type of backup operations.

This parameter cannot include **VSS_FSBT_DIFFERENTIAL_BACKUP_REQUIRED**, **VSS_FSBT_INCREMENTAL_BACKUP_REQUIRED**, or **VSS_FSBT_LOG_BACKUP_REQUIRED**.

The default value for this argument is (VSS_FSBT_ALL_BACKUP_REQUIRED | VSS_FSBT_ALL_SNAPSHOT_REQUIRED).

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid, or the caller attempted to add file-group files to a non-file-group component. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified component does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## See also

[IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata)
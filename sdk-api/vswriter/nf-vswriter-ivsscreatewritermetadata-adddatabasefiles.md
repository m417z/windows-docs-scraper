# IVssCreateWriterMetadata::AddDatabaseFiles

## Description

The
**AddDatabaseFiles** method indicates the file set (the specified file or files) that make up the database component to be backed up.

## Parameters

### `wszLogicalPath` [in]

Pointer to a **null**-terminated wide character string containing the logical path of the component to which the database will be added.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

A logical path is not required and can be **NULL**.

### `wszDatabaseName` [in]

Pointer to a **null**-terminated wide character string containing the name of the database.

This name is required and must match the name of the component to which the database is being added.

### `wszPath` [in]

Pointer to a **null**-terminated wide character string containing the path of the directory containing the database file.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters.

UNC paths are supported.

There is no requirement that the path end with a backslash ("\"). It is up to applications that retrieve this information to check.

### `wszFilespec` [in]

Pointer to a **null**-terminated wide character string containing the file specification of the file or files associated with the database.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `dwBackupTypeMask` [in]

A bit mask (or bitwise OR) of
[VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type) enumeration values to indicate whether a writer should evaluate the file for participation in certain types of backup operations.

The default value for this argument is (VSS_FSBT_ALL_BACKUP_REQUIRED | VSS_FSBT_ALL_SNAPSHOT_REQUIRED).

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified component does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012. Writers support only local resources—sets of files whose absolute path starts with a valid local volume specification and cannot be a mapped network drive. Therefore, path inputs (*wszPath*) to
**AddDatabaseFiles** (after the resolution of any environment variables) must be in this format.

This method can be called multiple times for a particular database. This is done when the database exists on files stored on separate volumes, as is possible with Microsoft SQL Server.

The values of the *wszLogicalPath* and *wszDatabaseName* parameters should match those of one of the database components previously added with the
[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent) method.

## See also

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)

[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent)
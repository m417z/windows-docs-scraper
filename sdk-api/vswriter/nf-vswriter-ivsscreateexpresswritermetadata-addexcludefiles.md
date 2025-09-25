# IVssCreateExpressWriterMetadata::AddExcludeFiles

## Description

Excludes a file set (a specified file or files) that might otherwise be implicitly included when a component of an express writer is backed up.

## Parameters

### `wszPath` [in]

A pointer to a null-terminated wide character string containing the root directory under which files are to be excluded.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters.

There is no requirement that the path end with a backslash (\\). It is up to applications that retrieve this information to check.

### `wszFilespec` [in]

A pointer to a null-terminated wide character string containing the file specification of the files to be excluded.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `bRecursive` [in]

A Boolean value specifying whether the path specified by the *wszPath* parameter identifies only a single directory or if it indicates a hierarchy of directories to be traversed recursively. This parameter should be set to **true** if the path is treated as a hierarchy of directories to be recursed through, or **false** otherwise.

For information on traversing over mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Express writers support only local resources—sets of files whose absolute path starts with a valid local volume specification and cannot be a mapped network drive. Therefore, path inputs (*wszPath*) to
**AddExcludeFiles** (after the resolution of any environment variables) must be in this format. For example, it is often convenient to define a component to include all files in a specified directory and then use
**AddExcludeFiles** to explicitly remove some files (for instance, temporary files) from a backup.

For more information on excluding files, see
[Exclude File List Specification](https://learn.microsoft.com/windows/desktop/VSS/writer-metadata-document-contents).

## See also

[IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata)

[IVssCreateExpressWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreateexpresswritermetadata-addcomponent)
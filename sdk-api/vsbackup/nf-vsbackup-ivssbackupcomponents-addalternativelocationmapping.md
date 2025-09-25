# IVssBackupComponents::AddAlternativeLocationMapping

## Description

The
**AddAlternativeLocationMapping** method is used by a requester to indicate that an alternate location mapping was used to restore all the members of a file set in a given component.

## Parameters

### `writerId` [in]

Globally unique identifier (GUID) of the writer class that exported the component.

### `componentType` [in]

Type of the component. The possible values of this parameter are defined by the
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) enumeration.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path to the component.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the component name.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszPath` [in]

**Null**-terminated wide character string containing the path to the directory that originally contained the file to be relocated. This path can be local to the VSS machine, or it can be a file share directory on a remote file server.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters. UNC paths are supported.

There is no requirement that the path end with a backslash ("\"). It is up to applications that retrieve this information to check.

### `wszFilespec` [in]

**Null**-terminated wide character string containing the original file specification.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `bRecursive` [in]

A Boolean value that indicates whether the path specified by the *wszPath* parameter identifies only a single directory or if it indicates a hierarchy of directories to be traversed recursively. This parameter should be set to **true** if the path is treated as a hierarchy of directories to be traversed recursively, or **false** if not.

For information on traversing mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

### `wszDestination` [in]

**Null**-terminated wide character string containing the name of the directory where the file will be relocated. This path can be local to the VSS machine, or it can be a file share directory on a remote file server. UNC paths are supported.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the alternate location mapping. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified component does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

The *writerId*, *componentType*, *wszLogicalPath*, and *wszComponentName* parameters identify a particular component, and the *wszPath*, *wszFilespec*, and *bRecursive* parameters identify the file set belonging to that component.

The combination of path, file specification, and recursion flag (*wszPath*, *wszFilespec*, and *bRecursive*, respectively) provided to
**AddAlternativeLocationMapping** to be mapped must match that of one of the file sets added to a component using either
[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles).

Because
**AddAlternativeLocationMapping** is used to notify a writer that an alternate location was used to restore all the files in a component, it should not be called for any component or files in a component that have not had an alternate location mapping specified.

The value of *wszPath* will have been mapped to *wszDestination* on restore; however, file names and subdirectories under the original path retain their same names.

A typical usage of
**AddAlternativeLocationMapping** during restore might be the following:

1. Retrieve stored Writer Metadata Documents from the backup media and load that information with
   [IVssExamineWriterMetadata::LoadFromXML](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-loadfromxml).
2. Call
   [IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping) to get an
   [IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) interface with the mapping information and use
   [IVssWMFiledesc::GetAlternateLocation](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getalternatelocation) to get the alternate location.
3. Examine filedesc information to heuristically determine which component this alternate location mapping should be applied to.
4. Call
   **IVssBackupComponents::AddAlternativeLocationMapping** to communicate where files were restored.

A file should always be restored to its alternate location mapping if either of the following is true:

* The restore method (set at backup time) is VSS_RME_RESTORE_TO_ALTERNATE_LOCATION.
* Its restore target was set (at restore time) to VSS_RT_ALTERNATE.

In either case, if no valid alternate location mapping is defined this constitutes a writer error.

A file may be restored to an alternate location mapping if either of the following is true:

* The restore method is VSS_RME_RESTORE_IF_NOT_THERE and a version of the file is already present on disk.
* The restore method is VSS_RME_RESTORE_IF_CAN_REPLACE and a version of the file is present on disk and cannot be replaced.

Again, if no valid alternate location mapping is defined this constitutes a writer error.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssWMFiledesc::GetAlternateLocation](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getalternatelocation)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)
# IVssBackupComponents::AddNewTarget

## Description

The
**AddNewTarget** method is used by a requester during a restore operation to indicate that the backup application plans to restore files to a new location.

## Parameters

### `writerId` [in]

Globally unique identifier (GUID) of the writer class containing the files that are to receive a new target.

### `ct` [in]

Identifies the type of the component. Refer to the documentation for
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for possible return values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component containing the files that are to receive a new restore target. For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component containing the files that are to receive a new restore target.

The string should not be **NULL** and should contain the same component name as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszPath` [in]

**Null**-terminated wide character string containing the name of the directory or directory hierarchy containing the files to receive a new restore target.

The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters. UNC paths are supported.

There is no requirement that the path end with a backslash ("\"). It is up to applications that retrieve this information to check.

### `wszFileName` [in]

**Null**-terminated wide character string containing the file specification of the files to receive a new restore target.

A file specification cannot contain directory specifications (for example, no backslashes) but can contain the ? and * wildcard characters.

### `bRecursive` [in]

Boolean indicating whether only the files in the directory defined by *wszPath* and matching the file specification provided by *wszFileName* are to receive a new restore target, or if all files in the hierarchy defined by *wszPath* and matching the file specification provided by *wszFileName* are to receive a new restore target.

For information on traversing mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

### `wszAlternatePath` [in]

**Null**-terminated wide character string containing the fully qualified path of the new restore target directory.

The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

UNC paths are supported.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the new restore target. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, or this method has been called during a restore operation. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The component does not exist or the path and file specification do not match a component and file specification in the component. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

The component name specified as an argument to
**AddNewTarget** (*wszComponentName*) must match a component that has already been added to the Backup Components Document.

Therefore, *wszComponentName* can be the name of any component explicitly included in the Backup Components Document.

Adding a new target for file in a subcomponent must be done using the name of the component that defines the component set containing the subcomponent.

When specifying a file or files to have their restore target changed, a requester must ensure that the combination of path, file specification, and recursion flag (*wszPath*, *wszFileSpec*, and *bRecursive*, respectively) provided to
**AddNewTarget** must match that of one of the file sets added to a component using
[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles).

When a requester calls **AddNewTarget**, it must do so before calling [IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore). For more information, see [Overview of Preparing for Restore](https://learn.microsoft.com/windows/desktop/VSS/overview-of-preparing-for-restore).

Path and file descriptor information can be obtained from the Writer Metadata Document by using the
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object returned by
[IVssWMComponent::GetFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getfile),
[IVssWMComponent::GetDatabaseFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabasefile), or
[IVssWMComponent::GetDatabaseLogFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabaselogfile). The
[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) object is obtained from Writer Metadata Document by the
[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent) method.

Writers can determine if files have been restored to new locations by using the
[IVssComponent::GetNewTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getnewtargetcount) and
[IVssComponent::GetNewTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getnewtarget) methods.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent)

[IVssComponent::GetNewTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getnewtarget)

[IVssComponent::GetNewTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getnewtargetcount)

[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles)

[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles)

[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup)

[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent)

[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent)

[IVssWMComponent::GetDatabaseFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabasefile)

[IVssWMComponent::GetDatabaseLogFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabaselogfile)

[IVssWMComponent::GetFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getfile)

[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)
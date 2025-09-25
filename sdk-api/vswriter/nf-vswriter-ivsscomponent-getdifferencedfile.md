# IVssComponent::GetDifferencedFile

## Description

The **GetDifferencedFile** method returns
information about a file set (a specified file or files) to participate in an incremental or differential backup
or restore as a differenced file—that is, backup and restores associated with it are to be
implemented as if entire files are copied to and from backup media (as opposed to using partial files).

This method can be called by a requester or a writer during backup or restore operations.

## Parameters

### `iDifferencedFile` [in]

Index number of the differenced file to be examined. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of differenced files
associated with a given component (and its subcomponents if it defines a component set). The value of
*n* is returned by
[IVssComponent::GetDifferencedFilesCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfilescount).

### `pbstrPath` [out]

The address of a caller-allocated variable that receives a string containing the path to the differenced files.

Users of this method need to check to determine whether this path ends with a backslash
(\\).

### `pbstrFilespec` [out]

The address of a caller-allocated variable that receives a string containing the file specification of the differenced files.

### `pbRecursive` [out]

The address of a caller-allocated variable that receives a Boolean specifying whether the file specification for the differenced files should be
interpreted recursively. If **TRUE**, then the entire directory hierarchy will need to be searched for files
matching the file specification *pbstrFilespec* to find files to be handled as
differenced files during incremental or differential backups. If **FALSE**, only the root directory needs to be
searched.

### `pbstrLsnString` [out]

Reserved for future use.

### `pftLastModifyTime` [out]

The address of a caller-allocated variable that receives the writer specification of the time of last modification for the difference files, expressed as a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | No differenced file corresponding to the supplied index was found. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

**GetDifferencedFile** can be called by
a requester or a writer during backup or restore operations.

If the call to **GetDifferencedFile** is successful, the caller is responsible for freeing the string that is returned in the *pbstrPath* and *pbstrFilespec* parameters by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

As writers can indicate differenced files with calls to
[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)
at any time prior to the actual backing up of files, typically while handling a
[PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event
([CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)), during backups
**GetDifferencedFile** is not usefully
called prior to the return of
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)
has successfully returned.

The time stamp returned by
**GetDifferencedFile** applies to all files
that match the returned path (*pbstrPath*) and file specification
(*pbstrFilespec*).

If the time-stamp value returned by
**GetDifferencedFile**
(*pftLastModifyTime*) is nonzero, a requester must respect this value regardless of its
own records and file system information and use it to determine whether the differenced file should be included in a
differential or incremental backup.

If the time stamp returned by
**GetDifferencedFile** is zero, the
requester can use file system information and its own records to determine whether the differenced files should be
included in a differential or incremental backup.

Differenced files can be either of the following:

* Members of the current component or, if the component defines a component set, members of its subcomponents
  that were added to the component using
  [IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
  [IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
  [IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles)
* New files added to the component by
  [IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)

When referring to a file set that is already part of the component, the combination of path, file
specification, and recursion flag (*wszPath*, *wszFileSpec*, and
*bRecursive*, respectively) used when calling
**GetDifferencedFile** should match that of
a file set already in the component, or one of its subcomponents (if the component defines a component set).

When **GetDifferencedFile** returns a
differenced new file, that file's path (*pbstrPath*) should match or be beneath a path
already in the component, or one of its subcomponents (if the component defines a component set).

In addition, the files returned by
**GetDifferencedFile** should not already
be managed by component or writer.

If any of these criteria are violated, they constitute an error on the part of the writer and should be
reported.

There is no method in the
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) interface that allows for changing or adding
an alternate location mapping for new files returned by
**GetDifferencedFilesByLastModifyTime**. If an alternate location mapping corresponds
to the new file, then that alternate location will be used.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)

[IVssComponent::GetDifferencedFilesCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfilescount)

[Incremental and Differential Backups](https://learn.microsoft.com/windows/desktop/VSS/incremental-and-differential-backups)
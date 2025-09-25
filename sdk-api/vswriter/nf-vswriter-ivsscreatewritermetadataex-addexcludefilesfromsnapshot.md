# IVssCreateWriterMetadataEx::AddExcludeFilesFromSnapshot

## Description

Reports any [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) that will be explicitly excluded by the writer when a shadow copy is created.

Calling this method does not cause the files to be excluded. The writer is responsible for deleting the files from the shadow copy in its [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) method.

## Parameters

### `wszPath` [in]

A pointer to a null-terminated wide character string containing the root directory under which files are to be excluded.

The directory can be a local directory on the VSS machine, or it can be a file share directory on a remote file server.

UNC paths are supported.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard characters.

There is no requirement that the path end with a backslash ("\"). It is up to applications that retrieve this information to check whether the path ends with a backslash.

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
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT**<br><br>0x80042311L | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_NOT_SUPPORTED**<br><br>0x8004232FL | This method is not supported for express writers. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

The use of the **AddExcludeFilesFromSnapshot** method is optional. Writers should use this method only for large files that change significantly between shadow copy operations.

This method is not a substitute for the [IVssCreateWriterMetadata::AddExcludeFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addexcludefiles) method. Writers should continue to use the **AddExcludeFiles** method to report which [file sets](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) are excluded from backup.

The caller is responsible for calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to release the resources of the returned
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object.

## See also

[IVssCreateWriterMetadata::AddExcludeFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addexcludefiles)

[IVssCreateWriterMetadataEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadataex)

[IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex2-getexcludefromsnapshotcount)

[IVssExamineWriterMetadataEx2::GetExcludeFromSnapshotFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex2-getexcludefromsnapshotfile)
# IVssComponent::AddPartialFile

## Description

The
**AddPartialFile** method indicates that only
portions of a given file are to be backed up and which portions those are.

Only a writer can call this method, and only during a backup operation.

## Parameters

### `wszPath` [in]

**Null**-terminated wide character string containing the path of the file involved in partial file operations.

The path can contain environment variables (for example, %SystemRoot%) but cannot contain wildcard
characters.

There is no requirement that the path end with a backslash ("\"). It is up to applications that
retrieve this information to check.

This path should match or be beneath the path of a file set already in the component (or one of its
subcomponents if the component defines a component set).

### `wszFilename` [in]

**Null**-terminated wide character string containing the name of the file involved in partial file operations.
The name of the file (*wszFilename*) cannot contain wildcard characters (* or ?) and must be consistent with the
file specification of a file set containing the source path (*wszPath*).

### `wszRanges` [in]

**Null**-terminated wide character string containing either a listing of file offsets and lengths that make up
the partial file support range (the sections of the file to actually be backed up), or the name of a file
containing such a list.

Specifying the partial file support range is required, and this value cannot be **NULL**.

### `wszMetadata` [in]

**Null**-terminated wide character string containing any additional metadata required by a writer to validate a
partial file restore operation. The information in this metadata string will be opaque to requesters.

If additional metadata is not required, this value can be **NULL**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the item. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The method was not called by a writer or, if called by a writer, was not called during a restore operation. |

## Remarks

Only a writer can call this method, and the writer cannot call this method during a restore operation.

The syntax of the range listing (*wszRanges*) is that of a comma-separated list of the form
**offset1:length1, offset2:length2**, where each offset and length is a 64-bit integer
specifying a byte offset and length in bytes, respectively. The offset and length can be expressed either as
hexadecimal or decimal values.

If
*wszRange* refers to a file containing all the offsets and lengths (a ranges file),
*wszRange* will contain only the full path to the file.

A ranges file must be a binary file with the following format:

1. A 64-bit integer indicating the number of distinct file ranges that need to be backed up
2. Each range expressed as a pair of 64-bit integers: the offset into the file being backed up in bytes, and
   the length of data starting from that offset to be backed up

In either case, a range indicates a subsection of a given file that is to be backed up, independent of the rest
of the file.

Requesters can retrieve the partial file information using
[IVssComponent::GetPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfile) and use the
offset and length information returned by
**GetPartialFile** to restore backed-up sections to
the appropriate location within the copy of the file on disk at restore time.

**AddPartialFile** can be applied to a file already
managed by the component (or one of its subcomponents if the component defines a component set), or it can add a new
file to the component and indicate that it will participate in partial file operations.

When indicating that the file to participate is a new file, that file must exist on a shadow-copied volume and
its path (*wszPath*) should match or be beneath a path already in the component (or one of its
subcomponents if the component defines a component set). However, the file's file specification (*wszFileSpec*) should not match one in the components.

Any newly added files will not support alternate location mappings.

## See also

[IVssBackupComponents::SetRangesFilePath](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrangesfilepath)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfile)

[IVssComponent::GetPartialFileCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfilecount)
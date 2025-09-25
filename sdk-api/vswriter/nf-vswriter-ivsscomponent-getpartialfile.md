# IVssComponent::GetPartialFile

## Description

The
**GetPartialFile** method returns information on a partial file associated with this component.

## Parameters

### `iPartialFile` [in]

Index number of the partial file. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of partial files associated with a given component. The value of *n* is returned by
[IVssComponent::GetPartialFileCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfilecount).

### `pbstrPath` [out]

Pointer to a string containing the path of the partial file.

Users of this method need to check to determine whether this path ends with a backslash ("\").

### `pbstrFilename` [out]

Pointer to a string containing the name of the partial file.

### `pbstrRange` [out]

A pointer to a string containing either a listing of file offsets and lengths that make up the partial file support range (the sections of the file that were backed up), or the name of a file containing such a list.

### `pbstrMetadata` [out]

Pointer to a string containing any additional metadata required by a writer to validate a partial file restore operation. The information in this metadata string will be opaque to requesters.

Additional metadata is not required, so *pbstrMetadata* may also be empty (zero length).

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The caller is not in the correct state (either backup or restore) for the operation. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified item was not found. |

## Remarks

The caller should free the memory held by the *pbstrPath*, *pbstrFilename*, *pbstrRange*, and *pbstrMetadata* parameters by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

A range indicates a subsection of a given file that is to be backed up, independent of the rest of the file.

The syntax of the range listing (*pbstrRanges*) is that of a comma-separated list of the form **offset1:length1, offset2:length2**, where each offset and length is a 64-bit integer specifying a byte offset and length in bytes, respectively. The offset and length can be expressed either as hexadecimal or decimal values.

If *pbstrRanges* refers to a file containing all the offsets and lengths (a ranges file), *pbstrRanges* should contain the full path to the file.

If *wszRange* refers to a file containing all the offsets and lengths (a ranges file), *wszRange* should contain the full path to the file.

A ranges file must be a binary file with the following format:

1. A 64-bit integer indicating the number of distinct file ranges that need to be backed up.
2. Each range expressed as a pair of 64-bit integers: the offset into the file being backed up, in bytes, and the length of data starting from that offset to be backed up.

A ranges file should have been backed up along with the partial file and typically is restored to the same location that it was backed up from.

However, the location to which a ranges file is restored might be altered by the requester, which uses
[IVssBackupComponents::SetRangesFilePath](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrangesfilepath) to indicate this and to update the Backup Components Document so that *pbstrRanges* indicates the correct ranges file.

A requester would use the ranges information returned by
**GetPartialFile** to restore the backed-up sections to the appropriate location within the copy of the file on disk at restore time.

## See also

[IVssBackupComponents::SetRangesFilePath](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrangesfilepath)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)

[IVssComponent::GetPartialFileCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfilecount)
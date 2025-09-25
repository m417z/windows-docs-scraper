# IVssComponent::GetDirectedTarget

## Description

The
**GetDirectedTarget** method returns information stored by a writer, at backup time, to the Backup Components Document to indicate that when a file is to be restored, it (the source file) should be remapped. The file may be restored to a new restore target and/or ranges of its data restored to different locations with the restore target.

Either a writer or a requester can call this method.

## Parameters

### `iDirectedTarget` [in]

Index number of the directed target. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of directed targets associated with a given component (and its subcomponents if it defines a component set). The value of *n* is returned by
[IVssComponent::GetDirectedTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdirectedtargetcount).

### `pbstrSourcePath` [out]

The address of a caller-allocated variable that receives a string containing the path to the directory that at backup time contained the file to be restored (the source file). This path should match or be beneath the path of a file set already in the component or one of its subcomponents (if the component defines a component set).

### `pbstrSourceFileName` [out]

The address of a caller-allocated variable that receives a string containing the name of the file (at backup time) that is to be remapped during a restore (the source file). The name of this file should not contain any wildcard characters, and must be a member of the same file set as the source path (*pbstrSourcePath*).

### `pbstrSourceRangeList` [out]

The address of a caller-allocated variable that receives a string containing a comma-separated list of file offsets and lengths indicating the source file support range (the sections of the file to be restored).

The number and length of the source file support ranges must match the number and size of destination file support ranges.

### `pbstrDestinationPath` [out]

The address of a caller-allocated variable that receives a string containing the path to which source file data will be remapped at restore time.

### `pbstrDestinationFilename` [out]

The address of a caller-allocated variable that receives a string containing the name of the file to which source file data will be remapped at restore time.

### `pbstrDestinationRangeList` [out]

The address of a caller-allocated variable that receives a string containing a comma-separated list of file offsets and lengths indicating the destination file support range (locations to which the sections of the source file are to be restored).

The number and length of the destination file support ranges must match the number and size of source file support ranges.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified item was not found. |

## Remarks

If the call to **GetDirectedTarget** is successful, the caller is responsible for freeing each returned string by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

A requester will use the directed target information stored in the Backup Components Document only if the restore target is VSS_RT_DIRECTED.

The syntax of the range listing (*wszSourceRanges* and *wszDestinationRanges*) is that of a comma-separated list of the form **offset1:length1, offset2:length2**, where each offset and length is a 64-bit integer specifying a byte offset and length in bytes, respectively. The offset and length can be expressed either as hexadecimal or decimal values.

Files whose directed targets are returned by
**GetDirectedTarget** may be members of the files of the current component or any subcomponent it defines.

The caller should free the memory held by the *pbstrSourcePath*, *pbstrSourceFileName*, *pbstrSourceRangeList*, *pbstrDestinationPath*, *pbstrDestinationFilename*, and *pbstrDestinationRangeList* parameters by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

Partial files may be added as directed targets, if the partial file ranges to be backed up match the directed target source ranges (see
[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)). This will allow you to remap partial files.

The requester will need to check if the directed target source file was backed up as a partial file to correctly implement the restore. If this is the case, the requester uses the directed target information in conjunction with the partial file information ([IVssComponent::GetPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfile)) to implement the remapping of the backed-up data during restore.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::AddDirectedTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddirectedtarget)

[IVssComponent::GetDirectedTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdirectedtargetcount)
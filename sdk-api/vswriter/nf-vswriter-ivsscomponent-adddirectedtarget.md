# IVssComponent::AddDirectedTarget

## Description

The
**AddDirectedTarget** method allows a writer to indicate at restore time that when a file is to be restored, it (the source file) should be remapped. The file can be restored to a new restore location and/or ranges of its data restored to different offsets within the restore location.

This method can be called by a writer only during a restore operation.

This method cannot be called while handling a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) ([CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)) or [BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) ([CVssWriter::OnBackupShutdown](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupshutdown)) event.

## Parameters

### `wszSourcePath` [in]

Null-terminated wide character string containing the path to the directory at restore time containing the file to be restored (the source file). This path should match or be beneath the path of a file set already in the component (or one of its subcomponents if the component defines a component set).

### `wszSourceFilename` [in]

Null-terminated wide character string containing the name of the file (at backup time) that will be remapped at restore time (the source file). The name of the file (*wszSourceFilename*) cannot contain wildcard characters (* or ?) and must be consistent with the file specification of a file set containing the source path (*wszSourcePath*).

### `wszSourceRangeList` [in]

A null-terminated wide character string containing a comma-separated list of file offsets and lengths indicating the source file support range (the sections of the file to actually be restored).

The number and length of the source file support ranges must match the number and size of destination file support ranges.

### `wszDestinationPath` [in]

Null-terminated wide character string containing the path to which source file data will be remapped at restore time.

### `wszDestinationFilename` [in]

Null-terminated wide character string containing the name of the file to which source file data will be remapped at restore time. The name of the file (*wszDestinationFilename*) cannot contain wildcard characters (* or ?).

### `wszDestinationRangeList` [in]

A null-terminated wide character string containing a comma-separated list of file offsets and lengths indicating the destination file support range (locations to which the sections of the source file are to be restored).

The number and length of the destination file support ranges must match the number and size of source file support ranges.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the item. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | This method was not called by a writer or, if called by a writer, it either was not called during a restore operation or was called while handling a [BackupComplete](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) or [BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) event. |

## Remarks

Only a writer can call
**AddDirectedTarget**, and only during restore operations.

A requester will use the directed target information stored in the Backup Components Document only if the restore target is VSS_RT_DIRECTED.

The
**AddDirectedTarget** method can be applied to any file managed in the current component or, if the component defines a component set, in any of its nonselectable subcomponents.

Source and destination file specifications may point to the same file. This would allow remapping of a file into itself at restore time.

The syntax of the range listing (*wszSourceRanges* and *wszDestinationRanges*) is that of a comma-separated list of the form **offset1:length1, offset2:length2**, where each offset and length is a 64-bit integer specifying a byte offset and length in bytes, respectively. The offset and length can be expressed either as hexadecimal or decimal values.

The number of entries and their sizes must match in the source and destination range arguments.

**AddDirectedTarget** can use as its source file any file already managed by the component or one of its subcomponents if the component defines a component set.

Partial files may be added as directed targets, if the partial file ranges to be backed up match the directed target source ranges (see
[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)). This will allow you to remap partial files at restore time.

In this case, the requester retrieves the directed target information by calling the
[IVssComponent::GetDirectedTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdirectedtarget) method and uses that to implement the remapping of the backed-up data during restore.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetDirectedTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdirectedtarget)

[IVssComponent::GetDirectedTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdirectedtargetcount)
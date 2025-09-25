## Description

**REARRANGE_FILE_DATA** is the input structure for the [**FSCTL_REARRANGE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_rearrange_file) control code.

## Members

### `SourceStartingOffset`

Cluster-aligned byte offset of the base of the contiguous source region in the source file to move to the target location of the target file.

### `TargetOffset`

Cluster-aligned byte offset of the point to insert the source region.

### `SourceFileHandle`

Handle to the alternate file to move the source region clusters from. This feature is not currently supported so **SourceFileHandle** must be set to NULL, which indicates that the source region is from the same file.

### `Length`

Cluster-aligned length in bytes of the source region.

### `Flags`

Reserved for future use; must be set to zero.

## See also

[**FSCTL_REARRANGE_FILE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_rearrange_file)
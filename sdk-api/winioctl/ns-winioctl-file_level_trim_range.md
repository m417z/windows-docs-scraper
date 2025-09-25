# FILE_LEVEL_TRIM_RANGE structure

## Description

Specifies a range of a file that is to be trimmed.

## Members

### `Offset`

Offset, in bytes, from the start of the file for the range to be trimmed.

### `Length`

Length, in bytes, for the range to be trimmed.

## Remarks

Before the trim operation is passed to the underlying storage system the input ranges are reduced to be
aligned to page boundaries (4,096 bytes on 32-bit and x64-based editions of Windows, 8,192 bytes on Itanium-Based
editions of Windows).

## See also

[FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_file_level_trim)

[FILE_LEVEL_TRIM_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_level_trim_output)

**FSCTL_FILE_LEVEL_TRIM**
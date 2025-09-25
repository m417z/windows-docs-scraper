# FILE_ALLOCATED_RANGE_BUFFER structure

## Description

Indicates a range of bytes in a file. This structure is used with the
[FSCTL_QUERY_ALLOCATED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_allocated_ranges) control code. On input, the structure indicates the range of the file to search. On output, the operation retrieves an array of
**FILE_ALLOCATED_RANGE_BUFFER** structures to indicate the allocated ranges within the search range.

## Members

### `FileOffset`

The file offset of the start of a range of bytes in a file, in bytes.

### `Length`

The size of the range, in bytes.

## See also

[FSCTL_QUERY_ALLOCATED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_allocated_ranges)

[Sparse Files](https://learn.microsoft.com/windows/desktop/FileIO/sparse-files)
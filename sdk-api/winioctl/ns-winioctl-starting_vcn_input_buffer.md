# STARTING_VCN_INPUT_BUFFER structure

## Description

Contains the starting VCN to the
[FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers) control code.

## Members

### `StartingVcn`

The VCN at which
the operation will begin enumerating extents in the file. This value may be rounded down to the first VCN of the extent in which the specified extent is found.

## See also

[Defragmentation](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364407(v=vs.85))

[FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers)
# FILE_ZERO_DATA_INFORMATION structure

## Description

Contains a range of a file to set to zeros. This structure is used by the
[FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_zero_data) control code

## Members

### `FileOffset`

The file offset of the start of the range to set to zeros, in bytes.

### `BeyondFinalZero`

The byte offset of the first byte beyond the last zeroed byte.

## See also

[FSCTL_SET_ZERO_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_zero_data)

[Sparse Files](https://learn.microsoft.com/windows/desktop/FileIO/sparse-files)
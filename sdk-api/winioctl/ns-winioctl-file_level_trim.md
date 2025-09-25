# FILE_LEVEL_TRIM structure

## Description

Used as input to the
[FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_file_level_trim) control code.

## Members

### `Key`

Reserved. Set to zero (0).

### `NumRanges`

Number of [FILE_LEVEL_TRIM_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_level_trim_range) entries in
the **Ranges** member. On return should be compared with the
**NumRangesProcessed** member of the
[FILE_LEVEL_TRIM_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_level_trim_output) structure.

### `Ranges`

Array of ranges that describe the portions of the file that are to be trimmed.

## See also

[FILE_LEVEL_TRIM_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_level_trim_output)

[FILE_LEVEL_TRIM_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-file_level_trim_range)

[FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_file_level_trim)
# FILE_LEVEL_TRIM_OUTPUT structure

## Description

Used as output to the
[FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_file_level_trim) control code.

## Members

### `NumRangesProcessed`

Contains the number of ranges that were successfully processed. This may be less than the value passed in
the **NumRanges** member of the
[FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_file_level_trim) structure. If it is then the last
ranges in the array were not processed.

## See also

[FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_file_level_trim)
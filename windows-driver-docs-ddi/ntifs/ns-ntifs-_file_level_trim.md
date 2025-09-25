# _FILE_LEVEL_TRIM structure

## Description

The **FILE_LEVEL_TRIM** structure contains an array of byte ranges to trim for a file.

## Members

### `Key`

The key for the byte range locks. Most callers will set this to 0. Remote file systems use **Key** for tagging a set of range locks.

### `NumRanges`

Total number of range structures in **Ranges**.

### `Ranges`

Array of trim ranges for a file.

## See also

[FILE_LEVEL_TRIM_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_level_trim_range)

[FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-file-level-trim)
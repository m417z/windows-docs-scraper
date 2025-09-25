# _FILE_LEVEL_TRIM_OUTPUT structure

## Description

The **FILE_LEVEL_TRIM_OUTPUT** structure contains the results of a trim operation performed by an [FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-file-level-trim) request.

## Members

### `NumRangesProcessed`

The number or trim ranges processed.

## Remarks

This structure is optionally included as the output buffer for an [FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-file-level-trim) request. **NumRangesProcessed** indicates how many ranges of the in the array given in [FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_level_trim) were processed.

All trim ranges in the array in [FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_level_trim) were successfully processed if **NumRangesProcessed** is equivalent to the **NumRanges** member of **FILE_LEVEL_TRIM**. Otherwise, the value in **NumRangesProcessed** is the starting index of the trim ranges that were not processed.

## See also

[FSCTL_FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-file-level-trim)
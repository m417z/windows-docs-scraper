# _FILE_LEVEL_TRIM_RANGE structure

## Description

Contains the offset and length of a trim range for a file.

## Members

### `Offset`

Byte offset from the front of the given file to trim at.

### `Length`

Length in bytes to trim from the given offset.

## Remarks

Due to alignment requirements, the file system may reduce the of the trim range to a multiple of **PAGE_SIZE** <= **Length**. Also, **Offset** will be adjusted to the next page boundary if its initial value is not on page boundary.

## See also

[FILE_LEVEL_TRIM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_level_trim)
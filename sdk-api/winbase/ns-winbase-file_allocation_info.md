# FILE_ALLOCATION_INFO structure

## Description

Contains the total number of bytes that should be allocated for a file. This structure is used when calling the [SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle) function.

## Members

### `AllocationSize`

The new file allocation size, in bytes. This value is typically a multiple of the sector or cluster size for the underlying physical device.

## Remarks

The end-of-file (EOF) position for a file must always be less than or equal to the file allocation size. If the allocation size is set to a value that is less than EOF, the EOF position is automatically adjusted to match the file allocation size.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
# FILE_END_OF_FILE_INFO structure

## Description

Contains the specified value to which the end of the file should be set. Used for file handles. Use only when calling [SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle).

## Members

### `EndOfFile`

The specified value for the new end of the file.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
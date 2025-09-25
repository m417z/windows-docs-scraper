# FILE_DISPOSITION_INFO structure

## Description

Indicates whether a file should be deleted. Used for any handles. Use only when calling
[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle).

## Members

### `DeleteFile`

Indicates whether the file should be deleted. Set to **TRUE** to delete the file.
This member has no effect if the handle was opened with
**FILE_FLAG_DELETE_ON_CLOSE**.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)
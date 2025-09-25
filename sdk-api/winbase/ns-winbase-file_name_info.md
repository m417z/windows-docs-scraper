# FILE_NAME_INFO structure

## Description

Receives the file name. Used for any handles. Use only when calling
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

## Members

### `FileNameLength`

The size of the **FileName** string, in bytes.

### `FileName`

The file name that is returned.

## Remarks

If the call to `GetFileInformationByHandleEx` fails with `ERROR_MORE_DATA` because there was not enough
buffer space for the full length of the **FileName** then the `FileNameLength`
field will contain the required length of the **FileName** in bytes.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)
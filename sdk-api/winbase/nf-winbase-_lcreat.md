# _lcreat function

## Description

[This function is provided for compatibility with 16-bit versions of Windows. New applications should use the **CreateFile** function.]

Creates or opens the specified file. This documentation is included only for troubleshooting existing code.

## Parameters

### `lpPathName`

The name of the file. The string must consist of characters from the Windows ANSI character set.

### `iAttribute`

The attributes of the file.

This parameter must be set to one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Normal. Can be read from or written to without restriction. |
| 1 | Read-only. Cannot be opened for write. |
| 2 | Hidden. Not found by directory search. |
| 4 | System. Not found by directory search. |

## Return value

If the function succeeds, the return value is a file handle. Otherwise, the return value is HFILE_ERROR. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If the file does not exist, **_lcreat** creates and opens a new file for writing. If the file does exist, **_lcreat** truncates the file size to zero and opens it for reading and writing.

When the function opens a file, the pointer is set to the beginning of the file.

Use the **_lcreat** function with care. It can open any file, even one already opened by another function.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)
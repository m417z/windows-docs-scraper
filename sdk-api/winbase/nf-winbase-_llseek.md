# _llseek function

## Description

[This function is provided for compatibility with 16-bit versions of Windows. New applications should use the **SetFilePointer** function.]

Repositions the file pointer for the specified file.

## Parameters

### `hFile`

A handle to an open file. This handle is created by [_lcreat](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-_lcreat).

### `lOffset`

The number of bytes that the file pointer is to be moved.

### `iOrigin`

The starting point and the direction that the pointer will be moved.

This parameter must be set to one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Moves the pointer from the beginning of the file. |
| 1 | Moves the file from its current location. |
| 2 | Moves the pointer from the end of the file. |

## Return value

If the function succeeds, the return value specifies the new offset. Otherwise, the return value is HFILE_ERROR. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

When a file is initially opened, the file pointer is set to the beginning of the file. The **_llseek** function moves the pointer without reading data, which allows random access to the content of the file.

## See also

[SetFilePointer](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfilepointer)
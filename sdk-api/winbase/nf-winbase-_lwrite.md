# _lwrite function

## Description

[This function is provided for compatibility with 16-bit versions of Windows. New applications should use the **WriteFile** function.]

Writes data to the specified file.

## Parameters

### `hFile`

A handle to the file that receives the data. This handle is created by [_lcreat](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-_lcreat).

### `lpBuffer`

The buffer that contains the data to be added.

### `uBytes`

The number of bytes to write to the file.

## Return value

If the function succeeds, the return value is the number of bytes written to the file. Otherwise, the return value is HFILE_ERROR. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)
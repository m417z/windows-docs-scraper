# _lclose function

## Description

The _lclose function closes the specified file so that it is no longer available for reading or writing. This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the CloseHandle function.

## Parameters

### `hFile`

Identifies the file to be closed. This handle is returned by the function that created or last opened the file.

## Return value

Handle to file to close.
# _lread function

## Description

The _lread function reads data from the specified file. This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the ReadFile function.

## Parameters

### `hFile`

Identifies the specified file.

### `lpBuffer`

Pointer to a buffer that contains the data read from the file.

### `uBytes`

Specifies the number of bytes to be read from the file.

## Return value

The return value indicates the number of bytes actually read from the file. If the number of bytes read is less than uBytes, the function has reached the end of file (EOF) before reading the specified number of bytes.
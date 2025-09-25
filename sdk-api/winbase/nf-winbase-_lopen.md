# _lopen function

## Description

The _lopen function opens an existing file and sets the file pointer to the beginning of the file. This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the CreateFile function.

## Parameters

### `lpPathName`

Pointer to a null-terminated string that names the file to open. The string must consist of characters from the Windows ANSI character set.

### `iReadWrite`

Specifies the modes in which to open the file. This parameter consists of one access mode and an optional share mode. The access mode must be one of the following values: OF_READ, OF_READWRITE, OF_WRITE

The share mode can be one of the following values: OF_SHARE_COMPAT, OF_SHARE_DENY_NONE, OF_SHARE_DENY_READ, OF_SHARE_DENY_WRITE, OF_SHARE_EXCLUSIVE

## Return value

If the function succeeds, the return value is a file handle.
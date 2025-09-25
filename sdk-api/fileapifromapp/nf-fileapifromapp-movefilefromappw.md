## Description

Moves an existing file or a directory, including its children. The behavior of this function is identical to [**MoveFile**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-movefile), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpExistingFileName`

The current name of the file or directory on the local computer.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpNewFileName`

The new name for the file or directory. The new name must not already exist. A new file may be on a different file system or drive. A new directory must be on the same drive.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also
## Description

Deletes an existing empty directory. The behavior of this function is identical to [RemoveDirectory](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-removedirectoryw), except that this function adheres to the Universal Windows Platform (UWP) app security model.

## Parameters

### `lpPathName`

The path of the directory to be removed. This path must specify an empty directory, and the calling process must have delete access to the directory.

For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (`0`). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file)

[RemoveDirectory](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-removedirectoryw)
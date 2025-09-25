## Description

Deletes an existing file. The behavior of this function is identical to [**DeleteFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-deletefilew), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpFileName`

The name of the file to be deleted.
In the ANSI version of this function, the name is limited to **MAX\_PATH** characters. To extend this limit to 32,767 wide characters, call the Unicode version of the function and prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

For the unicode version of this function (**DeleteFileFromAppW**), you can opt-in to remove the **MAX\_PATH** character limitation without prepending "\\\\?\\". See the "Maximum Path Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also
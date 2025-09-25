## Description

Copies an existing file to a new file. The behavior of this function is identical to [**CopyFile**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-copyfile), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpExistingFileName`

The name of an existing file.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

If *lpExistingFileName* does not exist, the function fails, and [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR\_FILE\_NOT\_FOUND**.

### `lpNewFileName`

The name of the new file.

In the ANSI version of this function, the name is limited to **MAX\_PATH** characters. To extend this limit to 32,767 wide characters, call the Unicode version of the function and prepend "\\\\?\\" to the path. For more information, see [Naming a File](https://learn.microsoft.com/windows/win32/FileIO/naming-a-file).

For the unicode version of this function (**CopyFileFromAppW**), you can opt-in to remove the **MAX\_PATH** limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/FileIO/naming-a-file) for details.

### `bFailIfExists`

If this parameter is **TRUE** and the new file specified by *lpNewFileName* already exists, the function fails. If this parameter is **FALSE** and the new file already exists, the function overwrites the existing file and succeeds.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also
## Description

Retrieves attributes for a specified file or directory. The behavior of this function is identical to [GetFileAttributesEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesexw), except that this function adheres to the Universal Windows Platform (UWP) app security model.

## Parameters

### `lpFileName`

The name of the file or directory.

For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `fInfoLevelId`

A class of attribute information to retrieve.

This parameter can be the following value from the [GET\_FILEEX\_INFO\_LEVELS](https://learn.microsoft.com/windows/win32/api/minwinbase/ne-minwinbase-get_fileex_info_levels) enumeration.

| Value | Meaning |
|--------|--------|
| **GetFileExInfoStandard** | The _lpFileInformation_ parameter is a [WIN32_FILE_ATTRIBUTE_DATA](https://learn.microsoft.com/windows/win32/api/fileapi/ns-fileapi-win32_file_attribute_data) structure. |

### `lpFileInformation`

A pointer to a buffer that receives the attribute information.

The type of attribute information that is stored into this buffer is determined by the value of _fInfoLevelId_.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero (`0`). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file)

[GetFileAttributesEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfileattributesexw)
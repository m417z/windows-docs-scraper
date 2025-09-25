## Description

Searches a directory for a file or subdirectory with a name and attributes that match those specified. The behavior of this function is identical to [**FindFirstFileEx**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findfirstfileexw), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpFileName`

The directory or path, and the file name. The file name can include wildcard characters, for example, an asterisk (\*) or a question mark (?).
This parameter should not be **NULL**, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\).

If the string ends with a wildcard, period, or directory name, the user must have access to the root and all subdirectories on the path.

For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `fInfoLevelId`

The information level of the returned data.
This parameter is one of the [**FINDEX\_INFO\_LEVELS**](https://learn.microsoft.com/windows/win32/api/minwinbase/ne-minwinbase-findex_info_levels) enumeration values.

### `lpFindFileData`

A pointer to the buffer that receives the file data.
The pointer type is determined by the level of information that is specified in the *fInfoLevelId* parameter.

### `fSearchOp`

The type of filtering to perform that is different from wildcard matching.
This parameter is one of the [**FINDEX\_SEARCH\_OPS**](https://learn.microsoft.com/windows/win32/api/minwinbase/ne-minwinbase-findex_search_ops) enumeration values.

### `lpSearchFilter`

A pointer to the search criteria if the specified *fSearchOp* needs structured search information.

At this time, none of the supported *fSearchOp* values require extended search information. Therefore, this pointer must be **NULL**.

### `dwAdditionalFlags`

Specifies additional flags that control the search.

| Value | Meaning |
| --- | --- |
| **FIND_FIRST_EX_CASE_SENSITIVE** 1 | Searches are case-sensitive. |
| **FIND_FIRST_EX_LARGE_FETCH** 2 | Uses a larger buffer for directory queries, which can increase performance of the find operation. |
| **FIND_FIRST_EX_ON_DISK_ENTRIES_ONLY** 4 | Limits the results to files that are physically on disk. This flag is only relevant when a file virtualization filter is present. |

## Return value

If the function succeeds, the return value is a search handle used in a subsequent call to [**FindNextFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findnextfilew) or [**FindClose**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findclose), and the *lpFindFileData* parameter contains information about the first file or directory found.

If the function fails or fails to locate files from the search string in the *lpFileName* parameter, the return value is **INVALID\_HANDLE\_VALUE** and the contents of *lpFindFileData* are indeterminate. To get extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

## See also
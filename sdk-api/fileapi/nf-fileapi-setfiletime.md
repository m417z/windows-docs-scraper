# SetFileTime function

## Description

Sets the date and time that the specified file or directory was created, last accessed, or last modified.

## Parameters

### `hFile` [in]

A handle to the file or directory. The handle must have been created using the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function with the **FILE_WRITE_ATTRIBUTES** access right. For more information, see [File Security and Access Rights](https://learn.microsoft.com/windows/win32/FileIO/file-security-and-access-rights).

### `lpCreationTime` [in, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that contains the new creation date and time for the file or directory. If the application does not need to change this information, set this parameter either to `NULL` or to a pointer to a **FILETIME** structure that has both the **dwLowDateTime** and **dwHighDateTime** members set to `0`.

### `lpLastAccessTime` [in, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that contains the new last access date and time for the file or directory. The last access time includes the last time the file or directory was written to, read from, or (in the case of executable files) run. If the application does not need to change this information, set this parameter either to `NULL` or to a pointer to a **FILETIME** structure that has both the **dwLowDateTime** and **dwHighDateTime** members set to `0`.

To prevent file operations using the given handle from modifying the last access time, call **SetFileTime** immediately after opening the file handle and pass a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that has both the **dwLowDateTime** and **dwHighDateTime** members set to `0xFFFFFFFF`.

### `lpLastWriteTime` [in, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that contains the new last modified date and time for the file or directory. If the application does not need to change this information, set this parameter either to `NULL` or to a pointer to a **FILETIME** structure that has both the **dwLowDateTime** and **dwHighDateTime** members set to `0`.

To prevent file operations using the given handle from modifying the last write time, call **SetFileTime** immediately after opening the file handle and pass a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure that has both the **dwLowDateTime** and **dwHighDateTime** members set to `0xFFFFFFFF`.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Not all file systems can record creation and last access times and not all file systems record them in the same manner. For example, on FAT, create time has a resolution of 10 milliseconds, write time has a resolution of 2 seconds, and access time has a resolution of 1 day (really, the access date). Therefore, the [GetFileTime](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfiletime) function may not return the same file time information set using **SetFileTime**. NTFS delays updates to the last access time for a file by up to one hour after the last access.

### Examples

For an example, see [Changing a File Time to the Current Time](https://learn.microsoft.com/windows/win32/SysInfo/changing-a-file-time-to-the-current-time).

## See also

[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime)

[File Times](https://learn.microsoft.com/windows/win32/SysInfo/file-times)

[GetFileSize](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfilesize)

[GetFileTime](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfiletime)

[GetFileType](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getfiletype)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-setfileinformationbyhandle)

[Time Functions](https://learn.microsoft.com/windows/win32/SysInfo/time-functions)
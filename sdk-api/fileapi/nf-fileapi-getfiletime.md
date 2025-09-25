# GetFileTime function

## Description

Retrieves the date and time that a file or directory was created, last accessed, and last
modified.

## Parameters

### `hFile` [in]

A handle to the file or directory for which dates and times are to be retrieved. The handle must have been
created using the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function with the
**GENERIC_READ** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `lpCreationTime` [out, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to receive the
date and time the file or directory was created. This parameter can be **NULL** if the
application does not require this information.

### `lpLastAccessTime` [out, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to
receive the date and time the file or directory was last accessed. The last access time includes the last time
the file or directory was written to, read from, or, in the case of executable files, run. This parameter can be
**NULL** if the application does not require this information.

### `lpLastWriteTime` [out, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to
receive the date and time the file or directory was last written to, truncated, or overwritten (for example,
with [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) or
[SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile)). This date and time is not updated when
file attributes or security descriptors are changed. This parameter can be **NULL** if the
application does not require this information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Not all file systems can record creation and last access times and not all file systems record them in the
same manner. For example, on FAT, create time has a resolution of 10 milliseconds, write time has a resolution of
2 seconds, and access time has a resolution of 1 day (really, the access date). Therefore, the
**GetFileTime** function may not return the same file time
information set using the [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) function.

NTFS delays updates to the last access time for a file by up to one hour after the last access. NTFS also
permits last access time updates to be disabled. Last access time is not updated on NTFS volumes by default.

**Windows Server 2003 and Windows XP:** Last access time is updated on NTFS volumes by default.

For more information, see [File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

If you rename or delete a file, then restore it shortly thereafter, Windows searches the cache for file
information to restore. Cached information includes its short/long name pair and creation time.

#### Examples

For an example, see
[Retrieving the Last-Write Time](https://learn.microsoft.com/windows/desktop/SysInfo/retrieving-the-last-write-time).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times)

[GetFileSize](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesize)

[GetFileType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletype)

[SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)
# SetFilePointerEx function

## Description

Moves the file pointer of the specified file.

## Parameters

### `hFile` [in]

A handle to the file. The file handle must have been created with the
**GENERIC_READ** or **GENERIC_WRITE** access right. For more
information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `liDistanceToMove` [in]

The number of bytes to move the file pointer. A positive value moves the pointer forward in the file and a
negative value moves the file pointer backward.

### `lpNewFilePointer` [out, optional]

A pointer to a variable to receive the new file pointer. If this parameter is
**NULL**, the new file pointer is not returned.

### `dwMoveMethod` [in]

The starting point for the file pointer move. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_BEGIN**<br><br>0 | The starting point is zero or the beginning of the file. If this flag is specified, then the *liDistanceToMove* parameter is interpreted as an unsigned value. |
| **FILE_CURRENT**<br><br>1 | The start point is the current value of the file pointer. |
| **FILE_END**<br><br>2 | The starting point is the current end-of-file position. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The file pointer returned by this function is not used for overlapped read and write operations. To specify
the offset for overlapped operations, use the **Offset** and
**OffsetHigh** members of the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

You cannot use the **SetFilePointerEx** function with a handle to a nonseeking
device such as a pipe or a communications device. To determine the file type for *hFile*,
use the [GetFileType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletype) function.

Use caution when setting the file pointer in a multithreaded application. You must synchronize access to
shared resources. For example, an application whose threads share a file handle, update the file pointer, and read
from the file must protect this sequence by using a critical section object or a mutex object. For more
information about these objects, see
[Critical Section Objects](https://learn.microsoft.com/windows/desktop/Sync/critical-section-objects)
and [Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/mutex-objects).

If the *hFile* handle was opened with the
**FILE_FLAG_NO_BUFFERING** flag set, an application can move the file pointer only to
sector-aligned positions. A sector-aligned position is a position that is a whole number multiple of the volume's
sector size. An application can obtain a volume's sector size by calling the
[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function. If an application
calls **SetFilePointerEx** with distance-to-move values that result in a position
that is not sector-aligned and a handle that was opened with **FILE_FLAG_NO_BUFFERING**, the
function fails, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_INVALID_PARAMETER**. For additional information, see
[File Buffering](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering).

Note that it is not an error to set the file pointer to a position beyond the end of the file. The size of the
file does not increase until you call the [SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile),
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile), or
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) function. A write operation increases the size
of the file to the file pointer position plus the size of the buffer written, which results in the intervening
bytes being zero initialized.

You can use **SetFilePointerEx** to determine the length of a file. To do this,
use **FILE_END** for *dwMoveMethod* and seek to location zero. The
file offset returned is the length of the file. However, this practice can have unintended side effects, such as
failure to save the current file pointer so that the program can return to that location. It is simpler and safer
to use the [GetFileSizeEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesizeex) function instead.

You can also use **SetFilePointerEx** to query the current file pointer position.
To do this, specify a move method of **FILE_CURRENT** and a distance of zero.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa)

[GetFileSizeEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesizeex)

[GetFileType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletype)

[SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)
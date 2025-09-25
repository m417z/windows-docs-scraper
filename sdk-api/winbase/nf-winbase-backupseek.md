# BackupSeek function

## Description

The
**BackupSeek** function seeks forward in a data stream initially accessed by using the
[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread) or
[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite) function.

## Parameters

### `hFile` [in]

Handle to the file or directory. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

The handle must be synchronous (nonoverlapped). This means that the FILE_FLAG_OVERLAPPED flag must not be set when [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) is called. This function does not validate that the handle it receives is synchronous, so it does not return an error code for a synchronous handle, but calling it with an asynchronous (overlapped) handle can result in subtle errors that are very difficult to debug.

### `dwLowBytesToSeek` [in]

Low-order part of the number of bytes to seek.

### `dwHighBytesToSeek` [in]

High-order part of the number of bytes to seek.

### `lpdwLowByteSeeked` [out]

Pointer to a variable that receives the low-order bits of the number of bytes the function actually seeks.

### `lpdwHighByteSeeked` [out]

Pointer to a variable that receives the high-order bits of the number of bytes the function actually seeks.

### `lpContext` [in]

Pointer to an internal data structure used by the function. This structure must be the same structure that was initialized by the
[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread) or [BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite) function. An application must not touch the contents of this structure.

## Return value

If the function could seek the requested amount, the function returns a nonzero value.

If the function could not seek the requested amount, the function returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications use the **BackupSeek** function to skip portions of a data stream that cause errors. This function does not seek across stream headers. For example, this function cannot be used to skip the stream name. If an application attempts to seek past the end of a substream, the function fails, the *lpdwLowByteSeeked* and *lpdwHighByteSeeked* parameters indicate the actual number of bytes the function seeks, and the file position is placed at the start of the next stream header.

## See also

[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread)

[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)
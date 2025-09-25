# BackupWrite function

## Description

The **BackupWrite** function can be used to
restore a file or directory that was backed up using
[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread). Use the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) function to get a stream of data from the backup
medium, then use **BackupWrite** to write the data to the specified file or
directory.

## Parameters

### `hFile` [in]

Handle to the file or directory to be restored. To obtain the handle, call the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. The SACLs are not restored unless the file handle was created with the **ACCESS_SYSTEM_SECURITY** access right. To ensure that the integrity ACEs are restored correctly, the file handle must also have been created with the **WRITE_OWNER** access right. For more information, see [File security and access rights](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights).

The handle must be synchronous (nonoverlapped). This means that the **FILE_FLAG_OVERLAPPED** flag must not be set when [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) is called. This function does not validate that the handle it receives is synchronous, so it does not return an error code for a synchronous handle, but calling it with an asynchronous (overlapped) handle can result in subtle errors that are very difficult to debug.

The **BackupWrite** function may fail if
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) was called with the flag
**FILE_FLAG_NO_BUFFERING**. In this case, the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the value
**ERROR_INVALID_PARAMETER**.

### `lpBuffer` [in]

Pointer to a buffer that the function writes data from.

### `nNumberOfBytesToWrite` [in]

Size of the buffer, in bytes. The buffer size must be greater than the size of a
[WIN32_STREAM_ID](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-win32_stream_id) structure.

### `lpNumberOfBytesWritten` [out]

Pointer to a variable that receives the number of bytes written.

### `bAbort` [in]

Indicates whether you have finished using **BackupWrite** on the handle.
While you are restoring the file, specify this parameter as **FALSE**. After you are done
using **BackupWrite**, you must call **BackupWrite**
one more time specifying **TRUE** for this parameter and passing the appropriate
*lpContext*. *lpContext* must be passed when
*bAbort* is **TRUE**; all other parameters are ignored.

### `bProcessSecurity` [in]

Specifies whether the function will restore the access-control list (ACL) data for the file or directory.

If *bProcessSecurity* is **TRUE**, you need to specify
**WRITE_OWNER** and **WRITE_DAC** access when opening the file or
directory handle. If the handle does not have those access rights, the operating system denies access to the
ACL data, and ACL data restoration will not occur.

### `lpContext` [out]

Pointer to a variable that receives a pointer to an internal data structure used by
**BackupWrite** to maintain context information during a restore operation.

You must set the variable pointed to by *lpContext* to **NULL**
before the first call to **BackupWrite** for the specified file or directory. The
function allocates memory for the data structure, and then sets the variable to point to that structure. You
must not change *lpContext* or the variable that it points to between calls to
**BackupWrite**.

To release the memory used by the data structure, call **BackupWrite** with the
*bAbort* parameter set to **TRUE** when the restore operation is
complete.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero, indicating that an I/O error occurred. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is not intended for use in restoring files encrypted under the
[Encrypted File System](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption). Use
[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw) for that purpose.

The data read from the backup medium must be substreams separated by
[WIN32_STREAM_ID](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-win32_stream_id) structures.

The **BACKUP_LINK** stream type lets you restore files with hard links.

## See also

[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread)

[BackupSeek](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupseek)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[WIN32_STREAM_ID](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-win32_stream_id)

[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw)
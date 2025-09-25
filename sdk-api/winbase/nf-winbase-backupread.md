# BackupRead function

## Description

The **BackupRead** function can be used to back up
a file or directory, including the security information. The function reads data associated with a
specified file or directory into a buffer, which can then be written to the backup medium using the
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) function.

## Parameters

### `hFile` [in]

Handle to the file or directory to be backed up. To obtain the handle, call the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. The SACLs are not read unless the file handle was created with the **ACCESS_SYSTEM_SECURITY** access right. For more information, see [File security and access rights](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights).

The handle must be synchronous (nonoverlapped). This means that the **FILE_FLAG_OVERLAPPED** flag must not be set when [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) is called. This function does not validate that the handle it receives is synchronous, so it does not return an error code for a synchronous handle, but calling it with an asynchronous (overlapped) handle can result in subtle errors that are very difficult to debug.

The **BackupRead** function may fail if
**CreateFile** was called with the flag
**FILE_FLAG_NO_BUFFERING**. In this case, the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the value
**ERROR_INVALID_PARAMETER**.

### `lpBuffer` [out]

Pointer to a buffer that receives the data.

### `nNumberOfBytesToRead` [in]

Length of the buffer, in bytes. The buffer size must be greater than the size of a
[WIN32_STREAM_ID](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-win32_stream_id) structure.

### `lpNumberOfBytesRead` [out]

Pointer to a variable that receives the number of bytes read.

If the function returns a nonzero value, and the variable pointed to by
*lpNumberOfBytesRead* is zero, then all the data associated with the file handle has
been read.

### `bAbort` [in]

Indicates whether you have finished using **BackupRead**
on the handle. While you are backing up the file, specify this parameter as **FALSE**.
Once you are done using **BackupRead**, you must call
**BackupRead** one more time specifying
**TRUE** for this parameter and passing the appropriate
*lpContext*. *lpContext* must be passed when
*bAbort* is **TRUE**; all other parameters are ignored.

### `bProcessSecurity` [in]

Indicates whether the function will restore the access-control list (ACL) data for the file or directory.

If *bProcessSecurity* is **TRUE**, the ACL data will be backed
up.

### `lpContext` [out]

Pointer to a variable that receives a pointer to an internal data structure used by
**BackupRead** to maintain context information during a
backup operation.

You must set the variable pointed to by *lpContext* to **NULL**
before the first call to **BackupRead** for the specified
file or directory. The function allocates memory for the data structure, and then sets the variable to point to
that structure. You must not change *lpContext* or the variable that it points to
between calls to **BackupRead**.

To release the memory used by the data structure, call
**BackupRead** with the
*bAbort* parameter set to **TRUE** when the backup operation is complete.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero, indicating that an I/O error occurred. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is not intended for use in backing up files encrypted under the
Encrypted File System. Use
[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw) for that purpose.

If an error occurs while **BackupRead** is reading data,
the calling process can skip the bad data by calling the
[BackupSeek](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupseek) function.

The file or directory should be restored using the
[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite) function.

## See also

[BackupSeek](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupseek)

[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite)

[Creating a Backup Application](https://learn.microsoft.com/windows/desktop/Backup/creating-a-backup-application)

[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw)

[WIN32_STREAM_ID](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-win32_stream_id)
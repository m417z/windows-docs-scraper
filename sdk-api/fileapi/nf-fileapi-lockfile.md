# LockFile function

## Description

Locks the specified file for exclusive access by the calling process.

To specify additional options, for example creating a shared lock or for block-on-fail operation, use the
[LockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfileex) function.

## Parameters

### `hFile` [in]

A handle to the file. The file handle must have been created with the **GENERIC_READ** or **GENERIC_WRITE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `dwFileOffsetLow` [in]

The low-order 32 bits of the starting byte offset in the file where the lock should begin.

### `dwFileOffsetHigh` [in]

The high-order 32 bits of the starting byte offset in the file where the lock should begin.

### `nNumberOfBytesToLockLow` [in]

The low-order 32 bits of the length of the byte range to be locked.

### `nNumberOfBytesToLockHigh` [in]

The high-order 32 bits of the length of the byte range to be locked.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the call to **LockFile** completes synchronously, a completion entry may not be queued when a completion port is associated with the file handle.

The
[UnlockFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfile) function unlocks a file region locked by
**LockFile**.

Locking a region of a file gives the threads of the locking process exclusive access to the specified region using this file handle. If the file handle is inherited by a process created by the locking process, the child process is not granted access to the locked region. If the locking process opens the file a second time, it cannot access the specified region through this second handle until it unlocks the region.

Locking a region of a file does not prevent reading or writing from a mapped file view.

You can lock bytes that are beyond the end of the current file. This is useful to coordinate adding records to the end of a file.

Exclusive locks cannot overlap an existing locked region of a file. For more information, see [LockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfileex).

If
**LockFile** cannot lock a region of a file, it returns zero immediately. It does not block. To issue a file lock request that will block until the lock is acquired, use
[LockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfileex) without the **LOCKFILE_FAIL_IMMEDIATELY** flag.

If a process terminates with a portion of a file locked or closes a file that has outstanding locks, the locks are unlocked by the operating system. However, the time it takes for the operating system to unlock these locks depends upon available system resources. Therefore, it is recommended that your process explicitly unlock all files it has locked when it terminates. If this is not done, access to these files may be denied if the operating system has not yet unlocked them.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Appending One File to Another File](https://learn.microsoft.com/windows/desktop/FileIO/appending-one-file-to-another-file).

## See also

[Locking and Unlocking Byte Ranges in Files](https://learn.microsoft.com/windows/desktop/FileIO/locking-and-unlocking-byte-ranges-in-files)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[LockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfileex)

[UnlockFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfile)
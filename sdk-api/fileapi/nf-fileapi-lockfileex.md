# LockFileEx function

## Description

Locks the specified file for exclusive access by the calling process. This function can operate either synchronously or asynchronously and can request either an exclusive or a shared lock.

## Parameters

### `hFile` [in]

A handle to the file. The handle must have been created with either the **GENERIC_READ** or **GENERIC_WRITE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `dwFlags` [in]

This parameter may be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LOCKFILE_EXCLUSIVE_LOCK**<br><br>0x00000002 | The function requests an exclusive lock. Otherwise, it requests a shared lock. |
| **LOCKFILE_FAIL_IMMEDIATELY**<br><br>0x00000001 | The function returns immediately if it is unable to acquire the requested lock. Otherwise, it waits. |

### `dwReserved`

Reserved parameter; must be set to zero.

### `nNumberOfBytesToLockLow` [in]

The low-order 32 bits of the length of the byte range to lock.

### `nNumberOfBytesToLockHigh` [in]

The high-order 32 bits of the length of the byte range to lock.

### `lpOverlapped` [in, out]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that the function uses with the locking request. This structure, which is required, contains the file offset of the beginning of the lock range. You must initialize the **hEvent** member to a valid handle or zero.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Locking a region of a file is used to acquire shared or exclusive access to the specified region using this file handle. If the file handle is inherited by a process created by the locking process, the child process is not granted access to the locked region. If the locking process opens the file a second time, it cannot access the specified region through this second handle until it unlocks the region.

Locking a portion of a file for exclusive access denies all other processes both read and write access to the specified region of the file. Locking a region that goes beyond the current end-of-file position is not an error.

Locking a portion of a file for shared access denies all processes write access to the specified region of the file, including the process that first locks the region. All processes can read the locked region.

Locking a region of a file does not prevent reading or writing from a mapped file view.

The
**LockFileEx** function operates asynchronously if the file handle was opened for asynchronous I/O, unless the **LOCKFILE_FAIL_IMMEDIATELY** flag is specified. If an exclusive lock is requested for a range of a file that already has a shared or exclusive lock, the function returns the error **ERROR_IO_PENDING**. The system will signal the event specified in the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure after the lock is granted. To determine when the lock has been granted, use the
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function or one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). For more information, see [Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o).

If the file handle was not opened for asynchronous I/O and the lock is not available, this call waits until the lock is granted or an error occurs, unless the **LOCKFILE_FAIL_IMMEDIATELY** flag is specified.

Exclusive locks cannot overlap an existing locked region of a file. Shared locks can overlap a locked region provided locks held on that region are shared locks. A shared lock can overlap an exclusive lock if both locks were created using the same file handle. When a shared lock overlaps an exclusive lock, the only possible access is a read by the owner of the locks.
If the same range is locked with an exclusive and a shared lock, two unlock operations are necessary to unlock the region; the first unlock operation unlocks the exclusive lock, the second unlock operation unlocks the shared lock.

If a process terminates with a portion of a file locked or closes a file that has outstanding locks, the locks are unlocked by the operating system. However, the time it takes for the operating system to unlock these locks depends upon available system resources. Therefore, it is recommended that your process explicitly unlock all files it has locked when it terminates. If this is not done, access to these files may be denied if the operating system has not yet unlocked them.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[Locking and Unlocking Byte Ranges in Files](https://learn.microsoft.com/windows/desktop/FileIO/locking-and-unlocking-byte-ranges-in-files)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[LockFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfile)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[UnlockFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfile)

[UnlockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfileex)
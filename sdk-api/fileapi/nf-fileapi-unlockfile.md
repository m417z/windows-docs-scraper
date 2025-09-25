# UnlockFile function

## Description

Unlocks a region in an open file. Unlocking a region enables other processes to access the region.

For an alternate way to specify the region, use the
[UnlockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfileex) function.

## Parameters

### `hFile` [in]

A handle to the file that contains a region locked with
[LockFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfile). The file handle must have been created with either the **GENERIC_READ** or **GENERIC_WRITE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `dwFileOffsetLow` [in]

The low-order word of the starting byte offset in the file where the locked region begins.

### `dwFileOffsetHigh` [in]

The high-order word of the starting byte offset in the file where the locked region begins.

### `nNumberOfBytesToUnlockLow` [in]

The low-order word of the length of the byte range to be unlocked.

### `nNumberOfBytesToUnlockHigh` [in]

The high-order word of the length of the byte range to be unlocked.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function always operates synchronously, but may not queue a completion entry when a completion port is associated with the file handle.

Unlocking a region of a file releases a previously acquired lock on the file. The region to unlock must correspond exactly to an existing locked region. Two adjacent regions of a file cannot be locked separately and then unlocked using a single region that spans both locked regions.

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

[UnlockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfileex)
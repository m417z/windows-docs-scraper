# UnlockFileEx function

## Description

Unlocks a region in the specified file. This function can operate either synchronously or
asynchronously.

## Parameters

### `hFile` [in]

A handle to the file. The handle must have been created with either the
**GENERIC_READ** or **GENERIC_WRITE** access right. For more
information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `dwReserved`

Reserved parameter; must be zero.

### `nNumberOfBytesToUnlockLow` [in]

The low-order part of the length of the byte range to unlock.

### `nNumberOfBytesToUnlockHigh` [in]

The high-order part of the length of the byte range to unlock.

### `lpOverlapped` [in, out]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that the
function uses with the unlocking request. This structure contains the file offset of the beginning of the unlock
range. You must initialize the **hEvent** member to a valid handle or zero. For more
information, see
[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero or **NULL**. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Unlocking a region of a file releases a previously acquired lock on the file. The region to unlock must
correspond exactly to an existing locked region. Two adjacent regions of a file cannot be locked separately and
then unlocked using a single region that spans both locked regions.

Locks are released before the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function is
finished processing.

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

[LockFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-lockfileex)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o)

[UnlockFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-unlockfile)
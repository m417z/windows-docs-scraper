# OpenFileById function

## Description

Opens the file that matches the specified identifier.

## Parameters

### `hVolumeHint` [in]

A handle to any file on a volume or share on which the file to be opened is stored.

### `lpFileId` [in]

A pointer to a [FILE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_descriptor) that identifies
the file to open.

### `dwDesiredAccess` [in]

The access to the object. Access can be read, write, or both.

For more information, see
[File Security and Access
Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights). You cannot request an access mode that conflicts with the sharing mode that is specified in an
open request that has an open handle.

If this parameter is zero (0), the application can query file and device attributes without accessing a
device. This is useful for an application to determine the size of a floppy disk drive and the formats it
supports without requiring a floppy in a drive. It can also be used to test for the existence of a file or
directory without opening them for read or write access.

### `dwShareMode` [in]

The sharing mode of an object, which can be read, write, both, or none.

You cannot request a sharing mode that conflicts with the access mode that is specified in an open request
that has an open handle, because that would result in the following sharing violation:
(**ERROR_SHARING_VIOLATION**). For more information, see
[Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files).

If this parameter is zero (0) and **OpenFileById**
succeeds, the object cannot be shared and cannot be opened again until the handle is closed. For more
information, see the Remarks section of this topic.

The sharing options remain in effect until you close the handle to an object.

To enable a processes to share an object while another process has the object open, use a combination of one
or more of the following values to specify the access mode they can request to open the object.

| Value | Meaning |
| --- | --- |
| **FILE_SHARE_DELETE**<br><br>0x00000004 | Enables subsequent open operations on an object to request delete access.<br><br>Otherwise, other processes cannot open the object if they request delete access.<br><br>If this flag is not specified, but the object has been opened for delete access, the function fails. |
| **FILE_SHARE_READ**<br><br>0x00000001 | Enables subsequent open operations on an object to request read access.<br><br>Otherwise, other processes cannot open the object if they request read access.<br><br>If this flag is not specified, but the object has been opened for read access, the function fails. |
| **FILE_SHARE_WRITE**<br><br>0x00000002 | Enables subsequent open operations on an object to request write access.<br><br>Otherwise, other processes cannot open the object if they request write access.<br><br>If this flag is not specified, but the object has been opened for write access or has a file mapping with write access, the function fails. |

### `lpSecurityAttributes` [in, optional]

Reserved.

### `dwFlagsAndAttributes` [in]

The file flags.

When **OpenFileById** opens a file, it combines the file
flags with existing file attributes, and ignores any supplied file attributes. This parameter can include any
combination of the following flags.

| Value | Meaning |
| --- | --- |
| **FILE_FLAG_BACKUP_SEMANTICS**<br><br>0x02000000 | A file is being opened for a backup or restore operation. The system ensures that the calling process overrides file security checks when the process has **SE_BACKUP_NAME** and **SE_RESTORE_NAME** privileges. For more information, see [Changing Privileges in a Token](https://learn.microsoft.com/windows/desktop/SecBP/changing-privileges-in-a-token).<br><br>You must set this flag to obtain a handle to a directory. A directory handle can be passed to some functions instead of a file handle. For more information, see [Directory Handles](https://learn.microsoft.com/windows/desktop/FileIO/obtaining-a-handle-to-a-directory). |
| **FILE_FLAG_NO_BUFFERING**<br><br>0x20000000 | The system opens a file with no system caching. This flag does not affect hard disk caching. When combined with **FILE_FLAG_OVERLAPPED**, the flag gives maximum asynchronous performance, because the I/O does not rely on the synchronous operations of the memory manager. However, some I/O operations take more time, because data is not being held in the cache. Also, the file metadata may still be cached. To flush the metadata to disk, use the [FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) function.<br><br>An application must meet certain requirements when working with files that are opened with **FILE_FLAG_NO_BUFFERING**:<br><br>* File access must begin at byte offsets within a file that are integer multiples of the volume sector   size.<br>* File access must be for numbers of bytes that are integer multiples of the volume sector size. For   example, if the sector size is 512 bytes, an application can request reads and writes of 512, 1024, 1536, or   2048 bytes, but not of 335, 981, or 7171 bytes.<br>* Buffer addresses for read and write operations should be sector aligned, which means aligned on   addresses in memory that are integer multiples of the volume sector size. Depending on the disk, this   requirement may not be enforced.<br><br>One way to align buffers on integer multiples of the volume sector size is to use [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) to allocate the buffers. It allocates memory that is aligned on addresses that are integer multiples of the operating system's memory page size. Because both memory page and volume sector sizes are powers of 2, this memory is also aligned on addresses that are integer multiples of a volume sector size. Memory pages are 4-8 KB in size; sectors are 512 bytes (hard disks) or 2048 bytes (CD), and therefore, volume sectors can never be larger than memory pages.<br><br>An application can determine a volume sector size by calling the [GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function. |
| **FILE_FLAG_OPEN_NO_RECALL**<br><br>0x00100000 | The file data is requested, but it should continue to be located in remote storage. It should not be transported back to local storage. This flag is for use by remote storage systems. |
| **FILE_FLAG_OPEN_REPARSE_POINT**<br><br>0x00200000 | When this flag is used, normal [reparse point](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points) processing does not occur, and **OpenFileById** attempts to open the reparse point. When a file is opened, a file handle is returned, whether or not the filter that controls the reparse point is operational. This flag cannot be used with the **CREATE_ALWAYS** flag. If the file is not a reparse point, then this flag is ignored. |
| **FILE_FLAG_OVERLAPPED**<br><br>0x40000000 | The file is being opened or created for asynchronous I/O. When the operation is complete, the event specified to the call in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure is set to the signaled state. Operations that take a significant amount of time to process return **ERROR_IO_PENDING**.<br><br>If this flag is specified, the file can be used for simultaneous read and write operations. The system does not maintain the file pointer, therefore you must pass the file position to the read and write functions in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure or update the file pointer.<br><br>If this flag is not specified, then I/O operations are serialized, even if the calls to the read and write functions specify an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. |
| **FILE_FLAG_RANDOM_ACCESS**<br><br>0x10000000 | A file is accessed randomly. The system can use this as a hint to optimize file caching. |
| **FILE_FLAG_SEQUENTIAL_SCAN**<br><br>0x08000000 | A file is accessed sequentially from beginning to end. The system can use this as a hint to optimize file caching. If an application moves the file pointer for random access, optimum caching may not occur. However, correct operation is still guaranteed.<br><br>Specifying this flag can increase performance for applications that read large files using sequential access. Performance gains can be even more noticeable for applications that read large files mostly sequentially, but occasionally skip over small ranges of bytes. |
| **FILE_FLAG_WRITE_THROUGH**<br><br>0x80000000 | The system writes through any intermediate cache and goes directly to disk.<br><br>If **FILE_FLAG_NO_BUFFERING** is not also specified, so that system caching is in effect, then the data is written to the system cache, but is flushed to disk without delay.<br><br>If **FILE_FLAG_NO_BUFFERING** is also specified, so that system caching is not in effect, then the data is immediately flushed to disk without going through the system cache. The operating system also requests a write-through the hard disk cache to persistent media. However, not all hardware supports this write-through capability. |

## Return value

If the function succeeds, the return value is an open handle to a specified file.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close an object handle
that **OpenFileById** returns.

If you call **OpenFileById** on a file that is pending
deletion as a result of a previous call to [DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea), the
function fails. The operating system delays file deletion until all handles to the file are closed.
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_ACCESS_DENIED**.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea)

[FILE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_id_descriptor)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)
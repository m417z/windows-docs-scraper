# ReOpenFile function

## Description

Reopens the specified file system object with different access rights, sharing mode, and
flags.

## Parameters

### `hOriginalFile` [in]

A handle to the object to be reopened. The object must have been created by the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwDesiredAccess` [in]

The required access to the object. For a list of values, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights). You
cannot request an access mode that conflicts with the sharing mode specified in a previous open request whose
handle is still open.

If this parameter is zero (0), the application can query device attributes without accessing the device. This
is useful if an application wants to determine the size of a floppy disk drive and the formats it supports
without requiring a floppy in the drive.

### `dwShareMode` [in]

The sharing mode of the object. You cannot request a sharing mode that conflicts with the access mode
specified in a previous open request whose handle is still open.

If this parameter is zero (0) and [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) succeeds,
the object cannot be shared and cannot be opened again until the handle is closed.

To enable other processes to share the object while your process has it open, use a combination of one or
more of the following values to specify the type of access they can request when they open the object. These
sharing options remain in effect until you close the handle to the object.

| Value | Meaning |
| --- | --- |
| **FILE_SHARE_DELETE**<br><br>0x00000004 | Enables subsequent open operations on the object to request delete access. Otherwise, other processes cannot open the object if they request delete access.<br><br>If the object has already been opened with delete access, the sharing mode must include this flag. |
| **FILE_SHARE_READ**<br><br>0x00000001 | Enables subsequent open operations on the object to request read access. Otherwise, other processes cannot open the object if they request read access.<br><br>If the object has already been opened with read access, the sharing mode must include this flag. |
| **FILE_SHARE_WRITE**<br><br>0x00000002 | Enables subsequent open operations on the object to request write access. Otherwise, other processes cannot open the object if they request write access.<br><br>If the object has already been opened with write access, the sharing mode must include this flag. |

### `dwFlagsAndAttributes` [in]

The file flags. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_FLAG_BACKUP_SEMANTICS**<br><br>0x02000000 | Indicates that the file is being opened or created for a backup or restore operation. The system ensures that the calling process overrides file security checks, provided it has the **SE_BACKUP_NAME** and **SE_RESTORE_NAME** privileges. For more information, see [Changing Privileges in a Token](https://learn.microsoft.com/windows/desktop/SecBP/changing-privileges-in-a-token).<br><br>You can also set this flag to obtain a handle to a directory. Where indicated, a directory handle can be passed to some functions in place of a file handle. |
| **FILE_FLAG_DELETE_ON_CLOSE**<br><br>0x04000000 | Indicates that the operating system is to delete the file immediately after all of its handles have been closed, not just the specified handle but also any other open or duplicated handles.<br><br>Subsequent open requests for the file fail, unless **FILE_SHARE_DELETE** is used. |
| **FILE_FLAG_NO_BUFFERING**<br><br>0x20000000 | Instructs the system to open the file with no intermediate buffering or caching. When combined with **FILE_FLAG_OVERLAPPED**, the flag gives maximum asynchronous performance, because the I/O does not rely on the synchronous operations of the memory manager. However, some I/O operations take longer, because data is not being held in the cache.<br><br>An application must meet specific requirements when working with files opened with **FILE_FLAG_NO_BUFFERING**:<br><br>* File access must begin at byte offsets within the file that are integer multiples of the volume sector   size.<br>* File access must be for numbers of bytes that are integer multiples of the volume sector size. For   example, if the sector size is 512 bytes, an application can request reads and writes of 512, 1024, 1536, or   2048 bytes, but not of 335, 981, or 7171 bytes.<br>* Buffer addresses for read and write operations should be sector aligned (aligned on addresses in memory   that are integer multiples of the volume sector size). Depending on the disk, this requirement may not be   enforced.<br><br>One way to align buffers on integer multiples of the volume sector size is to use [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) to allocate the buffers. It allocates memory that is aligned on addresses that are integer multiples of the operating system memory page size. Because both memory page and volume sector sizes are powers of 2, this memory is also aligned on addresses that are integer multiples of a volume sector size. Memory pages are 4-8 KB in size; sectors are 512 bytes (hard disks) or 2048 bytes (CD), and therefore, volume sectors can never be larger than memory pages.<br><br>An application can determine a volume sector size by calling the [GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function. |
| **FILE_FLAG_OPEN_NO_RECALL**<br><br>0x00100000 | Indicates that the file data is requested, but it should continue to reside in remote storage. It should not be transported back to local storage. This flag is intended for use by remote storage systems. |
| **FILE_FLAG_OPEN_REPARSE_POINT**<br><br>0x00200000 | When this flag is used, normal [reparse point](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points) processing does not occur, and **ReOpenFile** attempts to open the reparse point. When a file is opened, a file handle is returned, whether or not the filter that controls the reparse point is operational. This flag cannot be used with the **CREATE_ALWAYS** flag. If the file is not a reparse point, then this flag is ignored. |
| **FILE_FLAG_OVERLAPPED**<br><br>0x40000000 | Instructs the system to initialize the object, so that operations that take a significant amount of time to process return **ERROR_IO_PENDING**. When the operation is finished, the specified event is set to the signaled state.<br><br>When you specify **FILE_FLAG_OVERLAPPED**, the file read and write functions **must** specify an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. That is, when **FILE_FLAG_OVERLAPPED** is specified, an application **must** perform overlapped reading and writing.<br><br>When **FILE_FLAG_OVERLAPPED** is specified, the system does not maintain the file pointer. The file position must be passed as part of the *lpOverlapped* parameter (pointing to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure) to the file read and write functions.<br><br>This flag also enables more than one operation to be performed simultaneously with the handle (a simultaneous read and write operation, for example). |
| **FILE_FLAG_POSIX_SEMANTICS**<br><br>0x01000000 | Indicates that the file is to be accessed according to POSIX rules. This includes allowing multiple files with names, differing only in case, for file systems that support such naming. Use care when using this option because files created with this flag may not be accessible by applications written for MS-DOS or 16-bit Windows. |
| **FILE_FLAG_RANDOM_ACCESS**<br><br>0x10000000 | Indicates that the file is accessed randomly. The system can use this as a hint to optimize file caching. |
| **FILE_FLAG_SEQUENTIAL_SCAN**<br><br>0x08000000 | Indicates that the file is to be accessed sequentially from beginning to end. The system can use this as a hint to optimize file caching. If an application moves the file pointer for random access, optimum caching may not occur; however, correct operation is still guaranteed.<br><br>Specifying this flag can increase performance for applications that read large files using sequential access. Performance gains can be even more noticeable for applications that read large files mostly sequentially, but occasionally skip over small ranges of bytes. |
| **FILE_FLAG_WRITE_THROUGH**<br><br>0x80000000 | Instructs the system to write through any intermediate cache and go directly to disk. The system can still cache write operations, but cannot lazily flush them. |

If the handle represents the client side of a named pipe, the *dwFlags* parameter can
also contain Security Quality of Service information. For more information, see
[Impersonation Levels](https://learn.microsoft.com/windows/desktop/SecAuthZ/impersonation-levels). When the calling
application specifies the **SECURITY_SQOS_PRESENT** flag, the
*dwFlags* parameter can contain one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SECURITY_ANONYMOUS** | Impersonate the client at the Anonymous impersonation level. |
| **SECURITY_CONTEXT_TRACKING** | The security tracking mode is dynamic. If this flag is not specified, the security tracking mode is static. |
| **SECURITY_DELEGATION** | Impersonate the client at the Delegation impersonation level. |
| **SECURITY_EFFECTIVE_ONLY** | Only the enabled aspects of the client security context are available to the server. If you do not specify this flag, all aspects of the client security context are available.<br><br>This allows the client to limit the groups and privileges that a server can use while impersonating the client. |
| **SECURITY_IDENTIFICATION** | Impersonate the client at the Identification impersonation level. |
| **SECURITY_IMPERSONATION** | Impersonate the client at the Impersonation impersonation level. |

## Return value

If the function succeeds, the return value is an open handle to the specified file.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The *dwFlags* parameter cannot contain any of the file attribute flags
(**FILE_ATTRIBUTE_***). These can only be specified when the file is created.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)
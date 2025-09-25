# CreateFileTransactedW function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Creates or opens a file, file stream, or directory as a transacted operation. The function
returns a handle that can be used to access the object.

To perform this operation as a nontransacted
operation or to access objects other than files (for example, named pipes, physical devices, mailslots), use the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

For more information about transactions, see the Remarks section of this topic.

## Parameters

### `lpFileName` [in]

The name of an object to be created or opened.

The object must reside on the local computer; otherwise,
the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

To create a file stream, specify the name of the file, a colon, and then the name of the stream. For more
information, see [File Streams](https://learn.microsoft.com/windows/desktop/FileIO/file-streams).

### `dwDesiredAccess` [in]

The access to the object, which can be summarized as read, write, both or neither (zero). The most commonly
used values are **GENERIC_READ**, **GENERIC_WRITE**, or both
(**GENERIC_READ** | **GENERIC_WRITE**). For more information, see
[Generic Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights) and
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

If this parameter is zero, the application can query file, directory, or device attributes without accessing
that file or device. For more information, see the Remarks section of this topic.

You cannot request an access mode that conflicts with the sharing mode that is specified in an open request
that has an open handle. For more information, see
[Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files).

### `dwShareMode` [in]

The sharing mode of an object, which can be read, write, both, delete, all of these, or none (refer to the
following table).

If this parameter is zero and
**CreateFileTransacted** succeeds, the object cannot
be shared and cannot be opened again until the handle is closed. For more information, see the Remarks section
of this topic.

You cannot request a sharing mode that conflicts with the access mode that is specified in an open request
that has an open handle, because that would result in the following sharing violation:
**ERROR_SHARING_VIOLATION**. For more information, see
[Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files).

To enable a process to share an object while another process has the object open, use a combination of one or
more of the following values to specify the access mode they can request to open the object.

**Note** The sharing options for each open handle remain in effect until that handle is closed, regardless of
process context.

| Value | Meaning |
| --- | --- |
| **0**<br><br>0x00000000 | Disables subsequent open operations on an object to request any type of access to that object. |
| **FILE_SHARE_DELETE**<br><br>0x00000004 | Enables subsequent open operations on an object to request delete access.<br><br>Otherwise, other processes cannot open the object if they request delete access.<br><br>If this flag is not specified, but the object has been opened for delete access, the function fails. |
| **FILE_SHARE_READ**<br><br>0x00000001 | Enables subsequent open operations on an object to request read access.<br><br>Otherwise, other processes cannot open the object if they request read access.<br><br>If this flag is not specified, but the object has been opened for read access, the function fails. |
| **FILE_SHARE_WRITE**<br><br>0x00000002 | Enables subsequent open operations on an object to request write access.<br><br>Otherwise, other processes cannot open the object if they request write access.<br><br>If this flag is not specified, but the object has been opened for write access or has a file mapping with write access, the function fails. |

### `lpSecurityAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that contains an optional
[security descriptor](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) and also determines whether
or not the returned handle can be inherited by child processes. The parameter can be
**NULL**.

If the *lpSecurityAttributes* parameter is **NULL**, the handle
returned by **CreateFileTransacted** cannot be
inherited by any child processes your application may create and the object associated with the returned handle
gets a default security descriptor.

The **bInheritHandle** member of the structure specifies whether the returned handle
can be inherited.

The **lpSecurityDescriptor** member of the structure specifies
a [security descriptor](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) for an object, but may
also be **NULL**.

If **lpSecurityDescriptor** member is **NULL**, the object
associated with the returned handle is assigned a default security descriptor.

**CreateFileTransacted** ignores the
**lpSecurityDescriptor** member when opening an existing file, but continues to use the
**bInheritHandle** member.

For more information, see the Remarks section of this topic.

### `dwCreationDisposition` [in]

An action to take on files that exist and do not exist.

For more information, see the Remarks section of this topic.

This parameter must be one of the following values, which cannot be combined.

| Value | Meaning |
| --- | --- |
| **CREATE_ALWAYS**<br><br>2 | Creates a new file, always.<br><br>If the specified file exists and is writable, the function truncates the file, the function succeeds, and last-error code is set to **ERROR_ALREADY_EXISTS** (183).<br><br>If the specified file does not exist and is a valid path, a new file is created, the function succeeds, and the last-error code is set to zero.<br><br>For more information, see the Remarks section of this topic. |
| **CREATE_NEW**<br><br>1 | Creates a new file, only if it does not already exist.<br><br>If the specified file exists, the function fails and the last-error code is set to **ERROR_FILE_EXISTS** (80).<br><br>If the specified file does not exist and is a valid path to a writable location, a new file is created. |
| **OPEN_ALWAYS**<br><br>4 | Opens a file, always.<br><br>If the specified file exists, the function succeeds and the last-error code is set to **ERROR_ALREADY_EXISTS** (183).<br><br>If the specified file does not exist and is a valid path to a writable location, the function creates a file and the last-error code is set to zero. |
| **OPEN_EXISTING**<br><br>3 | Opens a file or device, only if it exists.<br><br>If the specified file does not exist, the function fails and the last-error code is set to **ERROR_FILE_NOT_FOUND** (2).<br><br>For more information, see the Remarks section of this topic. |
| **TRUNCATE_EXISTING**<br><br>5 | Opens a file and truncates it so that its size is zero bytes, only if it exists.<br><br>If the specified file does not exist, the function fails and the last-error code is set to **ERROR_FILE_NOT_FOUND** (2).<br><br>The calling process must open the file with the **GENERIC_WRITE** bit set as part of the *dwDesiredAccess* parameter. |

### `dwFlagsAndAttributes` [in]

The file attributes and flags, **FILE_ATTRIBUTE_NORMAL** being the most common default
value.

This parameter can include any combination of the available file attributes
(**FILE_ATTRIBUTE_***). All other file attributes override
**FILE_ATTRIBUTE_NORMAL**.

This parameter can also contain combinations of flags (**FILE_FLAG_***) for control of
buffering behavior, access modes, and other special-purpose flags. These combine with any
**FILE_ATTRIBUTE_*** values.

This parameter can also contain Security Quality of Service (SQOS) information by specifying the
**SECURITY_SQOS_PRESENT** flag. Additional SQOS-related flags information is presented in
the table following the attributes and flags tables.

**Note**

When **CreateFileTransacted** opens an existing
file, it generally combines the file flags with the file attributes of the existing file, and ignores any file
attributes supplied as part of *dwFlagsAndAttributes*. Special cases are detailed in
[Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files).

The following file attributes and flags are used only for file objects, not other types of objects that
**CreateFileTransacted** opens (additional
information can be found in the Remarks section of this topic). For more advanced access to file attributes,
see [SetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileattributesa). For a complete list of all
file attributes with their values and descriptions, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

| Attribute | Meaning |
| --- | --- |
| **FILE_ATTRIBUTE_ARCHIVE**<br><br>32 (0x20) | The file should be archived. Applications use this attribute to mark files for backup or removal. |
| **FILE_ATTRIBUTE_ENCRYPTED**<br><br>16384 (0x4000) | The file or directory is encrypted. For a file, this means that all data in the file is encrypted. For a directory, this means that encryption is the default for newly created files and subdirectories. For more information, see [File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption).<br><br>This flag has no effect if **FILE_ATTRIBUTE_SYSTEM** is also specified. |
| **FILE_ATTRIBUTE_HIDDEN**<br><br>2 (0x2) | The file is hidden. Do not include it in an ordinary directory listing. |
| **FILE_ATTRIBUTE_NORMAL**<br><br>128 (0x80) | The file does not have other attributes set. This attribute is valid only if used alone. |
| **FILE_ATTRIBUTE_OFFLINE**<br><br>4096 (0x1000) | The data of a file is not immediately available. This attribute indicates that file data is physically moved to offline storage. This attribute is used by Remote Storage, the hierarchical storage management software. Applications should not arbitrarily change this attribute. |
| **FILE_ATTRIBUTE_READONLY**<br><br>1 (0x1) | The file is read only. Applications can read the file, but cannot write to or delete it. |
| **FILE_ATTRIBUTE_SYSTEM**<br><br>4 (0x4) | The file is part of or used exclusively by an operating system. |
| **FILE_ATTRIBUTE_TEMPORARY**<br><br>256 (0x100) | The file is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient cache memory is available, because an application deletes a temporary file after a handle is closed. In that case, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is closed. |

| Flag | Meaning |
| --- | --- |
| **FILE_FLAG_BACKUP_SEMANTICS**<br><br>0x02000000 | The file is being opened or created for a backup or restore operation. The system ensures that the calling process overrides file security checks when the process has **SE_BACKUP_NAME** and **SE_RESTORE_NAME** privileges. For more information, see [Changing Privileges in a Token](https://learn.microsoft.com/windows/desktop/SecBP/changing-privileges-in-a-token).<br><br>You must set this flag to obtain a handle to a directory. A directory handle can be passed to some functions instead of a file handle. For more information, see [Directory Handles](https://learn.microsoft.com/windows/desktop/FileIO/obtaining-a-handle-to-a-directory). |
| **FILE_FLAG_DELETE_ON_CLOSE**<br><br>0x04000000 | The file is to be deleted immediately after the last transacted writer handle to the file is closed, provided that the transaction is still active. If a file has been marked for deletion and a transacted writer handle is still open after the transaction completes, the file will not be deleted.<br><br>If there are existing open handles to a file, the call fails unless they were all opened with the **FILE_SHARE_DELETE** share mode.<br><br>Subsequent open requests for the file fail, unless the **FILE_SHARE_DELETE** share mode is specified. |
| **FILE_FLAG_NO_BUFFERING**<br><br>0x20000000 | The file is being opened with no system caching. This flag does not affect hard disk caching or memory mapped files. When combined with **FILE_FLAG_OVERLAPPED**, the flag gives maximum asynchronous performance, because the I/O does not rely on the synchronous operations of the memory manager. However, some I/O operations take more time, because data is not being held in the cache. Also, the file metadata may still be cached. To flush the metadata to disk, use the [FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) function.<br><br>An application must meet certain requirements when working with files that are opened with **FILE_FLAG_NO_BUFFERING**:<br><br>* File access must begin at byte offsets within a file that are integer multiples of the volume sector   size.<br>* File access must be for numbers of bytes that are integer multiples of the volume sector size. For   example, if the sector size is 512 bytes, an application can request reads and writes of 512, 1024, 1536,   or 2048 bytes, but not of 335, 981, or 7171 bytes.<br>* Buffer addresses for read and write operations should be sector aligned, which means aligned on   addresses in memory that are integer multiples of the volume sector size. Depending on the disk, this   requirement may not be enforced.<br><br>One way to align buffers on integer multiples of the volume sector size is to use [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) to allocate the buffers. It allocates memory that is aligned on addresses that are integer multiples of the operating system's memory page size. Because both memory page and volume sector sizes are powers of 2, this memory is also aligned on addresses that are integer multiples of a volume sector size. Memory pages are 4 or 8 KB in size; sectors are 512 bytes (hard disks), 2048 bytes (CD), or 4096 bytes (hard disks), and therefore, volume sectors can never be larger than memory pages.<br><br>An application can determine a volume sector size by calling the [GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function. |
| **FILE_FLAG_OPEN_NO_RECALL**<br><br>0x00100000 | The file data is requested, but it should continue to be located in remote storage. It should not be transported back to local storage. This flag is for use by remote storage systems. |
| **FILE_FLAG_OPEN_REPARSE_POINT**<br><br>0x00200000 | Normal [reparse point](https://learn.microsoft.com/windows/desktop/FileIO/reparse-points) processing will not occur; **CreateFileTransacted** will attempt to open the reparse point. When a file is opened, a file handle is returned, whether or not the filter that controls the reparse point is operational. This flag cannot be used with the **CREATE_ALWAYS** flag. If the file is not a reparse point, then this flag is ignored. |
| **FILE_FLAG_OVERLAPPED**<br><br>0x40000000 | The file is being opened or created for asynchronous I/O. When the operation is complete, the event specified in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure is set to the signaled state. Operations that take a significant amount of time to process return **ERROR_IO_PENDING**.<br><br>If this flag is specified, the file can be used for simultaneous read and write operations. The system does not maintain the file pointer, therefore you must pass the file position to the read and write functions in the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure or update the file pointer.<br><br>If this flag is not specified, then I/O operations are serialized, even if the calls to the read and write functions specify an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. |
| **FILE_FLAG_POSIX_SEMANTICS**<br><br>0x01000000 | The file is to be accessed according to POSIX rules. This includes allowing multiple files with names, differing only in case, for file systems that support that naming. Use care when using this option, because files created with this flag may not be accessible by applications that are written for MS-DOS or 16-bit Windows. |
| **FILE_FLAG_RANDOM_ACCESS**<br><br>0x10000000 | The file is to be accessed randomly. The system can use this as a hint to optimize file caching. |
| **FILE_FLAG_SESSION_AWARE**<br><br>0x00800000 | The file or device is being opened with session awareness. If this flag is not specified, then per-session devices (such as a device using RemoteFX USB Redirection) cannot be opened by processes running in session 0. This flag has no effect for callers not in session 0. This flag is supported only on server editions of Windows.<br><br>**Windows Server 2008 R2 and Windows Server 2008:** This flag is not supported before Windows Server 2012. |
| **FILE_FLAG_SEQUENTIAL_SCAN**<br><br>0x08000000 | The file is to be accessed sequentially from beginning to end. The system can use this as a hint to optimize file caching. If an application moves the file pointer for random access, optimum caching may not occur. However, correct operation is still guaranteed.<br><br>Specifying this flag can increase performance for applications that read large files using sequential access. Performance gains can be even more noticeable for applications that read large files mostly sequentially, but occasionally skip over small ranges of bytes.<br><br>This flag has no effect if the file system does not support cached I/O and **FILE_FLAG_NO_BUFFERING**. |
| **FILE_FLAG_WRITE_THROUGH**<br><br>0x80000000 | Write operations will not go through any intermediate cache, they will go directly to disk.<br><br>If **FILE_FLAG_NO_BUFFERING** is not also specified, so that system caching is in effect, then the data is written to the system cache, but is flushed to disk without delay.<br><br>If **FILE_FLAG_NO_BUFFERING** is also specified, so that system caching is not in effect, then the data is immediately flushed to disk without going through the system cache. The operating system also requests a write-through the hard disk cache to persistent media. However, not all hardware supports this write-through capability. |

The *dwFlagsAndAttributes* parameter can also specify Security Quality of Service
information. For more information, see
[Impersonation Levels](https://learn.microsoft.com/windows/desktop/SecAuthZ/impersonation-levels). When the calling
application specifies the **SECURITY_SQOS_PRESENT** flag as part of
*dwFlagsAndAttributes*, it can also contain one or more of the following values.

| Security flag | Meaning |
| --- | --- |
| **SECURITY_ANONYMOUS** | Impersonates a client at the Anonymous impersonation level. |
| **SECURITY_CONTEXT_TRACKING** | The security tracking mode is dynamic. If this flag is not specified, the security tracking mode is static. |
| **SECURITY_DELEGATION** | Impersonates a client at the Delegation impersonation level. |
| **SECURITY_EFFECTIVE_ONLY** | Only the enabled aspects of the client's security context are available to the server. If you do not specify this flag, all aspects of the client's security context are available.<br><br>This allows the client to limit the groups and privileges that a server can use while impersonating the client. |
| **SECURITY_IDENTIFICATION** | Impersonates a client at the Identification impersonation level. |
| **SECURITY_IMPERSONATION** | Impersonate a client at the impersonation level. This is the default behavior if no other flags are specified along with the **SECURITY_SQOS_PRESENT** flag. |

### `hTemplateFile` [in, optional]

A valid handle to a template file with the **GENERIC_READ** access right. The template
file supplies file attributes and extended attributes for the file that is being created. This parameter can be
**NULL**.

When opening an existing file,
**CreateFileTransacted** ignores the template
file.

When opening a new EFS-encrypted file, the file inherits the DACL from its parent directory.

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

### `pusMiniVersion` [in, optional]

The miniversion to be opened. If the transaction specified in *hTransaction* is not
the transaction that is modifying the file, this parameter should be **NULL**. Otherwise,
this parameter can be a miniversion identifier returned by the
[FSCTL_TXFS_CREATE_MINIVERSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_create_miniversion) control
code, or one of the following values.

| Value | Meaning |
| --- | --- |
| **TXFS_MINIVERSION_COMMITTED_VIEW**<br><br>0x0000 | The view of the file as of its last commit. |
| **TXFS_MINIVERSION_DIRTY_VIEW**<br><br>0xFFFF | The view of the file as it is being modified by the transaction. |
| **TXFS_MINIVERSION_DEFAULT_VIEW**<br><br>0xFFFE | Either the committed or dirty view of the file, depending on the context. A transaction that is modifying the file gets the dirty view, while a transaction that is not modifying the file gets the committed view. |

### `lpExtendedParameter`

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is an open handle to the specified file, device, named pipe, or
mail slot.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When using the handle returned by
**CreateFileTransacted**, use the transacted version
of file I/O functions instead of the standard file I/O functions where appropriate. For more information, see
[Programming Considerations for
Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/programming-considerations-for-transacted-fileio-).

When opening a transacted handle to a directory, that handle must have
**FILE_WRITE_DATA** (**FILE_ADD_FILE**) and
**FILE_APPEND_DATA** (**FILE_ADD_SUBDIRECTORY**) permissions. These
are included in **FILE_GENERIC_WRITE** permissions. You should open directories with fewer
permissions if you are just using the handle to create files or subdirectories; otherwise, sharing violations can
occur.

You cannot open a file with **FILE_EXECUTE** access level when that file is a part of
another transaction (that is, another application opened it by calling
**CreateFileTransacted**). This means that
**CreateFileTransacted** fails if the access level
**FILE_EXECUTE** or **FILE_ALL_ACCESS** is specified

When a non-transacted application calls
**CreateFileTransacted** with
**MAXIMUM_ALLOWED** specified for *lpSecurityAttributes*, a handle
is opened with the same access level every time. When a transacted application calls
**CreateFileTransacted** with
**MAXIMUM_ALLOWED** specified for *lpSecurityAttributes*, a handle
is opened with a differing amount of access based on whether the file is locked by a transaction. For example,
if the calling application has **FILE_EXECUTE** access level for a file, the application
only obtains this access if the file that is being opened is either not locked by a transaction, or is locked by
a transaction and the application is already a transacted reader for that file.

See [Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal) for a complete
description of transacted operations.

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close an object handle
returned by **CreateFileTransacted** when the handle
is no longer needed, and prior to committing or rolling back the transaction.

Some file systems, such as the NTFS file system, support compression or encryption for individual files and
directories. On volumes that are formatted for that kind of file system, a new file inherits the compression and
encryption attributes of its directory.

You cannot use **CreateFileTransacted** to control
compression on a file or directory. For more information, see
[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression), and
[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption).

Symbolic link behavior—If the call to this function creates a new file, there is no change
in behavior.

If **FILE_FLAG_OPEN_REPARSE_POINT** is specified:

* If an existing file is opened and it is a symbolic link, the handle returned is a handle to the symbolic
  link.
* If **TRUNCATE_EXISTING** or **FILE_FLAG_DELETE_ON_CLOSE** are
  specified, the file affected is a symbolic link.

If **FILE_FLAG_OPEN_REPARSE_POINT** is not specified:

* If an existing file is opened and it is a symbolic link, the handle returned is a handle to the
  target.
* If **CREATE_ALWAYS**, **TRUNCATE_EXISTING**, or
  **FILE_FLAG_DELETE_ON_CLOSE** are specified, the file affected is the target.

A multi-sector write is not guaranteed to be atomic unless you are using a transaction (that is, the handle
created is a transacted handle). A single-sector write is atomic. Multi-sector writes that are cached may not
always be written to the disk; therefore, specify **FILE_FLAG_WRITE_THROUGH** to ensure that
an entire multi-sector write is written to the disk without caching.

As stated previously, if the *lpSecurityAttributes* parameter is
**NULL**, the handle returned by
**CreateFileTransacted** cannot be inherited by any
child processes your application may create. The following information regarding this parameter also applies:

* If **bInheritHandle** is not **FALSE**, which is any nonzero
  value, then the handle can be inherited. Therefore it is critical this structure member be properly initialized
  to **FALSE** if you do not intend the handle to be inheritable.
* The access control lists (ACL) in the default security descriptor for a file or directory are inherited
  from its parent directory.
* The target file system must support security on files and directories for the
  **lpSecurityDescriptor** to have an effect on them, which can be determined by using
  [GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

Note that SMB 3.0 does not support TxF.

### Files

If you try to create a file on a floppy drive that does not have a floppy disk or a CD-ROM drive that does not
have a CD, the system displays a message for the user to insert a disk or a CD. To prevent the system from
displaying this message, call the [SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) function
with **SEM_FAILCRITICALERRORS**.

For more information, see
[Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files).

If you rename or delete a file and then restore it shortly afterward, the system searches the cache for file
information to restore. Cached information includes its short/long name pair and creation time.

If you call **CreateFileTransacted** on a file that
is pending deletion as a result of a previous call to
[DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea), the function fails. The operating system
delays file deletion until all handles to the file are closed.
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_ACCESS_DENIED**.

The *dwDesiredAccess* parameter can
be zero, allowing the application to query file attributes without accessing the file if the application is
running with adequate security settings. This is useful to test for the existence of a file without opening it
for read and/or write access, or to obtain other statistics about the file or directory. See
[Obtaining and Setting File Information](https://learn.microsoft.com/windows/desktop/FileIO/obtaining-and-setting-file-information)
and [GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle).

When an application creates a file across a network, it is better to use
**GENERIC_READ** | **GENERIC_WRITE** than to use
**GENERIC_WRITE** alone. The resulting code is faster, because the redirector can use the
cache manager and send fewer SMBs with more data. This combination also avoids an issue where writing to a file
across a network can occasionally return **ERROR_ACCESS_DENIED**.

### File Streams

On NTFS file systems, you can use
**CreateFileTransacted** to create separate streams
within a file.

For more information, see
[File Streams](https://learn.microsoft.com/windows/desktop/FileIO/file-streams).

### Directories

An application cannot create a directory by using
**CreateFileTransacted**, therefore only the
**OPEN_EXISTING** value is valid for *dwCreationDisposition* for
this use case. To create a directory, the application must call
[CreateDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectorytransacteda),
[CreateDirectory](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createdirectorya) or
[CreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectoryexa).

To open a directory using **CreateFileTransacted**,
specify the **FILE_FLAG_BACKUP_SEMANTICS** flag as part of
*dwFlagsAndAttributes*. Appropriate security checks still apply when this flag is used
without **SE_BACKUP_NAME** and **SE_RESTORE_NAME** privileges.

When using **CreateFileTransacted** to open a
directory during defragmentation of a FAT or FAT32 file system volume, do not specify the
**MAXIMUM_ALLOWED** access right. Access to the directory is denied if this is done.
Specify the **GENERIC_READ** access right instead.

For more information, see
[About Directory Management](https://learn.microsoft.com/windows/desktop/FileIO/about-directory-management).

> [!NOTE]
> The winbase.h header defines CreateFileTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CopyFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfiletransacteda)

[CreateDirectoryTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createdirectorytransacteda)

[DeleteFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deletefiletransacteda)

[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights)

[File Streams](https://learn.microsoft.com/windows/desktop/FileIO/file-streams)

[FindFirstFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfiletransacteda)

**Functions**

[GetFileAttributesTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileattributestransacteda)

[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda)

**Overview Topics**

[Programming Considerations for Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/programming-considerations-for-transacted-fileio-)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[Transactional NTFS (TxF)](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)
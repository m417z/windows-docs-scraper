## Description

Creates or opens a file or I/O device. The behavior of this function is identical to [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpFileName`

The name of the file or device to be created or opened. You may use either forward slashes (/) or backslashes (\\) in this name.
In the ANSI version of this function, the name is limited to **MAX\_PATH** characters. To extend this limit to 32,767 wide characters, call the Unicode version of the function and prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

For information on special device names, see [Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/win32/fileio/defining-an-ms-dos-device-name).

To create a file stream, specify the name of the file, a colon, and then the name of the stream. For more information, see [File Streams](https://learn.microsoft.com/windows/win32/fileio/file-streams).

For the unicode version of this function (**CreateFileFromAppW**), you can opt-in to remove the **MAX\_PATH** limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwDesiredAccess`

The requested access to the file or device, which can be summarized as read, write, both or neither zero).

The most commonly used values are **GENERIC\_READ**, **GENERIC\_WRITE**, or both (`GENERIC_READ | GENERIC_WRITE`). For more information, see [Generic Access Rights](https://learn.microsoft.com/windows/win32/secauthz/generic-access-rights), [File Security and Access Rights](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights), [**File Access Rights Constants**](https://learn.microsoft.com/windows/win32/fileio/file-access-rights-constants), and [**ACCESS\_MASK**](https://learn.microsoft.com/windows/win32/secauthz/access-mask).

If this parameter is zero, the application can query certain metadata such as file, directory, or device attributes without accessing that file or device, even if **GENERIC\_READ** access would have been denied.

You cannot request an access mode that conflicts with the sharing mode that is specified by the *dwShareMode* parameter in an open request that already has an open handle.

### `dwShareMode`

 The requested sharing mode of the file or device, which can be read, write, both, delete, all of these, or none (refer to the following table). Access requests to attributes or extended attributes are not affected by this flag.

| Value | Meaning |
| --- | --- |
| **0** 0x00000000 | Prevents other processes from opening a file or device if they request delete, read, or write access. |
| **FILE_SHARE_DELETE** 0x00000004 | Enables subsequent open operations on a file or device to request delete access.<br><br>Otherwise, other processes cannot open the file or device if they request delete access.<br><br>If this flag is not specified, but the file or device has been opened for delete access, the function fails.<br><br>**Note** Delete access allows both delete and rename operations. |
| **FILE_SHARE_READ** 0x00000001 | Enables subsequent open operations on a file or device to request read access.<br><br>Otherwise, other processes cannot open the file or device if they request read access.<br><br>If this flag is not specified, but the file or device has been opened for read access, the function fails. |
| **FILE_SHARE_WRITE** 0x00000002 | Enables subsequent open operations on a file or device to request write access.<br><br>Otherwise, other processes cannot open the file or device if they request write access.<br><br>If this flag is not specified, but the file or device has been opened for write access or has a file mapping with write access, the function fails. |

### `lpSecurityAttributes`

A pointer to a [**SECURITY\_ATTRIBUTES**](https://docs.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that contains two separate but related data members: an optional security descriptor, and a Boolean value that determines whether the returned handle can be inherited by child processes.
This parameter can be **NULL**.

If this parameter is **NULL**, the handle returned cannot be inherited by any child processes the application may create and the file or device associated with the returned handle gets a default security descriptor.

The **lpSecurityDescriptor** member of the structure specifies a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) for a file or device. If this member is **NULL**, the file or device associated with the returned handle is assigned a default security descriptor.

This function ignores the **lpSecurityDescriptor** member when opening an existing file or device, but continues to use the **bInheritHandle** member.

The **bInheritHandle** member of the structure specifies whether the returned handle can be inherited.

### `dwCreationDisposition`

 An action to take on a file or device that exists or does not exist.
For devices other than files, this parameter is usually set to **OPEN\_EXISTING**.

For more information, see the Remarks section.

This parameter must be one of the following values, which cannot be combined:

| Value | Meaning |
| --- | --- |
| **CREATE_ALWAYS** 2 | Creates a new file, always.<br><br>If the specified file exists and is writable, the function truncates the file, the function succeeds, and last-error code is set to **ERROR_ALREADY_EXISTS** (183).<br><br>If the specified file does not exist and is a valid path, a new file is created, the function succeeds, and the last-error code is set to zero.<br><br>For more information, see the Remarks section of this topic. |
| **CREATE_NEW** 1 | Creates a new file, only if it does not already exist.<br><br>If the specified file exists, the function fails and the last-error code is set to **ERROR_FILE_EXISTS** (80).<br><br>If the specified file does not exist and is a valid path to a writable location, a new file is created. |
| **OPEN_ALWAYS** 4 | Opens a file, always.<br><br>If the specified file exists, the function succeeds and the last-error code is set to **ERROR_ALREADY_EXISTS** (183).<br><br>If the specified file does not exist and is a valid path to a writable location, the function creates a file and the last-error code is set to zero. |
| **OPEN_EXISTING** 3 | Opens a file or device, only if it exists.<br><br>If the specified file or device does not exist, the function fails and the last-error code is set to **ERROR_FILE_NOT_FOUND** (2).<br><br>For more information about devices, see the Remarks section. |
| **TRUNCATE_EXISTING** 5 | Opens a file and truncates it so that its size is zero bytes, only if it exists.<br><br>If the specified file does not exist, the function fails and the last-error code is set to **ERROR_FILE_NOT_FOUND** (2).<br><br>The calling process must open the file with the **GENERIC_WRITE** bit set as part of the *dwDesiredAccess* parameter. |

### `dwFlagsAndAttributes`

The file or device attributes and flags, **FILE\_ATTRIBUTE\_NORMAL** being the most common default value for files.
This parameter can include any combination of the available file attributes (**FILE\_ATTRIBUTE\_\***). All other file attributes override **FILE\_ATTRIBUTE\_NORMAL**.

This parameter can also contain combinations of flags (**FILE\_FLAG\_\***) for control of file or device caching behavior, access modes, and other special-purpose flags. These combine with any **FILE\_ATTRIBUTE\_\*** values.

This parameter can also contain Security Quality of Service (SQOS) information by specifying the **SECURITY\_SQOS\_PRESENT** flag. Additional SQOS-related flags information is presented in the table following the attributes and flags tables.

| Attribute | Meaning |
| --- | --- |
| **FILE_ATTRIBUTE_ARCHIVE** 32 (0x20) | The file should be archived. Applications use this attribute to mark files for backup or removal. |
| **FILE_ATTRIBUTE_ENCRYPTED** 16384 (0x4000) | The file or directory is encrypted. For a file, this means that all data in the file is encrypted. For a directory, this means that encryption is the default for newly created files and subdirectories. For more information, see [**File Encryption**](https://learn.microsoft.com/windows/win32/fileio/file-encryption).<br><br>This flag has no effect if **FILE_ATTRIBUTE_SYSTEM** is also specified.<br><br>This flag is not supported on Home, Home Premium, Starter, or ARM editions of Windows. |
| **FILE_ATTRIBUTE_HIDDEN** 2 (0x2) | The file is hidden. Do not include it in an ordinary directory listing. |
| **FILE_ATTRIBUTE_NORMAL** 128 (0x80) | The file does not have other attributes set. This attribute is valid only if used alone. |
| **FILE_ATTRIBUTE_OFFLINE** 4096 (0x1000) | The data of a file is not immediately available. This attribute indicates that file data is physically moved to offline storage. This attribute is used by Remote Storage, the hierarchical storage management software. Applications should not arbitrarily change this attribute. |
| **FILE_ATTRIBUTE_READONLY** 1 (0x1) | The file is read only. Applications can read the file, but cannot write to or delete it. |
| **FILE_ATTRIBUTE_SYSTEM** 4 (0x4) | The file is part of or used exclusively by an operating system. |
| **FILE_ATTRIBUTE_TEMPORARY** 256 (0x100) | The file is being used for temporary storage.<br><br>For more information, see the Caching Behavior section of this topic. |

| Flag | Meaning |
| --- | --- |
| **FILE_FLAG_BACKUP_SEMANTICS** 0x02000000 | The file is being opened or created for a backup or restore operation. The system ensures that the calling process overrides file security checks when the process has **SE_BACKUP_NAME** and **SE_RESTORE_NAME** privileges. For more information, see [Changing Privileges in a Token](https://learn.microsoft.com/windows/win32/secbp/changing-privileges-in-a-token).<br><br>You must set this flag to obtain a handle to a directory. A directory handle can be passed to some functions instead of a file handle. For more information, see the Remarks section. |
| **FILE_FLAG_DELETE_ON_CLOSE** 0x04000000 | The file is to be deleted immediately after all of its handles are closed, which includes the specified handle and any other open or duplicated handles.<br><br>If there are existing open handles to a file, the call fails unless they were all opened with the **FILE_SHARE_DELETE** share mode.<br><br>Subsequent open requests for the file fail, unless the **FILE_SHARE_DELETE** share mode is specified. |
| **FILE_FLAG_NO_BUFFERING** 0x20000000 | The file or device is being opened with no system caching for data reads and writes. This flag does not affect hard disk caching or memory mapped files.<br><br>There are strict requirements for successfully working with files opened with this function using the **FILE_FLAG_NO_BUFFERING** flag, for details see [File Buffering](https://learn.microsoft.com/windows/win32/fileio/file-buffering). |
| **FILE_FLAG_OPEN_NO_RECALL** 0x00100000 | The file data is requested, but it should continue to be located in remote storage. It should not be transported back to local storage. This flag is for use by remote storage systems. |
| **FILE_FLAG_OPEN_REPARSE_POINT** 0x00200000 | Normal [reparse point](https://learn.microsoft.com/windows/win32/fileio/reparse-points) processing will not occur; this function will attempt to open the reparse point. When a file is opened, a file handle is returned, whether or not the filter that controls the reparse point is operational.<br><br>This flag cannot be used with the **CREATE_ALWAYS** flag.<br><br>If the file is not a reparse point, then this flag is ignored.<br><br>For more information, see the Remarks section. |
| **FILE_FLAG_OVERLAPPED** 0x40000000 | The file or device is being opened or created for asynchronous I/O.<br><br>When subsequent I/O operations are completed on this handle, the event specified in the [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure will be set to the signaled state.<br><br>If this flag is specified, the file can be used for simultaneous read and write operations.<br><br>If this flag is not specified, then I/O operations are serialized, even if the calls to the read and write functions specify an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.<br><br>For information about considerations when using a file handle created with this flag, see the Synchronous and Asynchronous I/O Handles section of this topic. |
| **FILE_FLAG_POSIX_SEMANTICS** 0x0100000 | Access will occur according to POSIX rules. This includes allowing multiple files with names, differing only in case, for file systems that support that naming. Use care when using this option, because files created with this flag may not be accessible by applications that are written for MS-DOS or 16-bit Windows. |
| **FILE_FLAG_RANDOM_ACCESS** 0x10000000 | Access is intended to be random. The system can use this as a hint to optimize file caching.<br><br>This flag has no effect if the file system does not support cached I/O and **FILE_FLAG_NO_BUFFERING**.<br><br>For more information, see the Caching Behavior section of this topic. |
| **FILE_FLAG_SESSION_AWARE** 0x00800000 | The file or device is being opened with session awareness. If this flag is not specified, then per-session devices (such as a device using RemoteFX USB Redirection) cannot be opened by processes running in session 0. This flag has no effect for callers not in session 0. This flag is supported only on server editions of Windows. |
| **FILE_FLAG_SEQUENTIAL_SCAN** 0x08000000 | Access is intended to be sequential from beginning to end. The system can use this as a hint to optimize file caching.<br><br>This flag should not be used if read-behind (that is, reverse scans) will be used.<br><br>This flag has no effect if the file system does not support cached I/O and **FILE_FLAG_NO_BUFFERING**.<br><br>For more information, see the Caching Behavior section of this topic. |
| **FILE_FLAG_WRITE_THROUGH** 0x80000000 | Write operations will not go through any intermediate cache, they will go directly to disk.<br><br>For additional information, see the Caching Behavior section of this topic. |

The *dwFlagsAndAttributes*parameter can also specify SQOS information. For more information, see [Impersonation Levels](https://learn.microsoft.com/windows/win32/secauthz/impersonation-levels). When the calling application specifies the **SECURITY\_SQOS\_PRESENT** flag as part of *dwFlagsAndAttributes*, it can also contain one or more of the following values.

| Security flag | Meaning |
| --- | --- |
| **SECURITY_ANONYMOUS** | Impersonates a client at the Anonymous impersonation level. |
| **SECURITY_CONTEXT_TRACKING** | The security tracking mode is dynamic. If this flag is not specified, the security tracking mode is static. |
| **SECURITY_DELEGATION** | Impersonates a client at the Delegation impersonation level. |
| **SECURITY_EFFECTIVE_ONLY** | Only the enabled aspects of the client's security context are available to the server. If you do not specify this flag, all aspects of the client's security context are available.<br><br>This allows the client to limit the groups and privileges that a server can use while impersonating the client. |
| **SECURITY_IDENTIFICATION** | Impersonates a client at the Identification impersonation level. |
| **SECURITY_IMPERSONATION** | Impersonate a client at the impersonation level. This is the default behavior if no other flags are specified along with the **SECURITY_SQOS_PRESENT** flag. |

### `hTemplateFile`

 A valid handle to a template file with the **GENERIC\_READ** access right. The template file supplies file attributes and extended attributes for the file that is being created.
This parameter can be **NULL**.

When opening an existing file, this parameter is ignored.

When opening a new encrypted file, the file inherits the discretionary access control list from its parent directory. For more information, see [File Encryption](https://learn.microsoft.com/windows/win32/fileio/file-encryption).

## Return value

If the function succeeds, the return value is an open handle to the specified file, device, named pipe, or mail slot.

If the function fails, the return value is **INVALID\_HANDLE\_VALUE**. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also
# NtCreateFile function

## Description

Creates a new file or directory, or opens an existing file, device, directory, or volume.

This function is the user-mode equivalent to the **ZwCreateFile** function documented in the Windows Driver Kit (WDK).

## Parameters

### `FileHandle` [out]

A pointer to a variable that receives the file handle if the call is successful.

### `DesiredAccess` [in]

The **ACCESS_MASK** value that expresses the type of access that the caller requires to the file or directory. The set of system-defined *DesiredAccess* flags determines the following specific access rights for file objects.

| Value | Meaning |
| --- | --- |
| **DELETE** | The file can be deleted. |
| **FILE_READ_DATA** | Data can be read from the file. |
| **FILE_READ_ATTRIBUTES** | *FileAttributes* flags, described later, can be read. |
| **FILE_READ_EA** | Extended attributes associated with the file can be read. This flag is irrelevant to device and intermediate drivers. |
| **READ_CONTROL** | The access control list (ACL) and ownership information associated with the file can be read. |
| **FILE_WRITE_DATA** | Data can be written to the file. |
| **FILE_WRITE_ATTRIBUTES** | *FileAttributes* flags can be written. |
| **FILE_WRITE_EA** | Extended attributes (EAs) associated with the file can be written. This flag is irrelevant to device and intermediate drivers. |
| **FILE_APPEND_DATA** | Data can be appended to the file. |
| **WRITE_DAC** | The discretionary access control list (DACL) associated with the file can be written. |
| **WRITE_OWNER** | Ownership information associated with the file can be written. |
| **SYNCHRONIZE** | The returned *FileHandle* can be waited on to synchronize with the completion of an I/O operation. If *FileHandle* was not opened for synchronous I/O, this value is ignored. |
| **FILE_EXECUTE** | Data can be read into memory from the file using system paging I/O. This flag is irrelevant for device and intermediate drivers. |

Do not specify **FILE_READ_DATA**, **FILE_WRITE_DATA**, **FILE_APPEND_DATA**, or **FILE_EXECUTE** when you create or open a directory.

Callers of **NtCreateFile** can specify one or a combination of the following, possibly using a bitwise-OR with additional compatible flags from the preceding *DesiredAccess* flags list, for any file object that does not represent a directory file.

| Value | Meaning |
| --- | --- |
| **FILE_GENERIC_READ** | `STANDARD_RIGHTS_READ \| FILE_READ_DATA \| FILE_READ_ATTRIBUTES \| FILE_READ_EA \| SYNCHRONIZE` |
| **FILE_GENERIC_WRITE** | `STANDARD_RIGHTS_WRITE \| FILE_WRITE_DATA \| FILE_WRITE_ATTRIBUTES \| FILE_WRITE_EA \| FILE_APPEND_DATA \| SYNCHRONIZE` |
| **FILE_GENERIC_EXECUTE** | `STANDARD_RIGHTS_EXECUTE \| FILE_READ_ATTRIBUTES \| FILE_EXECUTE \| SYNCHRONIZE` |

The **FILE_GENERIC_EXECUTE** value is irrelevant for device and intermediate drivers.

The **STANDARD_RIGHTS_***XXX* are predefined system values used to enforce security on system objects.

To open or create a directory file, as also indicated with the *CreateOptions* parameter, callers of **NtCreateFile** can specify one or a combination of the following, possibly using a bitwise-OR with one or more compatible flags from the preceding *DesiredAccess* flags list.

| Value | Meaning |
| --- | --- |
| **FILE_LIST_DIRECTORY** | Files in the directory can be listed. |
| **FILE_TRAVERSE** | The directory can be traversed: that is, it can be part of the pathname of a file. |

### `ObjectAttributes` [in]

A pointer to a structure already initialized with **InitializeObjectAttributes**. Members of this structure for a file object include the following.

| Value | Meaning |
| --- | --- |
| **ULONG Length** | Specifies the number of bytes of *ObjectAttributes* data supplied. This value must be at least sizeof(OBJECT_ATTRIBUTES). |
| **HANDLE RootDirectory** | Optionally specifies a handle to a directory obtained by a preceding call to **NtCreateFile**. If this value is **NULL**, the **ObjectName** member must be a fully qualified file specification that includes the full path to the target file. If this value is non-**NULL**, the **ObjectName** member specifies a file name relative to this directory. |
| **PUNICODE_STRING ObjectName** | Points to a buffered Unicode string that names the file to be created or opened. This value must be a fully qualified file specification or the name of a device object, unless it is the name of a file relative to the directory specified by **RootDirectory**. For example, \Device\Floppy1\myfile.dat or \??\B:\myfile.dat could be the fully qualified file specification, provided that the floppy driver and overlying file system are already loaded. For more information, see [File Names, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file). |
| **ULONG Attributes** | Is a set of flags that controls the file object attributes. This value can be zero or **OBJ_CASE_INSENSITIVE**, which indicates that name-lookup code should ignore the case of the **ObjectName** member rather than performing an exact-match search. The value **OBJ_INHERIT** is irrelevant to device and intermediate drivers. |
| **PSECURITY_DESCRIPTOR SecurityDescriptor** | Optionally specifies a security descriptor to be applied to a file. ACLs specified by such a security descriptor are applied to the file only when it is created. If the value is **NULL** when a file is created, the ACL placed on the file is file-system-dependent; most file systems propagate some part of such an ACL from the parent directory file combined with the caller's default ACL. Device and intermediate drivers can set this member to **NULL**. |
| **PSECURITY_QUALITY_OF_SERVICE SecurityQualityOfService** | Specifies the access rights a server should be given to the client's security context. This value is non-**NULL** only when a connection to a protected server is established, allowing the caller to control which parts of the caller's security context are made available to the server and whether the server is allowed to impersonate the caller. |

### `IoStatusBlock` [out]

A pointer to a variable that receives the final completion status and information about the requested operation. On return from **NtCreateFile**, the **Information** member contains one of the following values:

* **FILE_CREATED**
* **FILE_OPENED**
* **FILE_OVERWRITTEN**
* **FILE_SUPERSEDED**
* **FILE_EXISTS**
* **FILE_DOES_NOT_EXIST**

### `AllocationSize` [in, optional]

The initial allocation size in bytes for the file. A nonzero value has no effect unless the file is being created, overwritten, or superseded.

### `FileAttributes` [in]

The file attributes. Explicitly specified attributes are applied only when the file is created, superseded, or, in some cases, overwritten. By default, this value is a **FILE_ATTRIBUTE_NORMAL**, which can be overridden by an ORed combination of one or more **FILE_ATTRIBUTE_***xxxx* flags, which are defined in Wdm.h and NtDdk.h. For a list of flags that can be used with **NtCreateFile**, see **CreateFile**.

### `ShareAccess` [in]

The type of share access that the caller would like to use in the file, as zero, or as one or a combination of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_SHARE_READ** | The file can be opened for read access by other threads' calls to **NtCreateFile**. |
| **FILE_SHARE_WRITE** | The file can be opened for write access by other threads' calls to **NtCreateFile**. |
| **FILE_SHARE_DELETE** | The file can be opened for delete access by other threads' calls to **NtCreateFile**. |

For more information, see the Windows SDK.

### `CreateDisposition` [in]

Specifies what to do, depending on whether the file already exists, as one of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_SUPERSEDE** | If the file already exists, replace it with the given file. If it does not, create the given file. |
| **FILE_CREATE** | If the file already exists, fail the request and do not create or open the given file. If it does not, create the given file. |
| **FILE_OPEN** | If the file already exists, open it instead of creating a new file. If it does not, fail the request and do not create a new file. |
| **FILE_OPEN_IF** | If the file already exists, open it. If it does not, create the given file. |
| **FILE_OVERWRITE** | If the file already exists, open it and overwrite it. If it does not, fail the request. |
| **FILE_OVERWRITE_IF** | If the file already exists, open it and overwrite it. If it does not, create the given file. |

### `CreateOptions` [in]

The options to be applied when creating or opening the file, as a compatible combination of the following flags.

| Value | Meaning |
| --- | --- |
| **FILE_DIRECTORY_FILE** | The file being created or opened is a directory file. With this flag, the *CreateDisposition* parameter must be set to **FILE_CREATE**, **FILE_OPEN**, or **FILE_OPEN_IF**. With this flag, other compatible *CreateOptions* flags include only the following: **FILE_SYNCHRONOUS_IO_ALERT**, **FILE_SYNCHRONOUS_IO _NONALERT**, **FILE_WRITE_THROUGH**, **FILE_OPEN_FOR_BACKUP_INTENT**, and **FILE_OPEN_BY_FILE_ID**. |
| **FILE_NON_DIRECTORY_FILE** | The file being opened must not be a directory file or this call fails. The file object being opened can represent a data file, a logical, virtual, or physical device, or a volume. |
| **FILE_WRITE_THROUGH** | Applications that write data to the file must actually transfer the data into the file before any requested write operation is considered complete. This flag is automatically set if the *CreateOptions* flag **FILE_NO_INTERMEDIATE _BUFFERING** is set. |
| **FILE_SEQUENTIAL_ONLY** | All accesses to the file are sequential. |
| **FILE_RANDOM_ACCESS** | Accesses to the file can be random, so no sequential read-ahead operations should be performed on the file by FSDs or the system. |
| **FILE_NO_INTERMEDIATE_BUFFERING** | The file cannot be cached or buffered in a driver's internal buffers. This flag is incompatible with the *DesiredAccess* **FILE_APPEND_DATA** flag. |
| **FILE_SYNCHRONOUS_IO_ALERT** | All operations on the file are performed synchronously. Any wait on behalf of the caller is subject to premature termination from alerts. This flag also causes the I/O system to maintain the file position context. If this flag is set, the *DesiredAccess* **SYNCHRONIZE** flag also must be set. |
| **FILE_SYNCHRONOUS_IO_NONALERT** | All operations on the file are performed synchronously. Waits in the system to synchronize I/O queuing and completion are not subject to alerts. This flag also causes the I/O system to maintain the file position context. If this flag is set, the *DesiredAccess* **SYNCHRONIZE** flag also must be set. |
| **FILE_CREATE_TREE_CONNECTION** | Create a tree connection for this file in order to open it over the network. This flag is not used by device and intermediate drivers. |
| **FILE_NO_EA_KNOWLEDGE** | If the extended attributes on an existing file being opened indicate that the caller must understand EAs to properly interpret the file, fail this request because the caller does not understand how to deal with EAs. This flag is irrelevant for device and intermediate drivers. |
| **FILE_OPEN_REPARSE_POINT** | Open a file with a reparse point and bypass normal reparse point processing for the file. For more information, see the Remarks section. |
| **FILE_DELETE_ON_CLOSE** | Delete the file when the last handle to it is passed to **NtClose**. If this flag is set, the DELETE flag must be set in the *DesiredAccess* parameter. |
| **FILE_OPEN_BY_FILE_ID** | The file name that is specified by the *ObjectAttributes* parameter includes the 8-byte file reference number for the file. This number is assigned by and specific to the particular file system. If the file is a reparse point, the file name will also include the name of a device. Note that the FAT file system does not support this flag. This flag is not used by device and intermediate drivers. |
| **FILE_OPEN_FOR_BACKUP_INTENT** | The file is being opened for backup intent. Therefore, the system should check for certain access rights and grant the caller the appropriate access to the file before checking the *DesiredAccess* parameter against the file's security descriptor. This flag not used by device and intermediate drivers. |
| **FILE_RESERVE_OPFILTER** | This flag allows an application to request a filter [opportunistic lock](https://learn.microsoft.com/windows/win32/fileio/opportunistic-locks) to prevent other applications from getting share violations. If there are already open handles, the create request will fail with **STATUS_OPLOCK_NOT_GRANTED**. For more information, see the Remarks section. |
| **FILE_OPEN_REQUIRING_OPLOCK** | The file is being opened and an [opportunistic lock](https://learn.microsoft.com/windows/win32/fileio/opportunistic-locks) on the file is being requested as a single atomic operation. The file system checks for oplocks before it performs the create operation and will fail the create with a return code of **STATUS_CANNOT_BREAK_OPLOCK** if the result would be to break an existing oplock. For more information, see the Remarks section.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported.<br><br>This flag is supported on the following file systems: NTFS, FAT, and exFAT. |
| **FILE_COMPLETE_IF_OPLOCKED** | Complete this operation immediately with an alternate success code of **STATUS_OPLOCK_BREAK_IN_PROGRESS** if the target file is oplocked, rather than blocking the caller's thread. If the file is [oplocked](https://learn.microsoft.com/windows/win32/fileio/opportunistic-locks), another caller already has access to the file. This flag is not used by device and intermediate drivers. |

### `EaBuffer` [in]

Pointer to an EA buffer used to pass extended attributes.

**Note** Some file systems may not support EA buffers.

### `EaLength` [in]

Length of the EA buffer.

## Return value

**NtCreateFile** returns either **STATUS_SUCCESS** or an appropriate error status. If it returns an error status, the caller can find more information about the cause of the failure by checking the *IoStatusBlock*. To simplify this check, an application can use the **NT_SUCCESS**, **NT_ERROR**, and **NT_WARNING** macros.

## Remarks

The handle, given by **NtCreateFile**, can be used by subsequent calls to manipulate data within the file or the file object's state or attributes.

There are two alternate ways to specify the name of the file to be created or opened with **NtCreateFile**:

* As a fully qualified pathname, supplied in the **ObjectName** member of the input *ObjectAttributes*
* As a pathname relative to the directory file represented by the handle in the **RootDirectory** member of the input *ObjectAttributes*

Certain *DesiredAccess* flags and combinations of flags have the following effects:

* For a caller to synchronize an I/O completion by waiting on the returned *FileHandle*, the **SYNCHRONIZE** flag must be set.
* Passing a zero to *DesiredAccess* is not valid.
* If only the **FILE_APPEND_DATA** and **SYNCHRONIZE** flags are set, the caller can write only to the end of the file, and any offset information on writes to the file is ignored. However, the file is automatically extended as necessary for this type of write operation.
* Setting the **FILE_WRITE_DATA** flag for a file also allows writes beyond the end of the file to occur. The file is automatically extended for this type of write, as well.
* If only the **FILE_EXECUTE** and **SYNCHRONIZE** flags are set, the caller cannot directly read or write any data in the file using the returned *FileHandle*, that is, all operations on the file occur through the system pager in response to instruction and data accesses.

The *ShareAccess* parameter determines whether separate threads can access the same file, possibly simultaneously. Provided that both file openers have the privilege to access a file in the specified manner, the file can be successfully opened and shared. If the original caller of **NtCreateFile** does not specify **FILE_SHARE_READ**, **FILE_SHARE_WRITE**, or **FILE_SHARE_DELETE**, no other open operations can be performed on the file; that is, the original caller is given exclusive access to the file.

For a shared file to be successfully opened, the requested *DesiredAccess* parameter to the file must be compatible with both the *DesiredAccess* and *ShareAccess* specifications of all preceding opens that have not yet been released with **NtClose**. That is, the *DesiredAccess* parameter specified to **NtCreateFile** for a given file must not conflict with the accesses that other openers of the file have disallowed.

The *CreateDisposition* value **FILE_SUPERSEDE** requires that the caller have **DELETE** access to an existing file object. If so, a successful call to **NtCreateFile** with **FILE_SUPERSEDE** on an existing file effectively deletes that file, and then re-creates it. This implies that, if the file has already been opened by another thread, it opened the file by specifying a *ShareAccess* parameter with the **FILE_SHARE_DELETE** flag set.

Note that this type of disposition is consistent with the POSIX style of overwriting files. The *CreateDisposition* values **FILE_OVERWRITE_IF** and **FILE_SUPERSEDE** are similar. If **ZwCreateFile** is called with an existing file and either of these *CreateDisposition* values, the file is replaced.

Overwriting a file is semantically equivalent to a supersede operation, except for the following:

* The caller must have write access to the file, rather than delete access. This implies that, if the file has already been opened by another thread, it opened the file with the **FILE_SHARE_WRITE** flag set in the input *ShareAccess* parameter.
* The specified file attributes are logically ORed with those already on the file. This implies that, if the file has already been opened by another thread, a subsequent caller of **NtCreateFile** cannot disable existing *FileAttributes* flags but can enable additional flags for the same file. Note that this style of overwriting files is consistent with MS-DOS, Windows 3.1, and OS/2 operating systems.

The *CreateOptions* **FILE_DIRECTORY_FILE** value specifies that the file to be created or opened is a
directory file. When a directory file is created, the file system creates an appropriate structure on the disk to
represent an empty directory for that particular file system's on-disk structure. If this option was specified
and the given file to be opened is not a directory file, or if the caller specified an inconsistent
*CreateOptions* or *CreateDisposition* value, the call to
**NtCreateFile** fails.

The *CreateOptions* **FILE_NO_INTERMEDIATE_BUFFERING** flag prevents the file system from performing any
intermediate buffering on behalf of the caller. Specifying this value places certain restrictions on the caller's
parameters to other **Nt*XXX*File** routines, including the
following:

* Any optional *ByteOffset* passed to the
  **NtReadFile** or **NtWriteFile** function must be an
  integral of the sector size.
* The *Length* passed to **NtReadFile** or
  **NtWriteFile**, must be an integral of the sector size. Note that specifying a
  read operation to a buffer whose length is exactly the sector size might result in a lesser number of
  significant bytes being transferred to that buffer if the end of the file was reached during the transfer.
* Buffers must be adjusted in accordance with the alignment requirement of the underlying device. This
  information can be obtained by calling **NtCreateFile**
  to get a handle for the file object that represents the physical device, and then calling
  **NtQueryInformationFile** with that handle. For a list of the system
  **FILE_***XXX***_ALIGNMENT** values, see
  the Windows SDK documentation.
* Calls to **NtSetInformationFile** with the
  *FileInformationClass* parameter set to
  **FilePositionInformation** must specify an offset that is an integral of the
  sector size.

The *CreateOptions* **FILE_SYNCHRONOUS_IO_ALERT** and **FILE_SYNCHRONOUS_IO_NONALERT** flags,
which are mutually exclusive as their names suggest, specify that all I/O operations on the file are to be
synchronous as long as they occur through the file object referred to by the returned
*FileHandle*. All I/O on such a file is serialized across all threads using the returned
handle. With either of these *CreateOptions*, the *DesiredAccess* **SYNCHRONIZE** flag must be set so that the I/O Manager uses the
file object as a synchronization object. With either of these *CreateOptions* set, the
I/O Manager maintains the "file position context" for the file object, an internal, current file position offset.
This offset can be used in calls to **NtReadFile** and
**NtWriteFile**. Its position also can be queried or set with
**NtQueryInformationFile** and
**NtSetInformationFile**.

If the *CreateOptions* parameter specifies the **FILE_OPEN_REPARSE_POINT** flag and **NtCreateFile** opens a file with a reparse point, normal reparse processing does not occur and **NtCreateFile** attempts to directly open the reparse point file. If the **FILE_OPEN_REPARSE_POINT** flag is not specified, normal reparse point processing occurs for the file. In either case, if the open operation was successful, **NtCreateFile** returns **STATUS_SUCCESS**; otherwise, an error code. The **NtCreateFile** function never returns **STATUS_REPARSE**.

The *CreateOptions* parameter's **FILE_OPEN_REQUIRING_OPLOCK** flag eliminates the time between when you open the file and request an oplock that could potentially allow a third party to open the file, which would cause a sharing violation. An application can use the **FILE_OPEN_REQUIRING_OPLOCK** flag with **NtCreateFile** and then request any oplock. This ensures that an oplock owner will be notified of any subsequent open request that causes a sharing violation.

In Windows 7, if other handles exist on the file when an application uses this flag, the create operation will fail with **STATUS_OPLOCK_NOT_GRANTED**. This restriction no longer exists starting with Windows 8.

If this create operation would break an oplock that already exists on the file, then setting the **FILE_OPEN_REQUIRING_OPLOCK** flag will cause the create operation to fail with **STATUS_CANNOT_BREAK_OPLOCK**. The existing oplock will not be broken by this create operation.

An application that uses the FILE_OPEN_REQUIRING_OPLOCK flag must request an oplock on the file after this call succeeds, or all subsequent attempts to open the file will be blocked without the benefit of normal oplock processing. Similarly, if this call succeeds but the subsequent oplock request fails, an application that uses this flag must close its handle after it detects that the oplock request has failed. The application must not perform any other file system operation on the file before requsting the oplock (besides closing the file handle), otherwise a deadlock may occur.

**Note** The **FILE_OPEN_REQUIRING_OPLOCK** flag is available in Windows 7, Windows Server 2008 R2 and later operating systems for the following file systems: NTFS, FAT, and exFAT.

The *CreateOptions* parameter's **FILE_RESERVE_OPFILTER** flag allows an application to request a Level 1, Batch, or Filter oplock to prevent other applications from getting share violations. However, in practical terms, the **FILE_RESERVE_OPFILTER** is useful only for filter oplocks. To use it, you must complete the following steps:

1. Issue a create request with *CreateOptions* of **FILE_RESERVE_OPFILTER**, *DesiredAccess* of exactly **FILE_READ_ATTRIBUTES**, and *ShareAccess* of exactly `(FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE)`. Possible failures are as follows:
   * If there are already open handles, the create request fails with **STATUS_OPLOCK_NOT_GRANTED**, and the next requested oplock also fails.
   * If you open with more access than **FILE_READ_ATTRIBUTES** or less sharing than `(FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE)`, the request fails with **STATUS_OPLOCK_NOT_GRANTED**.
2. If the create request succeeds, request an oplock.
3. Open another handle to the file to do I/O.

Step three makes this practical only for filter oplocks. The handle opened in step three can have a *DesiredAccess* that contains a maximum of `(FILE_READ_ATTRIBUTES | FILE_WRITE_ATTRIBUTES | FILE_READ_DATA | FILE_READ_EA | FILE_EXECUTE | SYNCHRONIZE | READ_CONTROL)` and still not break a filter oplock. However, any *DesiredAccess* greater than `(FILE_READ_ATTRIBUTES | FILE_WRITE_ATTRIBUTES | SYNCHRONIZE)` will break a Level 1 or Batch oplock and make the **FILE_RESERVE_OPFILTER** flag useless for those oplock types.

NTFS is the only Microsoft file system that implements **FILE_RESERVE_OPFILTER**.

For more information on oplocks, see [Opportunistic Locks](https://learn.microsoft.com/windows/win32/fileio/opportunistic-locks).

Note that the WDK header file NtDef.h is necessary for many constant definitions. You can also use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to NtDll.dll.
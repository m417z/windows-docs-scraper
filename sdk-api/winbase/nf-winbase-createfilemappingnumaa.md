# CreateFileMappingNumaA function

## Description

Creates or opens a named or unnamed file mapping object for a specified file and specifies the NUMA
node for the physical memory.

## Parameters

### `hFile` [in]

A handle to the file from which to create a file mapping object.

The file must be opened with access
rights that are compatible with the protection flags that the *flProtect* parameter
specifies. It is not required, but it is recommended that files you intend to map be opened for exclusive
access. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

If *hFile* is **INVALID_HANDLE_VALUE**, the calling process
must also specify a size for the file mapping object in the *dwMaximumSizeHigh* and
*dwMaximumSizeLow* parameters. In this scenario,
**CreateFileMappingNuma** creates a file mapping
object of a specified size that is backed by the system paging file instead of by a file in the file
system.

### `lpFileMappingAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that determines whether a returned handle can be inherited by child processes. The
**lpSecurityDescriptor** member of the
**SECURITY_ATTRIBUTES** structure specifies a
security descriptor for a new file mapping object.

If *lpFileMappingAttributes* is **NULL**, the handle cannot be
inherited and the file mapping object gets a default security descriptor. The access control lists (ACL) in the
default security descriptor for a file mapping object come from the primary or impersonation token of the
creator. For more information, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights).

### `flProtect` [in]

Specifies the page protection of the file mapping object. All mapped views of the object must be compatible
with this protection.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PAGE_EXECUTE_READ**<br><br>0x20 | Allows views to be mapped for read-only, copy-on-write, or execute access.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** and **GENERIC_EXECUTE** access rights. |
| **PAGE_EXECUTE_READWRITE**<br><br>0x40 | Allows views to be mapped for read-only, copy-on-write, read/write or execute access.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ**, **GENERIC_WRITE**, and **GENERIC_EXECUTE** access rights. |
| **PAGE_EXECUTE_WRITECOPY**<br><br>0x80 | Allows views to be mapped for read-only, copy-on-write, or execute access. This value is equivalent to **PAGE_EXECUTE_READ**.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** and **GENERIC_EXECUTE** access rights.<br><br>**Windows Vista:** This value is not available until Windows Vista with SP1. |
| **PAGE_READONLY**<br><br>0x02 | Allows views to be mapped for read-only or copy-on-write access. An attempt to write to a specific region results in an access violation.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** access right. |
| **PAGE_READWRITE**<br><br>0x04 | Allows views to be mapped for read-only, copy-on-write, or read/write access.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** and **GENERIC_WRITE** access rights. |
| **PAGE_WRITECOPY**<br><br>0x08 | Allows views to be mapped for read-only or copy-on-write access. This value is equivalent to **PAGE_READONLY**.<br><br>The file handle that the *hFile* parameter specifies must be created with the **GENERIC_READ** access right. |

An application can specify one or more of the following attributes for the file mapping object by combining
them with one of the preceding page protection values.

| Value | Meaning |
| --- | --- |
| **SEC_COMMIT**<br><br>0x8000000 | Allocates physical storage in memory or the paging file for all pages. <br><br>This is the default setting. |
| **SEC_IMAGE**<br><br>0x1000000 | Sets the file that is specified to be an executable image file.<br><br>The **SEC_IMAGE** attribute must be combined with a page protection value such as **PAGE_READONLY**. However, this page protection value has no effect on views of the executable image file. Page protection for views of an executable image file is determined by the executable file itself.<br><br>No other attributes are valid with **SEC_IMAGE**. |
| **SEC_IMAGE_NO_EXECUTE**<br><br>0x11000000 | Specifies that the file that the *hFile* parameter specifies is an executable image file that will not be executed and the loaded image file will have no forced integrity checks run. Additionally, mapping a view of a file mapping object created with the **SEC_IMAGE_NO_EXECUTE** attribute will not invoke driver callbacks registered using the [PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-pssetloadimagenotifyroutine) kernel API.<br><br>The **SEC_IMAGE_NO_EXECUTE** attribute must be combined with the **PAGE_READONLY** page protection value. No other attributes are valid with **SEC_IMAGE_NO_EXECUTE**.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This value is not supported before Windows Server 2012 and Windows 8. |
| **SEC_LARGE_PAGES**<br><br>0x80000000 | Enables large pages to be used when mapping images or backing from the pagefile, but not when mapping data for regular files. Be sure to specify the maximum size of the file mapping object as the minimum size of a large page reported by the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function and to enable the [SeLockMemoryPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) privilege. |
| **SEC_NOCACHE**<br><br>0x10000000 | Sets all pages to noncachable.<br><br>Applications should not use this flag except when explicitly required for a device. Using the interlocked functions with memory mapped with **SEC_NOCACHE** can result in an **EXCEPTION_ILLEGAL_INSTRUCTION** exception.<br><br>**SEC_NOCACHE** requires either **SEC_RESERVE** or **SEC_COMMIT** to be set. |
| **SEC_RESERVE**<br><br>0x4000000 | Reserves all pages without allocating physical storage.<br><br>The reserved range of pages cannot be used by any other allocation operations until the range of pages is released.<br><br>Reserved pages can be identified in subsequent calls to the [VirtualAllocExNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocexnuma) function. This attribute is valid only if the *hFile* parameter is **INVALID_HANDLE_VALUE** (that is, a file mapping object that is backed by the system paging file). |
| **SEC_WRITECOMBINE**<br><br>0x40000000 | Sets all pages to be write-combined.<br><br>Applications should not use this attribute except when explicitly required for a device. Using the interlocked functions with memory that is mapped with **SEC_WRITECOMBINE** can result in an **EXCEPTION_ILLEGAL_INSTRUCTION** exception.<br><br>**SEC_WRITECOMBINE** requires either the **SEC_RESERVE** or **SEC_COMMIT** attribute to be set. |

### `dwMaximumSizeHigh` [in]

The high-order **DWORD** of the maximum size of the file mapping object.

### `dwMaximumSizeLow` [in]

The low-order **DWORD** of the maximum size of the file mapping object.

If this parameter and the *dwMaximumSizeHigh* parameter are 0 (zero), the maximum
size of the file mapping object is equal to the current size of the file that the
*hFile* parameter identifies.

An attempt to map a file with a length of 0 (zero) fails with an error code of
**ERROR_FILE_INVALID**. Applications should test for files with a length of 0 (zero) and
reject those files.

### `lpName` [in, optional]

The name of the file mapping object.

If this parameter matches the name of an existing file mapping object, the function requests access to the
object with the protection that the *flProtect* parameter specifies.

If this parameter is **NULL**, the file mapping object is created without a name.

If the *lpName* parameter matches the name of an existing event, semaphore, mutex,
waitable timer, or job object, the function fails and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
**ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the
object in the global or session namespace. The remainder of the name can contain any character except the
backslash character (\\). Creating a file mapping object in the global namespace requires the
[SeCreateGlobalPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants)
privilege. For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

Fast user switching is implemented by using Terminal Services sessions. The first user to log on uses
session 0 (zero), the next user to log on uses session 1 (one), and so on. Kernel object names must follow the
guidelines so that applications can support multiple users.

### `nndPreferred` [in]

The NUMA node where the physical memory should reside.

| Value | Meaning |
| --- | --- |
| **NUMA_NO_PREFERRED_NODE**<br><br>0xffffffff | No NUMA node is preferred. This is the same as calling the [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) function. |

## Return value

If the function succeeds, the return value is a handle to the file mapping object.

If the object exists
before the function call, the function returns a handle to the existing object (with its current size, not the
specified size) and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_ALREADY_EXISTS**.

If the function fails, the return value is **NULL**. To get extended error information,
call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

After a file mapping object is created, the size of the file must not exceed the size of the file mapping
object; if it does, not all of the file contents are available for sharing.

The file mapping object can be shared by duplication, inheritance, or by name. The initial contents of the
pages in a file mapping object backed by the page file are 0 (zero).

If an application specifies a size for the file mapping object that is larger than the size of the actual
named file on disk and if the page protection allows write access (that is, the
*flProtect* parameter specifies **PAGE_READWRITE** or
**PAGE_EXECUTE_READWRITE**), then the file on disk is increased to match the specified size
of the file mapping object. If the file is extended, the contents of the file between the old end of the file and
the new end of the file are not guaranteed to be zero; the behavior is defined by the file system.

If the file cannot be increased, the result is a failure to create the file mapping object and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
**ERROR_DISK_FULL**.

The handle that the **CreateFileMappingNuma**
function returns has full access to a new file mapping object and can be used with any function that requires a
handle to a file mapping object. A file mapping object can be shared through process creation, handle duplication,
or by name. For more information, see the
[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) and
[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga) functions.

Creating a file mapping object creates the potential for mapping a view of the file but does not map the view.
The [MapViewOfFileExNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapviewoffileexnuma) function maps a view of a
file into a process address space.

With one important exception, file views derived from a single file mapping object are coherent or identical
at a specific time. If multiple processes have handles of the same file mapping object, they see a coherent view
of the data when they map a view of the file.

The exception is related to remote files. Although the
**CreateFileMappingNuma** function works with remote
files, it does not keep them coherent. For example, if two computers both map a file as writable and both change
the same page, each computer sees only its own writes to the page. When the data gets updated on the disk, the
page is not merged.

A mapped file and a file that is accessed by using the input and output (I/O) functions
([ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)) are not necessarily coherent.

To fully close a file mapping object, an application must unmap all mapped views of the file mapping object by
calling the [UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) function and then close
the file mapping object handle by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)
function.

These functions can be called in any order. The call to the
[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) function is necessary, because mapped
views of a file mapping object maintain internal open handles to the object, and a file mapping object does not
close until all open handles to it are closed.

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically.
If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the
timestamp.

Creating a file-mapping object from a session other than session zero requires the
[SeCreateGlobalPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) privilege.
Note that this privilege check is limited to the creation of file mapping objects and does not apply to opening
existing ones. For example, if a service or the system creates a file mapping object, any process running in any
session can access that file mapping object provided that the caller has the required access rights.

Use structured exception handling to protect any code that writes to or reads from a memory mapped view. For
more information, see
[Reading and Writing From a File View](https://learn.microsoft.com/windows/desktop/Memory/reading-and-writing-from-a-file-view).

To have a mapping with executable permissions, an application must call the
**CreateFileMappingNuma** function with either
**PAGE_EXECUTE_READWRITE** or **PAGE_EXECUTE_READ** and then call the
[MapViewOfFileExNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapviewoffileexnuma) function with
`FILE_MAP_EXECUTE | FILE_MAP_WRITE` or
`FILE_MAP_EXECUTE | FILE_MAP_READ`.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[File Mapping Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[MapViewOfFileExNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapviewoffileexnuma)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)

[VirtualAllocExNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocexnuma)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)
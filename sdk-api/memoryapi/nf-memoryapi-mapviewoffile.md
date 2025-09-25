# MapViewOfFile function

## Description

Maps a view of a file mapping into the address space of a calling process.

To specify a suggested base address for the view, use the
[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex) function. However, this practice is
not recommended.

## Parameters

### `hFileMappingObject` [in]

A handle to a file mapping object. The
[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) and
[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga) functions return this handle.

### `dwDesiredAccess` [in]

The type of access to a file mapping object, which determines the page protection of the pages. This
parameter can be one of the following values, or a bitwise OR combination of multiple values where appropriate.

| Value | Meaning |
| --- | --- |
| **FILE_MAP_ALL_ACCESS** | A read/write view of the file is mapped. The file mapping object must have been created with **PAGE_READWRITE** or **PAGE_EXECUTE_READWRITE** protection.<br><br>When used with the **MapViewOfFile** function, **FILE_MAP_ALL_ACCESS** is equivalent to **FILE_MAP_WRITE**. |
| **FILE_MAP_READ** | A read-only view of the file is mapped. An attempt to write to the file view results in an access violation.<br><br>The file mapping object must have been created with **PAGE_READONLY**, **PAGE_READWRITE**, **PAGE_EXECUTE_READ**, or **PAGE_EXECUTE_READWRITE** protection. |
| **FILE_MAP_WRITE** | A read/write view of the file is mapped. The file mapping object must have been created with **PAGE_READWRITE** or **PAGE_EXECUTE_READWRITE** protection.<br><br>When used with **MapViewOfFile**, (**FILE_MAP_WRITE** | **FILE_MAP_READ**) and **FILE_MAP_ALL_ACCESS** are equivalent to **FILE_MAP_WRITE**. |

Using bitwise OR, you can combine the values above with these values.

| Value | Meaning |
| --- | --- |
| **FILE_MAP_COPY** | A copy-on-write view of the file is mapped. The file mapping object must have been created with **PAGE_READONLY**, **PAGE_EXECUTE_READ**, **PAGE_WRITECOPY**, **PAGE_EXECUTE_WRITECOPY**, **PAGE_READWRITE**, or **PAGE_EXECUTE_READWRITE** protection.<br><br>When a process writes to a copy-on-write page, the system copies the original page to a new page that is private to the process. The new page is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.<br><br>When copy-on-write access is specified, the system and process commit charge taken is for the entire view because the calling process can potentially write to every page in the view, making all pages private. The contents of the new page are never written back to the original file and are lost when the view is unmapped. |
| **FILE_MAP_EXECUTE** | An executable view of the file is mapped (mapped memory can be run as code). The file mapping object must have been created with **PAGE_EXECUTE_READ**, **PAGE_EXECUTE_WRITECOPY**, or **PAGE_EXECUTE_READWRITE** protection.<br><br>**Windows Server 2003 and Windows XP:** This value is available starting with Windows XP with SP2 and Windows Server 2003 with SP1. |
| **FILE_MAP_LARGE_PAGES** | Starting with Windows 10, version 1703, this flag specifies that the view should be mapped using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support). The size of the view must be a multiple of the size of a large page reported by the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function, and the file-mapping object must have been created using the **SEC_LARGE_PAGES** option. If you provide a non-null value for *lpBaseAddress*, then the value must be a multiple of **GetLargePageMinimum**.\ \ **Note:** On OS versions before Windows 10, version 1703, the **FILE_MAP_LARGE_PAGES** flag has no effect. On these releases, the view is automatically mapped using large pages if the section was created with the **SEC_LARGE_PAGES** flag set. |
| **FILE_MAP_TARGETS_INVALID** | Sets all the locations in the mapped file as invalid targets for Control Flow Guard (CFG). This flag is similar to **PAGE_TARGETS_INVALID**. Use this flag in combination with the execute access right **FILE_MAP_EXECUTE**. Any indirect call to locations in those pages will fail CFG checks, and the process will be terminated. The default behavior for executable pages allocated is to be marked valid call targets for CFG. |

For file mapping objects created with the **SEC_IMAGE** attribute, the
*dwDesiredAccess* parameter has no effect, and should be set to any valid value such as
**FILE_MAP_READ**.

For more information about access to file mapping objects, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights).

### `dwFileOffsetHigh` [in]

A high-order **DWORD** of the file offset where the view begins.

### `dwFileOffsetLow` [in]

A low-order **DWORD** of the file offset where the view is to begin. The combination
of the high and low offsets must specify an offset within the file mapping. They must also match the virtual memory
allocation granularity of the system. That is, the offset must be a multiple of the VirtualAlloc allocation granularity. To
obtain the VirtualAlloc memory allocation granularity of the system, use the
[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function, which fills in the members of
a [SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info) structure.

### `dwNumberOfBytesToMap` [in]

The number of bytes of a file mapping to map to the view. All bytes must be within the maximum size specified
by [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga). If this parameter is 0
(zero), the mapping extends from the specified offset to the end of the file mapping.

## Return value

If the function succeeds, the return value is the starting address of the mapped view.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Mapping a file makes the specified portion of a file visible in the address space of the calling process.

For files that are larger than the address space, you can only map a small portion of the file data at one
time. When the first view is complete, you can unmap it and map a new view.

To obtain the size of a view, use the [VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)
function.

Multiple views of a file (or a file mapping object and its mapped file) are *coherent*
if they contain identical data at a specified time. This occurs if the file views are derived from any file
mapping object that is backed by the same file. A process can duplicate a file mapping object handle into another
process by using the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function, or
another process can open a file mapping object by name by using the
[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga) function.

With one important exception, file views derived from any file mapping object that is backed by the same file
are coherent or identical at a specific time. Coherency is guaranteed for views within a process and for views
that are mapped by different processes.

The exception is related to remote files. Although
**MapViewOfFile** works with remote files, it does not keep
them coherent. For example, if two computers both map a file as writable, and both change the same page, each
computer only sees its own writes to the page. When the data gets updated on the disk, it is not merged.

A mapped view of a file is not guaranteed to be coherent with a file that is being accessed by the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) or
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) function.

Do not store pointers in the memory mapped file; store offsets from the base of the file mapping so that the
mapping can be used at any address.

To guard against **EXCEPTION_IN_PAGE_ERROR**
exceptions, use structured exception handling to protect any code that writes to or reads from a memory mapped
view of a file other than the page file. For more information, see
[Reading and Writing From a File View](https://learn.microsoft.com/windows/desktop/Memory/reading-and-writing-from-a-file-view).

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically.
If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the
timestamp.

If a file mapping object is backed by the paging file
([CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) is called with the
*hFile* parameter set to **INVALID_HANDLE_VALUE**), the paging file
must be large enough to hold the entire mapping. If it is not,
**MapViewOfFile** fails. The initial contents of the pages
in a file mapping object backed by the paging file are 0 (zero).

When a file mapping object that is backed by the paging file is created, the caller can specify whether
**MapViewOfFile** should reserve and commit pages at the
same time (**SEC_COMMIT**) or simply reserve pages
(**SEC_RESERVE**). Mapping the file makes the entire mapped virtual address range
unavailable to other allocations in the process. After a page from the reserved range is committed, it cannot be
freed or decommitted by calling [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree). Reserved and
committed pages are released when the view is unmapped and the file mapping object is closed. For details, see
the [UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) and
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) functions.

To have a file with executable permissions, an application must call
[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) with either
**PAGE_EXECUTE_READWRITE** or **PAGE_EXECUTE_READ**,
and then call **MapViewOfFile** with
**FILE_MAP_EXECUTE** | **FILE_MAP_WRITE** or
**FILE_MAP_EXECUTE** | **FILE_MAP_READ**.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

When CsvFs is paused this call might fail with an error indicating that there is a lock conflict.

#### Examples

For an example, see
[Creating Named Shared Memory](https://learn.microsoft.com/windows/desktop/Memory/creating-named-shared-memory).

## See also

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[Creating a File View](https://learn.microsoft.com/windows/desktop/Memory/creating-a-file-view)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)
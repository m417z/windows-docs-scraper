# MapViewOfFileExNuma function

## Description

Maps a view of a file mapping into the address space of a calling process and specifies the NUMA node
for the physical memory.

## Parameters

### `hFileMappingObject` [in]

A handle to a file mapping object. The [CreateFileMappingNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappingnumaa) and [OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga) functions return this handle.

### `dwDesiredAccess` [in]

The type of access to a file mapping object, which determines the page protection of the pages. This parameter can be one of the following values, or a bitwise OR combination of multiple values where appropriate.

| Value | Meaning |
| --- | --- |
| **FILE_MAP_ALL_ACCESS** | A read/write view of the file is mapped. The file mapping object must have been created with **PAGE_READWRITE** or **PAGE_EXECUTE_READWRITE** protection.<br><br>When used with **MapViewOfFileExNuma**, **FILE_MAP_ALL_ACCESS** is equivalent to **FILE_MAP_WRITE**. |
| **FILE_MAP_READ** | A read-only view of the file is mapped. An attempt to write to the file view results in an access violation.<br><br>The file mapping object must have been created with **PAGE_READONLY**, **PAGE_READWRITE**, **PAGE_EXECUTE_READ**, or **PAGE_EXECUTE_READWRITE** protection. |
| **FILE_MAP_WRITE** | A read/write view of the file is mapped. The file mapping object must have been created with **PAGE_READWRITE** or **PAGE_EXECUTE_READWRITE** protection.<br><br>When used with **MapViewOfFileExNuma**, `(FILE_MAP_WRITE \| FILE_MAP_READ)` is equivalent to **FILE_MAP_WRITE**. |

Using bitwise OR, you can combine the values above with these values.

| Value | Meaning |
| --- | --- |
| **FILE_MAP_COPY** | A copy-on-write view of the file is mapped. The file mapping object must have been created with **PAGE_READONLY**, **PAGE_EXECUTE_READ**, **PAGE_WRITECOPY**, **PAGE_EXECUTE_WRITECOPY**, **PAGE_READWRITE**, or **PAGE_EXECUTE_READWRITE** protection.<br><br>When a process writes to a copy-on-write page, the system copies the original page to a new page that is private to the process. The new page is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.<br><br>When copy-on-write access is specified, the system and process commit charge taken is for the entire view because the calling process can potentially write to every page in the view, making all pages private. The contents of the new page are never written back to the original file and are lost when the view is unmapped. |
| **FILE_MAP_EXECUTE** | An executable view of the file is mapped (mapped memory can be run as code). The file mapping object must have been created with **PAGE_EXECUTE_READ**, **PAGE_EXECUTE_WRITECOPY**, or **PAGE_EXECUTE_READWRITE** protection. |
| **FILE_MAP_LARGE_PAGES** | Starting with Windows 10, version 1703, this flag specifies that the view should be mapped using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support). The size of the view must be a multiple of the size of a large page reported by the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function, and the file-mapping object must have been created using the **SEC_LARGE_PAGES** option. If you provide a non-null value for *lpBaseAddress*, then the value must be a multiple of **GetLargePageMinimum**. |
| **FILE_MAP_TARGETS_INVALID** | Sets all the locations in the mapped file as invalid targets for Control Flow Guard (CFG). This flag is similar to **PAGE_TARGETS_INVALID**. Use this flag in combination with the execute access right **FILE_MAP_EXECUTE**. Any indirect call to locations in those pages will fail CFG checks, and the process will be terminated. The default behavior for executable pages allocated is to be marked valid call targets for CFG. |

For file-mapping objects created with the **SEC_IMAGE** attribute, the
*dwDesiredAccess* parameter has no effect, and should be set to any valid value such as
**FILE_MAP_READ**.

For more information about access to file mapping objects, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights).

### `dwFileOffsetHigh` [in]

The high-order **DWORD** of the file offset where the view is to begin.

### `dwFileOffsetLow` [in]

The low-order **DWORD** of the file offset where the view is to begin. The
combination of the high and low offsets must specify an offset within the file mapping. They must also match the
memory allocation granularity of the system. That is, the offset must be a multiple of the allocation
granularity. To obtain the memory allocation granularity of the system, use the
[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function, which fills in the members of
a [SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info) structure.

### `dwNumberOfBytesToMap` [in]

The number of bytes of a file mapping to map to a view. All bytes must be within the maximum size specified
by [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga). If this parameter is 0
(zero), the mapping extends from the specified offset to the end of the file mapping.

### `lpBaseAddress` [in, optional]

A pointer to the memory address in the calling process address space where mapping begins. This must be a
multiple of the system's memory allocation granularity, or the function fails. To determine the memory
allocation granularity of the system, use the
[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function. If there is not enough
address space at the specified address, the function fails.

If the *lpBaseAddress* parameter is **NULL**, the operating
system chooses the mapping address.

While it is possible to specify an address that is safe now (not used by the operating system), there is no
guarantee that the address will remain safe over time. Therefore, it is better to let the operating system
choose the address. In this case, you would not store pointers in the memory mapped file; you would store
offsets from the base of the file mapping so that the mapping can be used at any address.

### `nndPreferred` [in]

The NUMA node where the physical memory should reside.

| Value | Meaning |
| --- | --- |
| **NUMA_NO_PREFERRED_NODE**<br><br>0xffffffff | No NUMA node is preferred. This is the same as calling the [MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex) function. |

## Return value

If the function succeeds, the return value is the starting address of the mapped view.

If the function fails, the return value is **NULL**. To get extended error information,
call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Mapping a file makes the specified portion of the file visible in the address space of the calling
process.

For files that are larger than the address space, you can map only a small portion of the file data at one
time. When the first view is complete, then you unmap it and map a new view.

To obtain the size of a view, use the
[VirtualQueryEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualqueryex) function.

The initial contents of the pages in a file mapping object backed by the page file are 0 (zero).

If a suggested mapping address is supplied, the file is mapped at the specified address (rounded down to the
nearest 64-KB boundary) if there is enough address space at the specified address. If there is not enough address
space, the function fails.

Typically, the suggested address is used to specify that a file should be mapped at the same address in
multiple processes. This requires the region of address space to be available in all involved processes. No other
memory allocation can take place in the region that is used for mapping, including the use of the
[VirtualAllocExNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocexnuma) function to reserve memory.

If the *lpBaseAddress* parameter specifies a base offset, the function succeeds if the
specified memory region is not already in use by the calling process. The system does not ensure that the same
memory region is available for the memory mapped file in other 32-bit processes.

Multiple views of a file (or a file mapping object and its mapped file) are *coherent*
if they contain identical data at a specified time. This occurs if the file views are derived from the same file
mapping object. A process can duplicate a file mapping object handle into another process by using the
[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function, or another process can open
a file mapping object by name by using the
[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga) function.

With one important exception, file views derived from any file mapping object that is backed by the same file
are coherent or identical at a specific time. Coherency is guaranteed for views within a process and for views
that are mapped by different processes.

The exception is related to remote files. Although
**MapViewOfFileExNuma** works with remote files, it
does not keep them coherent. For example, if two computers both map a file as writable, and both change the same
page, each computer only sees its own writes to the page. When the data gets updated on the disk, it is not
merged.

A mapped view of a file is not guaranteed to be coherent with a file being accessed by the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) or
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) function.

To guard against **EXCEPTION_IN_PAGE_ERROR** exceptions, use structured exception
handling to protect any code that writes to or reads from a memory mapped view of a file other than the page file.
For more information, see
[Reading and Writing From a File View](https://learn.microsoft.com/windows/desktop/Memory/reading-and-writing-from-a-file-view).

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically.
If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the
timestamp.

To have a file with executable permissions, an application must call
the [CreateFileMappingNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappingnumaa) function with either
**PAGE_EXECUTE_READWRITE** or **PAGE_EXECUTE_READ**
and then call the **MapViewOfFileExNuma** function
with **FILE_MAP_EXECUTE** | **FILE_MAP_WRITE** or
**FILE_MAP_EXECUTE** | **FILE_MAP_READ**.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CreateFileMappingNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappingnumaa)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[File Mapping Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)
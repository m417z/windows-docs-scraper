# MapViewOfFileFromApp function

## Description

Maps a view of a file mapping into the address space of a calling
Windows Store app.

## Parameters

### `hFileMappingObject` [in]

A handle to a file mapping object. The
[CreateFileMappingFromApp](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-createfilemappingfromapp) function returns
this handle.

### `DesiredAccess` [in]

The type of access to a file mapping object, which determines the page protection of the pages. This
parameter can be one of the following values, or a bitwise OR combination of multiple values where appropriate.

| Value | Meaning |
| --- | --- |
| **FILE_MAP_ALL_ACCESS** | A read/write view of the file is mapped. The file mapping object must have been created with **PAGE_READWRITE** protection.<br><br>When used with **MapViewOfFileFromApp**, **FILE_MAP_ALL_ACCESS** is equivalent to **FILE_MAP_WRITE**. |
| **FILE_MAP_READ** | A read-only view of the file is mapped. An attempt to write to the file view results in an access violation.<br><br>The file mapping object must have been created with **PAGE_READONLY**, **PAGE_READWRITE**, **PAGE_EXECUTE_READ**, or **PAGE_EXECUTE_READWRITE** protection. |
| **FILE_MAP_WRITE** | A read/write view of the file is mapped. The file mapping object must have been created with **PAGE_READWRITE** protection.<br><br>When used with **MapViewOfFileFromApp**, `(FILE_MAP_WRITE | FILE_MAP_READ)` is equivalent to **FILE_MAP_WRITE**. |

Using bitwise OR, you can combine the values above with these values.

| Value | Meaning |
| --- | --- |
| **FILE_MAP_COPY** | A copy-on-write view of the file is mapped. The file mapping object must have been created with **PAGE_READONLY**, **PAGE_EXECUTE_READ**, **PAGE_WRITECOPY**, or **PAGE_READWRITE** protection.<br><br>When a process writes to a copy-on-write page, the system copies the original page to a new page that is private to the process. The new page is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.<br><br>When copy-on-write access is specified, the system and process commit charge taken is for the entire view because the calling process can potentially write to every page in the view, making all pages private. The contents of the new page are never written back to the original file and are lost when the view is unmapped. |
| **FILE_MAP_LARGE_PAGES** | Starting with Windows 10, version 1703, this flag specifies that the view should be mapped using [large page support](https://learn.microsoft.com/windows/desktop/Memory/large-page-support). The size of the view must be a multiple of the size of a large page reported by the [GetLargePageMinimum](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getlargepageminimum) function, and the file-mapping object must have been created using the **SEC_LARGE_PAGES** option. If you provide a non-null value for *lpBaseAddress*, then the value must be a multiple of **GetLargePageMinimum**. |
| **FILE_MAP_TARGETS_INVALID** | Sets all the locations in the mapped file as invalid targets for Control Flow Guard (CFG). This flag is similar to **PAGE_TARGETS_INVALID**. Use this flag in combination with the execute access right **FILE_MAP_EXECUTE**. Any indirect call to locations in those pages will fail CFG checks, and the process will be terminated. The default behavior for executable pages allocated is to be marked valid call targets for CFG. |

For file-mapping objects created with the **SEC_IMAGE** attribute, the
*dwDesiredAccess* parameter has no effect, and should be set to any valid value such as
**FILE_MAP_READ**.

For more information about access to file mapping objects, see
[File Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights).

### `FileOffset` [in]

The file offset where the view is to begin. The offset must specify an offset within the file mapping. They
must also match the memory allocation granularity of the system. That is, the offset must be a multiple of the
allocation granularity. To obtain the memory allocation granularity of the system, use the
[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function, which fills in the members of
a [SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info) structure.

### `NumberOfBytesToMap` [in]

The number of bytes of a file mapping to map to the view. All bytes must be within the maximum size specified
by [CreateFileMappingFromApp](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-createfilemappingfromapp). If this
parameter is 0 (zero), the mapping extends from the specified offset to the end of the file mapping.

## Return value

If the function succeeds, the return value is the starting address of the mapped view.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

With one important exception, file views derived from any file mapping object that is backed by the same file
are coherent or identical at a specific time. Coherency is guaranteed for views within a process and for views
that are mapped by different processes.

The exception is related to remote files. Although
**MapViewOfFileFromApp** works with remote files, it
does not keep them coherent. For example, if two computers both map a file as writable, and both change the same
page, each computer only sees its own writes to the page. When the data gets updated on the disk, it is not
merged.

 You can only successfully request executable protection if your app has the **codeGeneration** capability.

## See also

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[Creating a File View](https://learn.microsoft.com/windows/desktop/Memory/creating-a-file-view)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[OpenFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfilemappinga)

[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)
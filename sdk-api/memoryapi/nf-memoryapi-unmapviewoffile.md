# UnmapViewOfFile function

## Description

Unmaps a mapped view of a file from the calling process's address space.

## Parameters

### `lpBaseAddress` [in]

A pointer to the base address of the mapped view of a file that is to be unmapped. This value must be identical to the value returned by a previous call
to one of the functions in the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) family.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Unmapping a mapped view of a file invalidates the range occupied by the view in the address space of the process and makes the range available for other allocations. It removes the working set entry for each unmapped virtual page that was part of the working set of the process and reduces the working set size of the process. It also decrements the share count of the corresponding physical page.

Modified pages in the unmapped view are not written to disk until their share count reaches zero, or in other words, until they are unmapped or trimmed from the working sets of all processes that share the pages. Even then, the modified pages are written "lazily" to disk; that is, modifications may be cached in memory and written to disk at a later time. To minimize the risk of data loss in the event of a power failure or a system crash, applications should explicitly flush modified pages using the [FlushViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-flushviewoffile) function.

Although an application may close the file handle used to create a file mapping object, the system holds the corresponding file open until the last view of the file is unmapped. Files for which the last view has not yet been unmapped are held open with no sharing restrictions.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Creating a View Within a File](https://learn.microsoft.com/windows/desktop/Memory/creating-a-view-within-a-file).

## See also

[Closing a File Mapping Object](https://learn.microsoft.com/windows/desktop/Memory/closing-a-file-mapping-object)

[File Mapping Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex)

Memory
Management Functions
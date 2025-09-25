# FlushViewOfFile function

## Description

Writes to the disk a byte range within a mapped view of a file.

## Parameters

### `lpBaseAddress` [in]

A pointer to the base address of the byte range to be flushed to the disk representation of the mapped file.

### `dwNumberOfBytesToFlush` [in]

The number of bytes to be flushed. If *dwNumberOfBytesToFlush* is zero, the file is flushed from the base address to the end of the mapping.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Flushing a range of a mapped view initiates writing of dirty pages within that range to the disk. Dirty pages are those whose contents have changed since the file view was mapped. The **FlushViewOfFile** function does not flush the file metadata, and it does not wait to return until the changes are flushed from the underlying hardware disk cache and physically written to disk. To flush all the dirty pages plus the metadata for the file and ensure that they are physically written to disk, call **FlushViewOfFile** and then call the [FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) function.

When flushing a memory-mapped file over a network,
**FlushViewOfFile** guarantees that the data has been written from the local computer, but not that the data resides on the remote computer. The server can cache the data on the remote side. Therefore,
**FlushViewOfFile** can return before the data has been physically written to disk.

When modifying a file through a mapped view, the last modification timestamp may not be updated automatically. If required, the caller should use [SetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfiletime) to set the timestamp.

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
[Reading and Writing From a File View](https://learn.microsoft.com/windows/desktop/Memory/reading-and-writing-from-a-file-view).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[Creating a File View](https://learn.microsoft.com/windows/desktop/Memory/creating-a-file-view)

[File Mapping Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)
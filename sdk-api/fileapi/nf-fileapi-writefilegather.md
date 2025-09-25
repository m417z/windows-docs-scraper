# WriteFileGather function

## Description

Retrieves data from an array of buffers and writes the data to a file.

The function starts writing data to the file at a position that is specified by an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The **WriteFileGather** function operates asynchronously.

## Parameters

### `hFile` [in]

A handle to the file. The file handle must be created with the **GENERIC_WRITE** access right, and the **FILE_FLAG_OVERLAPPED** and **FILE_FLAG_NO_BUFFERING** flags. For more information, see [File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `aSegmentArray` [in]

A pointer to an array of [FILE_SEGMENT_ELEMENT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-file_segment_element) buffers that contain the data. For a description of this union, see Remarks.

Each element represents one page of data.

> [!NOTE]
> To determine the size of a system page, use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function.

The array must contain enough elements to represent *nNumberOfBytesToWrite* bytes of data. For example, if there are 40 KB to be written and the page size is 4 KB, the array must have 10 elements.

Each buffer must be at least the size of a system memory page and must be aligned on a system memory page size boundary. The system writes one system memory page of data from each buffer.

The function gathers the data from the buffers in sequential order. For example, it writes data to the file from the first buffer, then the second buffer, and so on until *nNumberOfBytesToWrite* bytes have been written.

Due to the asynchronous operation of this function, precautions must be taken to ensure that this parameter always references valid memory for the lifetime of the asynchronous writes. For instance, a common programming error is to use local stack storage and then allow execution to run out of scope.

### `nNumberOfBytesToWrite` [in]

The total number of bytes to be written. Each element of *aSegmentArray* contains a one-page chunk of this total. Because the file must be opened with **FILE_FLAG_NO_BUFFERING**, the number of bytes must be a multiple of the sector size of the file system where the file is located.

If *nNumberOfBytesToWrite* is zero (0), the function performs a null write operation. The behavior of a null write operation depends on the underlying file system. If *nNumberOfBytesToWrite* is not zero (0) and the offset and length of the write place data beyond the current end of the file, the **WriteFileGather** function extends the file.

### `lpReserved`

This parameter is reserved for future use and must be **NULL**.

### `lpOverlapped` [in, out]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) data structure.

The **WriteFileGather** function requires a valid
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The *lpOverlapped* parameter cannot be **NULL**.

The **WriteFileGather** function starts writing data to the file at a position that is specified by the **Offset** and **OffsetHigh** members of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

The **WriteFileGather** function may return before the write operation is complete. In that scenario, the **WriteFileGather** function returns the value zero (0), and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the value **ERROR_IO_PENDING**. This asynchronous operation of the **WriteFileGather** function lets the calling process continue while the write operation completes.

You can call the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult), [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-hasoverlappediocompleted), or [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function to obtain information about the completion of the write operation. For more information, see [Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

If the function returns before the write operation is complete, the function returns zero (0), and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_IO_PENDING**.

## Remarks

This function is not supported for 32-bit applications by WOW64 on the Itanium-based systems.

The [FILE_SEGMENT_ELEMENT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-file_segment_element) is defined as follows:

```cpp
typedef union _FILE_SEGMENT_ELEMENT {
    PVOID64   Buffer;
    ULONGLONG Alignment;
}FILE_SEGMENT_ELEMENT, *PFILE_SEGMENT_ELEMENT;
```

Assigning a pointer to the **Buffer** member will sign-extend the value if the code is compiled as 32-bits; this can break large-address aware applications running on systems configured with [4-Gigabyte Tuning](https://learn.microsoft.com/windows/desktop/Memory/4-gigabyte-tuning) or running under WOW64 on 64-bit Windows. Therefore, use the **PtrToPtr64** macro when assigning pointers to **Buffer**.

If part of the file specified by *hFile* is locked by another process, and the write operation overlaps the locked portion, the **WriteFileGather** function fails.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

### Transacted Operations

If there is a transaction bound to the file handle, then the operation is transacted.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[FILE_SEGMENT_ELEMENT](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/winnt/ns-winnt-file_segment_element.md)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[HasOverlappedIoCompleted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-hasoverlappediocompleted)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[ReadFileScatter](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfilescatter)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o)
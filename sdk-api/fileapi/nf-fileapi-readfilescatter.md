# ReadFileScatter function

## Description

Reads data from a file and stores it in an array of buffers.

The function starts reading data from the file at a position that is specified by an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The
    **ReadFileScatter** function operates asynchronously.

## Parameters

### `hFile` [in]

A handle to the file to be read.

The file handle must be created with the **GENERIC_READ** right, and the **FILE_FLAG_OVERLAPPED** and **FILE_FLAG_NO_BUFFERING** flags. For more information, see [File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `aSegmentArray` [in]

A pointer to an array of [FILE_SEGMENT_ELEMENT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-file_segment_element) buffers that receives the data. For a description of this union, see [Remarks](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfilescatter#remarks).

Each element represents one page of data.

> [!NOTE]
> To determine the size of a system page, use [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo).

The array must contain enough elements to represent *nNumberOfBytesToRead* bytes of data. For example, if there are 40 KB to be read and the page size is 4 KB, the array must have 10 elements.

Each buffer must be at least the size of a system memory page and must be aligned on a system memory page size boundary. The system reads one system memory page of data into each buffer.

The function stores the data in the buffers in sequential order. For example, it stores data into the first buffer, then into the second buffer, and so on until each buffer is filled and all the data is stored, or *nNumberOfBytesToRead* bytes have been read.

### `nNumberOfBytesToRead` [in]

The total number of bytes to be read from the file. Each element of *aSegmentArray* contains a one-page chunk of this total. Because the file must be opened with **FILE_FLAG_NO_BUFFERING**, the number of bytes must be a multiple of the sector size of the file system where the file is located.

### `lpReserved`

This parameter is reserved for future use and must be **NULL**.

### `lpOverlapped` [in, out]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) data structure.

The **ReadFileScatter** function requires a valid
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The *lpOverlapped* parameter cannot be **NULL**.

The **ReadFileScatter** function starts reading data from the file at a position that is specified by the **Offset** and **OffsetHigh** members of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

The **ReadFileScatter** function may return before the read operation is complete. In that scenario, the **ReadFileScatter** function returns the value 0 (zero), and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the value **ERROR_IO_PENDING**. This asynchronous operation of **ReadFileScatter** lets the calling process continue while the read operation completes. You can call the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult), [HasOverlappedIoCompleted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-hasoverlappediocompleted), or [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) functions to obtain information about the completion of the read operation. For more information, see [Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

If **ReadFileScatter** attempts to read past the end-of-file (EOF), the call to [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) for that operation returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_HANDLE_EOF**.

If the function returns before the read operation is complete, the function returns zero (0), and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_IO_PENDING**.

## Remarks

This function is not supported for 32-bit applications by WOW64 on Itanium-based systems.

The [FILE_SEGMENT_ELEMENT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-file_segment_element) is defined as follows:

```cpp
typedef union _FILE_SEGMENT_ELEMENT {
    PVOID64 Buffer;
    ULONGLONG Alignment;
}FILE_SEGMENT_ELEMENT, *PFILE_SEGMENT_ELEMENT;
```

Assigning a pointer to the **Buffer** member will sign-extend the value if the code is compiled as 32-bits; this can break large-address aware applications running on systems configured with [4-Gigabyte Tuning](https://learn.microsoft.com/windows/desktop/Memory/4-gigabyte-tuning) or running on under WOW64 on 64-bit Windows. Therefore, use the **PtrToPtr64** macro when assigning pointers to **Buffer**.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

### Transacted Operations

If there is a transaction bound to the file handle, then the function returns data from the transacted view of
the file. A transacted read handle is guaranteed to show the same view of a file for the duration of the
handle.

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

[WriteFileGather](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefilegather)
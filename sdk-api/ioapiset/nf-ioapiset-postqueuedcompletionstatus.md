# PostQueuedCompletionStatus function

## Description

Posts an I/O completion packet to an I/O completion port.

## Parameters

### `CompletionPort` [in]

A handle to an I/O completion port to which the I/O completion packet is to be posted.

### `dwNumberOfBytesTransferred` [in]

The value to be returned through the *lpNumberOfBytesTransferred* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

### `dwCompletionKey` [in]

The value to be returned through the *lpCompletionKey* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

### `lpOverlapped` [in, optional]

The value to be returned through the *lpOverlapped* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) .

## Remarks

The I/O completion packet will satisfy an outstanding call to the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function. This function returns with the three values passed as the second, third, and fourth parameters of the call to
**PostQueuedCompletionStatus**. The system does not use or validate these values. In particular, the *lpOverlapped* parameter need not point to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

CsvFs will do redirected IO for compressed files.

## See also

[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)
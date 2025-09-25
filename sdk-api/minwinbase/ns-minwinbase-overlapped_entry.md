# OVERLAPPED_ENTRY structure

## Description

Contains the information returned by a call to the
[GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func)
function.

## Members

### `lpCompletionKey`

Receives the completion key value associated with the file handle whose I/O operation has completed. A
completion key is a per-file key that is specified in a call to
[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport).

### `lpOverlapped`

Receives the address of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure
that was specified when the completed I/O operation was started.

### `Internal`

Reserved.

### `dwNumberOfBytesTransferred`

Receives the number of bytes transferred during the I/O operation that has completed.

## See also

[GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)
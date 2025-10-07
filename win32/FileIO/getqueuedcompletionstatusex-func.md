# GetQueuedCompletionStatusEx function

Retrieves multiple completion port entries simultaneously. It waits for pending I/O operations that are associated with the specified completion port to complete.

To dequeue I/O completion packets one at a time, use the [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

## Parameters

*CompletionPort* `[in]`

A handle to the completion port. To create a completion port, use the [CreateIoCompletionPort](https://learn.microsoft.com/windows/win32/fileio/createiocompletionport) function.

*lpCompletionPortEntries* `[out]`

On input, points to a pre-allocated array of [OVERLAPPED\_ENTRY](https://learn.microsoft.com/windows/win32/api/MinWinBase/ns-minwinbase-overlapped_entry) structures.

On output, receives an array of [OVERLAPPED\_ENTRY](https://learn.microsoft.com/windows/win32/api/MinWinBase/ns-minwinbase-overlapped_entry) structures that hold the entries. The number of array elements is provided by *ulNumEntriesRemoved*.

The number of bytes transferred during each I/O, the completion key that indicates on which file each I/O occurred, and the overlapped structure address used in each original I/O are all returned in the *lpCompletionPortEntries* array.

*ulCount* `[in]`

The maximum number of entries to remove.

*ulNumEntriesRemoved* `[out]`

A pointer to a variable that receives the number of entries actually removed.

*dwMilliseconds* `[in]`

The number of milliseconds that the caller is willing to wait for a completion packet to appear at the completion port. If a completion packet does not appear within the specified time, the function times out and returns `FALSE`.

If *dwMilliseconds* is **INFINITE** (`0xFFFFFFFF`), the function will never time out. If *dwMilliseconds* is zero and there is no I/O operation to dequeue, the function will time out immediately.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008 and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8, Windows Server 2012, Windows 8.1, Windows Server 2012 R2, Windows 10 and Windows Server 2016:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

*fAlertable* `[in]`

If this parameter is `FALSE`, the function does not return until the time-out period has elapsed or an entry is retrieved.

If the parameter is `TRUE` and there are no available entries, the function performs an alertable wait. The thread returns when the system queues an I/O completion routine or APC to the thread and the thread executes the function.

A completion routine is queued when the [ReadFileEx](https://learn.microsoft.com/windows/win32/api/FileAPI/nf-fileapi-readfileex) or [WriteFileEx](https://learn.microsoft.com/windows/win32/api/FileAPI/nf-fileapi-writefileex) function in which it was specified has completed, and the calling thread is the thread that initiated the operation. An APC is queued when you call [QueueUserAPC](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc).

## Return value

Returns nonzero `TRUE` if successful or zero `FALSE` otherwise.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function associates a thread with the specified completion port. A thread can be associated with at most one completion port.

This function returns `TRUE` when at least one pending I/O is completed, but it is possible that one or more I/O operations failed. Note that it is up to the user of this function to check the list of returned entries in the *lpCompletionPortEntries* parameter to determine which of them correspond to any possible failed I/O operations by looking at the status contained in the **lpOverlapped** member in each [OVERLAPPED\_ENTRY](https://learn.microsoft.com/windows/win32/api/MinWinBase/ns-minwinbase-overlapped_entry).

This function returns `FALSE` when no I/O operation was dequeued. This typically means that an error occurred while processing the parameters to this call, or that the *CompletionPort* handle was closed or is otherwise invalid. The [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function provides extended error information.

If a call to [GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) fails because the handle associated with it is closed, the function returns `FALSE` and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return `ERROR_ABANDONED_WAIT_0`.

Server applications may have several threads calling the **GetQueuedCompletionStatusEx** function for the same completion port. As I/O operations complete, they are queued to this port in first-in-first-out order. If a thread is actively waiting on this call, one or more queued requests complete the call for that thread only.

For more information on I/O completion port theory, usage, and associated functions, see [I/O Completion Ports](https://learn.microsoft.com/windows/win32/fileio/i-o-completion-ports).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
|-------------------------------------------|-----------|
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client | Windows Vista \[desktop apps \| UWP apps\] |
| Minimum supported server | Windows Server 2008 \[desktop apps \| UWP apps\] |
| Header | `IoAPI.h` (include `Windows.h`)<br>`WinBase.h` on Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista (include `Windows.h`) |
| Library | `Kernel32.lib` |
| DLL | `Kernel32.dll` |

## See also

**Overview Topics**

[File Management Functions](https://learn.microsoft.com/windows/win32/fileio/file-management-functions)

[I/O Completion Ports](https://learn.microsoft.com/windows/win32/fileio/i-o-completion-ports)

[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers)

**Functions**

[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateIoCompletionPort](https://learn.microsoft.com/windows/win32/fileio/createiocompletionport)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[LockFileEx](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-lockfileex)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-readfile)

[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/fileio/postqueuedcompletionstatus)

[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)

[WaitCommEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitcommevent)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-writefile)
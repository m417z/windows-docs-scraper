## Description

**LPWSAOVERLAPPED_COMPLETION_ROUTINE** is a function pointer type. You implement a matching callback function in your app, and pass that to functions such as [WSAIoctl](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl), [WSARecv](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsarecv), and [WSASend](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsasend), among others.

The system calls your callback function when the asynchronous input and output (I/O) operation is completed or canceled, and the calling thread is in an alertable state (by using the [SleepEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepex), [MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-msgwaitformultipleobjectsex), [WaitForSingleObjectEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex), or [WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjectsex) function with the *fAlertable* parameter set to **TRUE**).

## Parameters

### `dwError`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The I/O completion status. This parameter can be one of the [system error codes](https://learn.microsoft.com/windows/win32/Debug/system-error-codes).

### `cbTransferred`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of bytes transferred. If an error occurs, this parameter is zero.

### `lpOverlapped`

Type: IN **[LPWSAOVERLAPPED](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped)**

A pointer to the [**WSAOVERLAPPED**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped) structure specified by the asynchronous I/O function.

The system doesn't use the [**WSAOVERLAPPED**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaoverlapped) structure after the completion routine is called, so the completion routine can deallocate the memory used by the overlapped structure.

### `dwFlags`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flags associated with the call.

## Remarks

See [**LPOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/minwinbase/nc-minwinbase-lpoverlapped_completion_routine).

## See also
# WSAAsyncGetProtoByName function

## Description

The
**WSAAsyncGetProtoByName** function asynchronously retrieves protocol information that corresponds to a protocol name.

## Parameters

### `hWnd` [in]

Handle of the window that will receive a message when the asynchronous request completes.

### `wMsg` [in]

Message to be received when the asynchronous request completes.

### `name` [in]

Pointer to the null-terminated protocol name to be resolved.

### `buf` [out]

Pointer to the data area to receive the
[protoent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-protoent) data. The data area must be larger than the size of a
**protoent** structure because the data area is used by Windows Sockets to contain a
**protoent** structure and all of the data that is referenced by members of the
**protoent** structure. A buffer of MAXGETHOSTSTRUCT bytes is recommended.

### `buflen` [out]

Size of data area for the *buf* parameter, in bytes.

## Return value

The return value specifies whether or not the asynchronous operation was successfully initiated. It does not imply success or failure of the operation itself.

If no error occurs,
**WSAAsyncGetProtoByName** returns a nonzero value of type HANDLE that is the asynchronous task handle for the request (not to be confused with a Windows HTASK). This value can be used in two ways. It can be used to cancel the operation using
[WSACancelAsyncRequest](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacancelasyncrequest), or it can be used to match up asynchronous operations and completion messages, by examining the *wParam* message parameter.

If the asynchronous operation could not be initiated,
**WSAAsyncGetProtoByName** returns a zero value, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

The following error codes can be set when an application window receives a message. As described above, they can be extracted from the *lParam* in the reply message using the **WSAGETASYNCERROR** macro.

| Error code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient buffer space is available. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* or *buf* parameter is not in a valid part of the process address space. |
| **[WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Authoritative answer protocol not found. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonauthoritative protocol not found, or server failure. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Nonrecoverable errors, the protocols database is not accessible. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Valid name, no data record of requested type. |

The following errors can occur at the time of the function call, and indicate that the asynchronous operation could not be initiated.

| Error code | Meaning |
| --- | --- |
| [WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem has failed. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The asynchronous operation cannot be scheduled at this time due to resource or other constraints within the Windows Sockets implementation. |

## Remarks

The
**WSAAsyncGetProtoByName** function is an asynchronous version of
[getprotobyname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getprotobyname). It is used to retrieve the protocol name and number from the Windows Sockets database corresponding to a given protocol name. Windows Sockets initiates the operation and returns to the caller immediately, passing back an opaque, asynchronous task handle that the application can use to identify the operation. When the operation is completed, the results (if any) are copied into the buffer provided by the caller and a message is sent to the application's window.

When the asynchronous operation has completed, the application window indicated by the *hWnd* parameter receives message in the *wMsg* parameter. The *wParam* parameter contains the asynchronous task handle as returned by the original function call. The high 16 bits of *lParam* contain any error code. The error code can be any error as defined in Winsock2.h. An error code of zero indicates successful completion of the asynchronous operation.

On successful completion, the buffer specified to the original function call contains a
[protoent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-protoent) structure. To access the members of this structure, the original buffer address should be cast to a
**protoent** structure pointer and accessed as appropriate.

If the error code is [WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), the size of the buffer specified by *buflen* in the original call was too small to contain all the resulting information. In this case, the low 16 bits of *lParam* contain the size of buffer required to supply all the requisite information. If the application decides that the partial data is inadequate, it can reissue the
**WSAAsyncGetProtoByName** function call with a buffer large enough to receive all the desired information (that is, no smaller than the low 16 bits of *lParam*).

The buffer specified to this function is used by Windows Sockets to construct a
[protoent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-protoent) structure together with the contents of data areas referenced by members of the same
**protoent** structure. To avoid the
[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error noted above, the application should provide a buffer of at least MAXGETHOSTSTRUCT bytes (as defined in Winsock2.h).

The error code and buffer length should be extracted from the *lParam* using the macros **WSAGETASYNCERROR** and **WSAGETASYNCBUFLEN**, defined in Winsock2.h as:

```cpp
#include <windows.h>

#define WSAGETASYNCBUFLEN(lParam)           LOWORD(lParam)
#define WSAGETASYNCERROR(lParam)            HIWORD(lParam)

```

The use of these macros will maximize the portability of the source code for the application.

## See also

[WSACancelAsyncRequest](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacancelasyncrequest)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getprotobyname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getprotobyname)
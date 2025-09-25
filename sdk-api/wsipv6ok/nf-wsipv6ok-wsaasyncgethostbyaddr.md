# WSAAsyncGetHostByAddr macro

## Description

The
**WSAAsyncGetHostByAddr** function asynchronously retrieves host information that corresponds to an address.

**Note** The
**WSAAsyncGetHostByAddr** function is not designed to provide parallel resolution of several addresses. Therefore, applications that issue several requests should not expect them to be executed concurrently. Alternatively, applications can start another thread and use the
[getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo) function to resolve addresses in an IP-version agnostic manner. Developers creating Windows Sockets 2 applications are urged to use the
**getnameinfo** function to enable smooth transition to IPv6 compatibility.

## Parameters

### `a` [in]

Handle of the window that will receive a message when the asynchronous request completes.

### `b` [in]

Message to be received when the asynchronous request completes.

### `c` [in]

Pointer to the network address for the host. Host addresses are stored in network byte order.

### `d` [in]

Length of the address, in bytes.

### `e` [in]

Type of the address.

### `f` [out]

Pointer to the data area to receive the
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) data. The data area must be larger than the size of a
**hostent** structure because the data area is used by Windows Sockets to contain a
**hostent** structure and all of the data referenced by members of the
**hostent** structure. A buffer of MAXGETHOSTSTRUCT bytes is recommended.

### `g` [in]

Size of data area for the *buf* parameter, in bytes.

## Remarks

The
**WSAAsyncGetHostByAddr** function is an asynchronous version of
[gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr). It is used to retrieve the host name and address information that corresponds to a network address. Windows Sockets initiates the operation and returns to the caller immediately, passing back an opaque, asynchronous task handle that the application can use to identify the operation. When the operation is completed, the results (if any) are copied into the buffer provided by the caller and a message is sent to the application's window.

When the asynchronous operation has completed, the application window indicated by the *hWnd* parameter receives message in the *wMsg* parameter. The *wParam* parameter contains the asynchronous task handle as returned by the original function call. The high 16 bits of *lParam* contain any error code. The error code can be any error as defined in Winsock2.h. An error code of zero indicates successful completion of the asynchronous operation.

On successful completion, the buffer specified to the original function call contains a
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure. To access the members of this structure, the original buffer address is cast to a
**hostent** structure pointer and accessed as appropriate.

If the error code is
[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), the size of the buffer specified by *buflen* in the original call was too small to contain all the resulting information. In this case, the low 16 bits of *lParam* contain the size of buffer required to supply all the requisite information. If the application decides that the partial data is inadequate, it can reissue the
**WSAAsyncGetHostByAddr** function call with a buffer large enough to receive all the desired information (that is, no smaller than the low 16 bits of *lParam*).

The buffer specified to this function is used by Windows Sockets to construct a structure together with the contents of data areas referenced by members of the same
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure. To avoid the
[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error, the application should provide a buffer of at least MAXGETHOSTSTRUCT bytes (as defined in Winsock2.h).

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

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr)

[getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo)

[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent)
# getsockname function

## Description

The
**getsockname** function retrieves the local name for a socket.

## Parameters

### `s` [in]

Descriptor identifying a socket.

### `name` [out]

Pointer to a
[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that receives the address (name) of the socket.

### `namelen` [in, out]

Size of the *name* buffer, in bytes.

## Return value

If no error occurs,
**getsockname** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this API. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* or the *namelen* parameter is not a valid part of the user address space, or the *namelen* parameter is too small. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket has not been bound to an address with [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), or ADDR_ANY is specified in **bind** but connection has not yet occurred. |

## Remarks

The
**getsockname** function retrieves the current name for the specified socket descriptor in *name*. It is used on the bound or connected socket specified by the *s* parameter. The local association is returned. This call is especially useful when a
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call has been made without doing a
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) first; the
**getsockname** function provides the only way to determine the local association that has been set by the system.

On call, the *namelen* parameter contains the size of the *name* buffer, in bytes. On return, the *namelen* parameter contains the actual size in bytes of the *name* parameter.

The
**getsockname** function does not always return information about the host address when the socket has been bound to an unspecified address, unless the socket has been connected with
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) (for example, using ADDR_ANY). A Windows Sockets application must not assume that the address will be specified unless the socket is connected. The address that will be used for the socket is unknown unless the socket is connected when used in a multihomed host. If the socket is using a connectionless protocol, the address may not be available until I/O occurs on the socket.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[getpeername](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getpeername)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)
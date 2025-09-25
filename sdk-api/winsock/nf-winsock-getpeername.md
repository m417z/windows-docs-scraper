# getpeername function

## Description

The
**getpeername** function retrieves the address of the peer to which a socket is connected.

## Parameters

### `s` [in]

A descriptor identifying a connected socket.

### `name` [out]

The
[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that receives the address of the peer.

### `namelen` [in, out]

A pointer to the size, in bytes, of the *name* parameter.

## Return value

If no error occurs,
**getpeername** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* or the *namelen* parameter is not in a valid part of the user address space, or the *namelen* parameter is too small. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**getpeername** function retrieves the address of the peer connected to the socket *s* and stores the address in the [SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure identified by the *name* parameter. This function works with any address family and it simply returns the address to which the socket is connected. The
**getpeername** function can be used only on a connected socket.

For datagram sockets, only the address of a peer specified in a previous
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call will be returned. Any address specified by a previous
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) call will not be returned by
**getpeername**.

On call, the *namelen* parameter contains the size, in bytes, of the *name* buffer. On return, the *namelen* parameter contains the actual size, in bytes, of the *name* parameter returned.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)
# WSAHtonl function

## Description

The
**WSAHtonl** function converts a **u_long** from host byte order to network byte order.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `hostlong` [in]

A 32-bit number in host byte order.

### `lpnetlong` [out]

A pointer to a 32-bit number to receive the number in network byte order.

## Return value

If no error occurs,
**WSAHtonl** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpnetlong* parameter is **NULL** or the address pointed to is not completely contained in a valid part of the user address space. |

## Remarks

The
**WSAHtonl** function takes a 32-bit number in host byte order and returns a 32-bit number in network byte order in the 32-bit number pointed to by the *lpnetlong* parameter. The socket passed in the *s* parameter is used to determine the network byte order required based on the Winsock catalog protocol entry associated with the socket. This feature supports Winsock providers that use different network byte orders.

If the socket is for the AF_INET or AF_INET6 address family, the
**WSAHtonl** function can be used to convert an IPv4 address in host byte order to the IPv4 address in network byte order. This function does not do any checking to determine if the *hostlong* parameter is a valid IPv4 address.

The
**WSAHtonl** function requires that the Winsock DLL has previously been loaded with a successful
call to the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function. For use with the AF_INET or AF_INET6 family, the [htonl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htonl) function does not require that the Winsock DLL be loaded.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[WSAHtons](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsahtons)

[WSANtohl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsantohl)

[WSANtohs](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsantohs)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[htonl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htonl)

[htons](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htons)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)
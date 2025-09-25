# WSANtohl function

## Description

The
**WSANtohl** function converts a **u_long** from network byte order to host byte order.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `netlong` [in]

A 32-bit number in network byte order.

### `lphostlong` [out]

A pointer to a 32-bit number to receive the number in host byte order.

## Return value

If no error occurs,
**WSANtohl** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lphostlong* parameter is **NULL** or the address pointed to is not completely contained in a valid part of the user address space. |

## Remarks

The
**WSANtohl** function takes a 32-bit number in network byte order and returns a 32-bit number in host byte order in the 32-bit number pointed to by the *lphostlong* parameter. The socket passed in the *s* parameter is used to determine the network byte order required based on the Winsock catalog protocol entry associated with the socket. This feature supports Winsock providers that use different network byte orders.

If the socket is for the AF_INET or AF_INET6 address family, the
**WSANtohl** function can be used to convert an IPv4 address in network byte order to the IPv4 address in host byte order. This function does not do any checking to determine if the *netlong* parameter is a valid IPv4 address.

The
**WSANtohl** function requires that the Winsock DLL has previously been loaded with a successful
call to the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function. For use with the AF_INET or AF_INET6 family, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) function does not require that the Winsock DLL be loaded.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[WSAHtonl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsahtonl)

[WSAHtons](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsahtons)

[WSANtohs](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsantohs)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[htonl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htonl)

[htons](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htons)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)
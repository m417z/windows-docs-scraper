# ntohs function

## Description

The
**ntohs** function converts a **u_short** from TCP/IP network byte order to host byte order (which is little-endian on Intel processors).

## Parameters

### `netshort` [in]

A 16-bit number in TCP/IP network byte order.

## Return value

The
**ntohs** function returns the value in host byte order. If the *netshort* parameter is already in host byte order, then this function will reverse it. It is up to the application to determine if the byte order must be reversed.

## Remarks

The
**ntohs** function takes a 16-bit number in TCP/IP network byte order (the AF_INET or AF_INET6 address family) and returns a 16-bit number in host byte order.

The
**ntohs** function can be used to convert an IP port number in network byte order to the IP port number in host byte order.

The **ntohs** function does not require that the Winsock DLL has previously been loaded with a successful
call to the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

[WSAHtonl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsahtonl)

[WSAHtons](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsahtons)

[WSANtohl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsantohl)

[WSANtohs](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsantohs)

[htond](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-htond)

[htonf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-htonf)

[htonl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htonl)

[htonll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-htonll)

[htons](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htons)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-ntohd)

[ntohf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-ntohf)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-ntohll)
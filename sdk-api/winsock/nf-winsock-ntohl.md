# ntohl function

## Description

The
**ntohl** function converts a **u_long** from TCP/IP network order to host byte order (which is little-endian on Intel processors).

## Parameters

### `netlong` [in]

A 32-bit number in TCP/IP network byte order.

## Return value

The
**ntohl** function returns the value supplied in the *netlong* parameter with the byte order reversed. If *netlong* is already in host byte order, then this function will reverse it. It is up to the application to determine if the byte order must be reversed.

## Remarks

The
**ntohl** function takes a 32-bit number in TCP/IP network byte order (the AF_INET or AF_INET6 address family) and returns a 32-bit number in host byte order.

The
**ntohl** function can be used to convert an IPv4 address in network byte order to the IPv4 address in host byte order. This function does not do any checking to determine if the *netlong* parameter is a valid IPv4 address.

The **ntohl** function does not require that the Winsock DLL has previously been loaded with a successful
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

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)
# htonll function

## Description

The
**htonll** inline function converts an **unsigned __int64** from host to TCP/IP network byte order (which is big-endian).

## Parameters

### `Value`

A 64-bit unsigned number in host byte order.

## Return value

The
**htonll** function returns the value in TCP/IP's network byte order.

## Remarks

The
**htonll** inline function takes a 64-bit number in host byte order and returns a 64-bit number in the network byte order used in TCP/IP networks (the AF_INET or AF_INET6 address family).

The
**htonll** inline function can be used to convert an IPv4 address in host byte order to the IPv4 address in network byte order. This function does not do any checking to determine if the *value* parameter is a valid IPv4 address.

The **htonll** inline function does not require that the Winsock DLL has previously been loaded with a successful
call to the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

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

[htons](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-htons)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-ntohd)

[ntohf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-ntohf)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohll](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-ntohll)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)
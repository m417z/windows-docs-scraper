# TIMEVAL structure

## Description

The
**timeval** structure is used to specify a time interval. It is associated with the Berkeley Software Distribution (BSD) *Time.h* header file.

## Members

### `tv_sec`

Time interval, in seconds.

### `tv_usec`

Time interval, in microseconds. This value is used in combination with the **tv_sec** member to represent time interval values that are not a multiple of seconds.

## Remarks

The **timeval** structure is used in Windows Sockets by the [select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function to specify the maximum time the function can take to complete. The time interval is a combination of the values in **tv_sec** and **tv_usec** members.

Several functions are added on Windows Vista and later that use the **timeval** structure. These functions include [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), [SetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setaddrinfoexa), [WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist), and [WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea).

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[SetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setaddrinfoexa)

[WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist)

[WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea)

[linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)
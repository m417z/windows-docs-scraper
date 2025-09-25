# setipv4sourcefilter function

## Description

The
**setipv4sourcefilter** inline function sets the multicast filter state for an IPv4 socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a multicast socket.

### `Interface` [in]

The local IPv4 address of the interface or the interface index on which the multicast group should be joined or dropped.

This value is in network byte order. If this member specifies an IPv4 address of 0.0.0.0, the default IPv4 multicast interface is used.

Any IP address in the 0.x.x.x block (first octet of 0) except IPv4 address 0.0.0.0 is treated as an interface index. An interface index is a 24-bit number, and the 0.0.0.0/8 IPv4 address block is not used (this range is reserved).

To use an interface index of 1 would be the same as an IP address of 0.0.0.1.

### `Group` [in]

The IPv4 address of the multicast group.

### `FilterMode` [in]

The multicast filter mode for multicast group address.

### `SourceCount` [in]

The number of source addresses in the buffer pointed to by the *SourceList* parameter.

### `SourceList` [in]

A pointer to a buffer with the IP addresses to associate with the multicast filter.

## Return value

On success, **setipv4sourcefilter** returns NO_ERROR (0). Any nonzero return value indicates failure and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**setipv4sourcefilter** inline function is used to set the multicast filter state for an IPv4 socket.

This function is part of socket interface extensions for multicast source filters defined in RFC 3678. An app can use these functions to retrieve and set the multicast source address filters associated with a socket.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type)

[getipv4sourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getipv4sourcefilter)

[getsourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getsourcefilter)

[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[setsourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setsourcefilter)
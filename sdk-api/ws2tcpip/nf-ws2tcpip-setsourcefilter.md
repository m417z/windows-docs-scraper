# setsourcefilter function

## Description

The
**setsourcefilter** inline function sets the multicast filter state for an IPv4 or IPv6 socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a multicast socket.

### `Interface` [in]

The interface index of the multicast interface.

### `Group` [in]

A pointer to the socket address of the multicast group.

### `GroupLength` [in]

The length, in bytes, of the socket address pointed to by the *Group* parameter.

### `FilterMode` [in]

The multicast filter mode for the multicast group address.

### `SourceCount` [in]

The number of source addresses in the buffer pointed to by the *SourceList* parameter.

### `SourceList` [in]

A pointer to a buffer with the IP addresses to associate with the multicast filter.

## Return value

On success, **setsourcefilter** returns NO_ERROR (0). Any nonzero return value indicates failure and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**setsourcefilter** inline function is used to set the multicast filter state for an IPv4 or IPv6 socket.

This function is part of socket interface extensions for multicast source filters defined in RFC 3678. An app can use these functions to retrieve and set the multicast source address filters associated with a socket.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type)

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))

[getipv4sourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getipv4sourcefilter)

[getsourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getsourcefilter)

[setipv4sourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setipv4sourcefilter)